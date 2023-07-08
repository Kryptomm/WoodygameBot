CC = gcc
CFLAGS = -Wall -Wextra -I.

SRCS = main.c board.c
OBJS = $(SRCS:.c=.o)
EXECUTABLE = program

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c board.h defines.h
board.o: board.c board.h defines.h

clean:
	rm -f $(OBJS) $(EXECUTABLE)
