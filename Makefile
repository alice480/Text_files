CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ../build/

all: cipher

cipher_quest1: cipher.c
	$(CC) $(CFLAGS) -c cipher.c

cipher_quest5: cipher.c
	$(CC) $(CFLAGS) -DQuest5 -c cipher.c

logger.o: logger.c
	$(CC) $(CFLAGS) -c logger.c

cipher: cipher_quest1
	$(CC) -o $(DIR)cipher cipher.o

logging_cipher: cipher_quest5 logger.o
	$(CC) -o $(DIR)logging_cipher cipher.o logger.o

clean:
	rm -rf *.o
	rm -rf ../build/cipher

rebuild: clean all
