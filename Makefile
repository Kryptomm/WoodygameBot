CC = gcc
CFLAGS = -Wall -Wextra -pthread

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c defines.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
