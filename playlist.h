#ifndef _PLAYLIST_H
#define _PLAYLIST_H
#include "ll.h"

void add_song(char *name, char *artist );

song_node * search_Name( char *name );

song_node * search_Artist( char *artist );

void print_letter( char letter );

void print_artist( char *artist );

void print_library();

void shuffle(int k);

void delete_song( char *name );

void clear();
#endif
