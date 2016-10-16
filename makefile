GCC = gcc -g

all: playlist.o A.o
	$(GCC) playlist.o A.o -o playlisttest

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

A.o: A.c playlist.h
	$(GCC) -c A.c

clean:
	rm *.o
	rm *~

run: all
	./playlisttest
