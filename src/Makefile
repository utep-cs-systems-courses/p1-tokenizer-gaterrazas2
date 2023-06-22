# Makefile for compiling and running main.c

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Name of the executable
TARGET = lab1

# Source files
SRCS = main.c

# Object files to be generated
OBJS = $(SRCS:.c=.o)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile C source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the generated files
clean:
	rm -f $(OBJS) $(TARGET)
