CC = gcc
CFLAGS = -Wall -Wextra -pthread

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

TARGET = program

ifeq ($(OS),Windows_NT)
	RM = del /Q
	CLEAR = cls
else
	RM = rm -f
	CLEAR = clear
endif

all: clean clear $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c defines.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)

clear:
	$(CLEAR)
