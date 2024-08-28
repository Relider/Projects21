package main

import (
	"net/http"
	"os"

	"ozon/graph"
	"ozon/internal/config"
	"ozon/internal/consts"
	"ozon/internal/db"
	"ozon/internal/gateway"
	in_memory "ozon/internal/gateway/in-memory"
	"ozon/internal/gateway/postgres"
	"ozon/internal/server/graphql"
	"ozon/internal/service"

	"github.com/99designs/gqlgen/graphql/handler"
	"github.com/99designs/gqlgen/graphql/playground"
	_ "github.com/lib/pq"

	env "ozon/pkg/env"
	lg "ozon/pkg/logger"
	er "ozon/pkg/responce_errors"
)

func main() {
	logger := lg.InitLogger()
	logger.Info.Print("Executing InitLogger.")

	envFile := env.GetEnvFile()

	logger.Info.Print("Executing InitConfig.")
	logger.Info.Printf("Reading %s \n", envFile)
	err := config.InitConfig(envFile)
	er.ErrTest(err, logger)

	logger.Info.Print("Connecting to Postgres.")

	options := db.PostgresOptions{
		Name:     os.Getenv("POSTGRES_DBNAME"),
		Port:     os.Getenv("POSTGRES_PORT"),
		Host:     os.Getenv("POSTGRES_HOST"),
		User:     os.Getenv("POSTGRES_USER"),
		Password: os.Getenv("POSTGRES_PASSWORD"),
	}

	logger.Info.Print(options)
	pDb, err := db.CreateDB(options)

	er.ErrTest(err, logger)

	var gateways *gateway.Gateways

	logger.Info.Print("Creating Gateways.")
	logger.Info.Print("USE_IN_MEMORY = ", os.Getenv("USE_IN_MEMORY"))

	if os.Getenv("USE_IN_MEMORY") == "true" {
		posts := in_memory.CreatePostsInMemory(consts.PostsPullSize)
		comments := in_memory.CreateCommentsInMemory(consts.CommentsPullSize)
		gateways = gateway.CreateGateways(posts, comments)
	} else {
		posts := postgres.CreatePostsPostgres(pDb)
		comments := postgres.CreateCommentsPostgres(pDb)
		gateways = gateway.CreateGateways(posts, comments)
	}

	logger.Info.Print("Creating Services.")
	services := service.CreateServices(gateways, logger)

	logger.Info.Print("Creating graphql server.")
	port := os.Getenv("PORT")
	srv := handler.NewDefaultServer(graph.CreateExecutableSchema(graph.Config{Resolvers: &graphql.Resolver{
		PostsService:      services.Posts,
		CommentsService:   services.Comments,
		CommentsObservers: graphql.CreateCommentsObserver(),
	}}))

	http.Handle("/", playground.Handler("GraphQL playground", "/query"))
	http.Handle("/query", srv)

	logger.Info.Printf("Connect to http://localhost:%s/ for GraphQL playground", port)
	logger.Err.Fatal(http.ListenAndServe(":"+port, nil))

}
