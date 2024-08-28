
local.run:
	docker compose --env-file ./docker.env up -d postgres
	docker compose --env-file ./docker.env up -d migrate
	go run ./cmd/main.go

graph.gen:
	go run github.com/99designs/gqlgen generate --verbose

docker.rebuild:
	docker compose --env-file ./docker.env up -d --build app

docker.run:
	docker compose --env-file ./docker.env up -d

docker.down:
	docker compose down

migrate.up:
	migrate -path ./migrations -database "postgres://postgres:1@localhost:5432/postgres?sslmode=disable" up

migrate.down:
	migrate -path ./migrations -database "postgres://postgres:1@localhost:5432/postgres?sslmode=disable" down

tests.run:
	go test ./...

tests.cover:
	go test -cover ./...