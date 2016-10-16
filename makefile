GCC = gcc -g

all: ll.o playlist.o A.o
	$(GCC) playlist.o A.o ll.o -o playlisttest

ll.o: ll.c ll.h
	$(GCC) -c ll.c

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

A.o: A.c playlist.h
	$(GCC) -c A.c

clean:
	rm *.o
	rm *~

run: all
	./playlisttest
