# Simple Makefile for a C project with PostgreSQL

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra 
PGSQL_FLAGS = -Ic:/PostgreSQL/16/include
PGSQL_LIBS = -Lc:/PostgreSQL/16/lib -lpq 

# Source files
SOURCES = src/Logic/*.c src/io/*.c src/Data/*.c src/*.c Include/DataStructure/List.c

# Executable
EXECUTABLE = bin\Debug\SI-PRJ.exe

# Target to compile the project
all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(PGSQL_FLAGS) $^ -o $@ $(PGSQL_LIBS)

# Phony target to force a rebuild
build: clean all
run:
	$(EXECUTABLE)

# Clean up object files and executable
clean:
	del  $(EXECUTABLE)
