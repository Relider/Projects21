package service

import (
	"database/sql"
	"errors"
	"ozon/internal/consts"
	"ozon/internal/gateway"
	"ozon/internal/models"
	"ozon/pkg/logger"
	"ozon/pkg/pagination"
	re "ozon/pkg/responce_errors"
)

type PostsService struct {
	repo   gateway.Posts
	logger *logger.Logger
}

func CreatePostsService(repo gateway.Posts, logger *logger.Logger) *PostsService {
	return &PostsService{repo: repo, logger: logger}
}

func (p PostsService) CreatePost(post models.Post) (models.Post, error) {

	if len(post.Author) == 0 {
		p.logger.Err.Println(consts.EmptyAuthorError)
		return models.Post{}, re.ResponseError{
			Message: consts.EmptyAuthorError,
			Type:    consts.BadRequestType,
		}
	}

	if len(post.Content) >= consts.MaxContentLength {
		p.logger.Err.Println(consts.TooLongContentError, len(post.Content))
		return models.Post{}, re.ResponseError{
			Message: consts.TooLongContentError,
			Type:    consts.BadRequestType,
		}
	}

	newPost, err := p.repo.CreatePost(post)
	if err != nil {
		p.logger.Err.Println(consts.CreatingPostError, err.Error())
		return models.Post{}, re.ResponseError{
			Message: consts.CreatingPostError,
			Type:    consts.InternalErrorType,
		}
	}

	return newPost, nil

}

func (p PostsService) GetPostById(postId int) (models.Post, error) {

	if postId <= 0 {
		p.logger.Err.Println(consts.WrongIdError, postId)
		return models.Post{}, re.ResponseError{
			Message: consts.WrongIdError,
			Type:    consts.BadRequestType,
		}
	}

	post, err := p.repo.GetPostById(postId)
	if err != nil {

		p.logger.Err.Println(consts.GettingPostError, err.Error())
		if errors.Is(err, sql.ErrNoRows) {
			return models.Post{}, re.ResponseError{
				Message: consts.PostNotFountError,
				Type:    consts.NotFoundType,
			}
		}
		return models.Post{}, re.ResponseError{
			Message: consts.GettingPostError,
			Type:    consts.InternalErrorType,
		}
	}

	return post, nil
}

func (p PostsService) GetAllPosts(page, pageSize *int) ([]models.Post, error) {

	if page != nil && *page < 0 {
		p.logger.Err.Println(consts.WrongPageError, *page)
		return nil, re.ResponseError{
			Message: consts.WrongPageError,
			Type:    consts.BadRequestType,
		}
	}

	if pageSize != nil && *pageSize < 0 {
		p.logger.Err.Println(consts.WrongPageSizeError, *pageSize)
		return nil, re.ResponseError{
			Message: consts.WrongPageSizeError,
			Type:    consts.BadRequestType,
		}
	}

	offset, limit := pagination.GetOffsetAndLimit(page, pageSize)

	posts, err := p.repo.GetAllPosts(limit, offset)
	if err != nil {
		p.logger.Err.Println(consts.GettingPostError, err.Error())
		return nil, re.ResponseError{
			Message: consts.GettingPostError,
			Type:    consts.InternalErrorType,
		}
	}

	return posts, nil
}
