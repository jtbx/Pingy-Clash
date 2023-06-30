CC = gcc
CFLAGS = -std=c11 -O
OBJS = main.o battle.o utils.o

all: pingyclash

pingyclash: ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}

main.o: main.c utils.h
	${CC} ${CFLAGS} -o $@ -c $<

battle.o: battle.c utils.h
	${CC} ${CFLAGS} -o $@ -c $<

utils.o: utils.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	rm -f pingyclash ${OBJS}

.PHONY: all clean
