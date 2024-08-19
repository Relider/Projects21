CC=gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS=-Wall -Wextra -Werror $(shell $(PKGCONFIG) --cflags gtk4)
SOURCES=s21_Cppcode/* s21_Cppcode/*
TEST_SOURCES=tests/*.c s21_Ccode/*.c s21_Ccode/s21_3dviewer.h
UNAME_S=$(shell uname -s)
GCOV_FLAGS=

ifeq ($(UNAME_S),Linux)
LDFLAGS= pthread -lcheck_pic -pthread -lrt -lm -lcheck -lpthread -lsubunit
endif
ifeq ($(UNAME_S),Darwin)
LDFLAGS= -lm -lcheck -lpthread
endif

all: install
 
test:
	$(CC) $(CFLAGS) $(TEST_SOURCES) $(LDFLAGS) $(GCOV_FLAGS) -o test

gcov_report: GCOV_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test > /dev/null
	lcov --exclude *Cppcode.c -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

install:
	rm -rf s21_3d_viewer
	mkdir s21_3d_viewer
	qmake s21_Cppcode/s21_3d_viewer.pro -o s21_3d_viewer
	cd s21_3d_viewer && make && cd ../
	chmod +x s21_3d_viewer/s21_3d_viewer.app
	ln -s ${PWD}/s21_3d_viewer/s21_3d_viewer.app ${HOME}/Desktop/s21_3d_viewer

uninstall:
	rm -rf s21_3d_viewer
	rm ${HOME}/Desktop/s21_3d_viewer

dvi:src/s21_Cppcode/s21_3d_viewer/s21_3d_viewer.pro
	open info.html

dist: install
	tar -czf s21_3d_viewer.tar.gz --directory=s21_3d_viewer/ .

style:
	clang-format -style=google -i s21_Ccode/*.c s21_Ccode/*.h s21_Cppcode/*.h s21_Cppcode/*.cpp
	clang-format -style=google -n s21_Ccode/*.c s21_Ccode/*.h s21_Cppcode/*.h s21_Cppcode/*.cpp

clean:
	rm -rf obj *.a test html_report report.info program *.o *.gch s21_Cppcode/*.gch *.gcno *.gcda s21_3d_viewer.tar.gz s21_3d_viewer
	
lib:
	$(CC) -c $(SOURCES) $(LDFLAGS)
	ar -rc libcalc.a *.o
	ranlib libcalc.a

.PHONY: all test clean lib gcov_report