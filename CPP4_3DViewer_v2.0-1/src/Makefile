CC=gcc
PKGCONFIG = $(shell which pkg-config) 
CFLAGS=-Wall -Wextra -Werror $(shell $(PKGCONFIG) --cflags gtk4)
SOURCES= Ccode/* Cppcode/3d_viewer/*
TEST_SOURCES=tests/*.c Ccode/*.c
UNAME_S=$(shell uname -s)
GCOV_FLAGS=

ifeq ($(UNAME_S),Linux)
LDFLAGS= -lm -lcheck -lpthread -lsubunit
endif
ifeq ($(UNAME_S),Darwin)
LDFLAGS= -lm -lcheck -lpthread
endif

all: install

test:
	$(CC) $(CFLAGS) $(TEST_SOURCES) $(LDFLAGS) $(GCOV_FLAGS) -o test

gcov_report: GCOV_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test
	lcov -c -d . -o report.info
	genhtml -o "html_report" report.info
	rm -rf test  *.o *.gch *.gcno *.gcda
	open html_report/index.html

install:
	rm -rf s21_3d_viewer
	mkdir s21_3d_viewer
	qmake Cppcode/3d_viewer/3d_viewer.pro -o s21_3d_viewer
	cd s21_3d_viewer && make && cd ../
	chmod +x s21_3d_viewer/3d_viewer.app
	ln -s ${PWD}/s21_3d_viewer/3d_viewer.app ${HOME}/Desktop/s21_3dViewer

uninstall:
	rm -rf s21_3d_viewer
	rm ${HOME}/Desktop/s21_3dViewer

dvi:
	open info.html

dist: install
	tar -czf s21_3d_viewer.tar.gz --directory=Cppcode/3d_viewer .

style:
	clang-format -style=google -i Ccode/* matrix/* Cppcode/3d_viewer/*.h Cppcode/3d_viewer/*.cpp
	clang-format -style=google -n Ccode/* matrix/* Cppcode/3d_viewer/*.h Cppcode/3d_viewer/*.cpp

clean:
	rm -rf obj *.a test html_report report.info program *.o *.gch Cppcode/3d_viewer/*.gch *.gcno *.gcda s21_3d_viewer.tar.gz s21_3d_viewer

.PHONY: all test clean gcov_report
