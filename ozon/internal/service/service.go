package service

import (
	"ozon/internal/gateway"
	"ozon/internal/models"
	"ozon/pkg/logger"
)

type Services struct {
	Posts
	Comments
}

func CreateServices(gateways *gateway.Gateways, logger *logger.Logger) *Services {
	return &Services{
		Posts:    CreatePostsService(gateways.Posts, logger),
		Comments: CreateCommentsService(gateways.Comments, logger, gateways.Posts),
	}
}

type Posts interface {
	CreatePost(post models.Post) (models.Post, error)
	GetPostById(id int) (models.Post, error)
	GetAllPosts(page, pageSize *int) ([]models.Post, error)
}

type Comments interface {
	CreateComment(comment models.Comment) (models.Comment, error)
	GetCommentsByPost(postId int, page *int, pageSize *int) ([]*models.Comment, error)
	GetRepliesOfComment(commentId int) ([]*models.Comment, error)
}
