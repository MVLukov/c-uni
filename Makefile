CC = gcc
CPP = g++
CFLAGS = -pedantic -Wall -Wextra -Werror -lm -lstdc++
TARGET = main

c: 
		$(CC) ${arg1} $(CFLAGS) -o ${TARGET} 

cpp: 
		$(CC) ${arg1} $(CFLAGS) -o ${TARGET}

run:
		./${TARGET}

clear:
		rm ${TARGET}