#
#
#
#

COMPILER = gcc
FLAGS    = -std=c99 -Wall -ansi
DEBUG    = -O3 -DNDEBUG
CC       = $(COMPILER) $(FLAGS) $(DEBUG)
CO       = $(CC) -c

banana.o: banana_random_engine.c
	$(CO) banana_random_engine.c -o banana.o

banana_unit_test: banana_random_engine.c
	$(CC) banana_random_engine.c -DBANANA_RANDOM_ENGINE_UNIT_TEST -o banana_unit_test

clean:
	rm -f *.o
	rm -rf banana_unit_test
	rm -rf *.dSYM

