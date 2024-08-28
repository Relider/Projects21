package responce_errors

import (
	lg "ozon/pkg/logger"
)

type ResponseError struct {
	Message string
	Type    string
}

func (r ResponseError) Error() string {
	return r.Message
}

func (r ResponseError) Extensions() map[string]interface{} {
	return map[string]interface{}{
		"message": r.Message,
		"type":    r.Type,
	}
}

func ErrTest(err error, logger *lg.Logger) {
	if err != nil {
		logger.Err.Fatalf(err.Error())
	}
}
