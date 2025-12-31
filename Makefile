main: main.c gameoflife.c gameoflife.h
	cc -Wall -Wextra -ggdb -lraylib -L/usr/include -o main main.c gameoflife.c
