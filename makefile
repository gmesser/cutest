# makefile for the cutest test program 
##############################################################################

SHELL = /bin/sh
CFLAGS = -O3 -Wall
ALL_CFLAGS = -g -I. -std=c17 $(CFLAGS)

# Common prefix for installation directories.
prefix = /usr/local
datarootdir = $(prefix)/share
# Source directory.
srcdir = ./

TEST_SOURCES = test_cutest.c
TEST_EXECUTABLES = test_cutest

##############################################################################

all : clean test

build : clean $(TEST_EXECUTABLES)

targets :
	@echo Targets... && grep -A 1 '^[\.a-zA-Z1-9_ ]*:' ./makefile

variables :
	@echo Variables... && grep '^[a-zA-Z1-9_ ]*=' ./makefile

clean :
	-rm ./$(TEST_EXECUTABLES)

test : $(TEST_EXECUTABLES)
	./test_cutest

test_cutest : test_cutest.c cutest.h
	gcc $(ALL_CFLAGS) -o test_cutest test_cutest.c

install : cutest.h
	sudo cp -pv cutest.h $(prefix)/include

uninstall :
	-sudo rm -v $(prefix)/include/cutest.h

