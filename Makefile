CC = gcc
CFLAGS = -Wall -Wextra -pthread

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

TARGET = program

ifeq ($(OS),Windows_NT)
	RM = del /Q
else
	RM = rm -f
endif

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c defines.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
