
CC=gcc
LC = lcov

CFLAGS = -c -Wall -Werror -Wextra  -std=c11
AFLAGS = ar rc
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LCOVFLAGS = -c -d . -o

SOURCES = $(wildcard *.c)
LIBSOURCES = $(wildcard s21*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
LIBOBJECTS = $(patsubst %.c, %.o, $(LIBSOURCES))
EXECUTABLE = test
PROJECT_NAME = s21_math

ifeq ($(shell uname -s),Linux)# Linux
OPEN_CMD = xdg-open # команда для открытия отчета
OFLAGS =  -lcheck -lsubunit  -lrt -lpthread -lgcov -o
# добавлятся дополнительные библиотеки
endif
ifeq ($(shell uname -s),Darwin) # MacOS
OPEN_CMD = open
OFLAGS = -lcheck -lpthread -lgcov -o
endif


all:  s21_math.a $(SOURCES) test check gcov_report


.c.o:
	$(CC) $(CFLAGS) $< $(GCOVFLAGS) -o $@


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(OFLAGS) $@ -lm
	./$(EXECUTABLE)


s21_math.a:
	$(CC) $(CFLAGS) $(LIBSOURCES) -lm
	$(AFLAGS) s21_math.a $(LIBOBJECTS)
	rm -rf *.o


gcov_report:
	$(LC) $(LCOVFLAGS) report.info
	genhtml report.info
	$(OPEN_CMD) ./index.html


check:
	# leaks -atExit -- ./$(EXECUTABLE) | grep LEAK:
ifeq ("","$(wilcard ./.clang-format)") # если файла нет, копируем его.
	-cp -f ../materials/linters/.clang-format ./.clang-format
endif
	-clang-format -i $(SOURCES)


clean:
	-rm -rf *.o
	-rm -rf *.gc*
	-rm -rf *.a
	-rm -rf *.png *.info *.html *.css *.info
	-rm -rf src usr
	-rm -rf test
	

rebuild: clean all
