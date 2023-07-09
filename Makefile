CC = gcc
CFLAGS = -Wall -Wextra -I.

SRCS = main.c board.c tiles.c
OBJS = $(SRCS:.c=.o)
EXECUTABLE = program

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXECUTABLE)

main.o: main.c board.h tiles.h
	$(CC) $(CFLAGS) -c $< -o $@

board.o: board.c board.h defines.h tiles.h
	$(CC) $(CFLAGS) -c $< -o $@

tiles.o: tiles.c tiles.h defines.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)
