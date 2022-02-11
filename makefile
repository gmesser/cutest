# makefile for the cutest unit test framework and test program

################
# Variables

SHELL = /bin/sh
CFLAGS = -O3 -Wall
ALL_CFLAGS = -g -I. -std=c17 $(CFLAGS)

# Common prefix for installation directory.
prefix = /usr/local

# Doing everything in the project directory.
srcdir = .
blddir = .

################
# Targets

all : clean test

build : clean test_cutest

clean :
	-rm $(blddir)/test_cutest

# Run the test program.
test : test_cutest
	$(blddir)/test_cutest

# Build the test program.
test_cutest : test_cutest.c cutest.h
	cc $(ALL_CFLAGS) -o $(blddir)/test_cutest $(srcdir)/test_cutest.c

# Install/uninstall at the standard loation.
install : cutest.h
	sudo cp -pv $(blddir)/cutest.h $(prefix)/include

uninstall :
	-sudo rm -v $(prefix)/include/cutest.h

# Show the targets in this makefile.
targets :
	@echo Targets... && grep -A 1 '^[\.a-zA-Z1-9_ ]*:' $(srcdir)/makefile

# Show the variables in this makefile.
variables :
	@echo Variables... && grep '^[a-zA-Z1-9_ ]*=' $(srcdir)/makefile
