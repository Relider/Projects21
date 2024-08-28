// Code generated by MockGen. DO NOT EDIT.
// Source: internal/server/graphql/subscription.go

// Package mock_graphql is a generated GoMock package.
package mock_graphql

import (
	reflect "reflect"

	gomock "github.com/golang/mock/gomock"
	models "ozon/internal/models"
)

// MockObservers is a mock of Observers interface.
type MockObservers struct {
	ctrl     *gomock.Controller
	recorder *MockObserversMockRecorder
}

// MockObserversMockRecorder is the mock recorder for MockObservers.
type MockObserversMockRecorder struct {
	mock *MockObservers
}

// NewMockObservers creates a new mock instance.
func NewMockObservers(ctrl *gomock.Controller) *MockObservers {
	mock := &MockObservers{ctrl: ctrl}
	mock.recorder = &MockObserversMockRecorder{mock}
	return mock
}

// EXPECT returns an object that allows the caller to indicate expected use.
func (m *MockObservers) EXPECT() *MockObserversMockRecorder {
	return m.recorder
}

// CreateObserver mocks base method.
func (m *MockObservers) CreateObserver(postId int) (int, chan *models.Comment, error) {
	m.ctrl.T.Helper()
	ret := m.ctrl.Call(m, "CreateObserver", postId)
	ret0, _ := ret[0].(int)
	ret1, _ := ret[1].(chan *models.Comment)
	ret2, _ := ret[2].(error)
	return ret0, ret1, ret2
}

// CreateObserver indicates an expected call of CreateObserver.
func (mr *MockObserversMockRecorder) CreateObserver(postId interface{}) *gomock.Call {
	mr.mock.ctrl.T.Helper()
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "CreateObserver", reflect.TypeOf((*MockObservers)(nil).CreateObserver), postId)
}

// DeleteObserver mocks base method.
func (m *MockObservers) DeleteObserver(postId, chanId int) error {
	m.ctrl.T.Helper()
	ret := m.ctrl.Call(m, "DeleteObserver", postId, chanId)
	ret0, _ := ret[0].(error)
	return ret0
}

// DeleteObserver indicates an expected call of DeleteObserver.
func (mr *MockObserversMockRecorder) DeleteObserver(postId, chanId interface{}) *gomock.Call {
	mr.mock.ctrl.T.Helper()
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "DeleteObserver", reflect.TypeOf((*MockObservers)(nil).DeleteObserver), postId, chanId)
}

// NotifyObservers mocks base method.
func (m *MockObservers) NotifyObservers(postId int, comment models.Comment) error {
	m.ctrl.T.Helper()
	ret := m.ctrl.Call(m, "NotifyObservers", postId, comment)
	ret0, _ := ret[0].(error)
	return ret0
}

// NotifyObservers indicates an expected call of NotifyObservers.
func (mr *MockObserversMockRecorder) NotifyObservers(postId, comment interface{}) *gomock.Call {
	mr.mock.ctrl.T.Helper()
	return mr.mock.ctrl.RecordCallWithMethodType(mr.mock, "NotifyObservers", reflect.TypeOf((*MockObservers)(nil).NotifyObservers), postId, comment)
}
