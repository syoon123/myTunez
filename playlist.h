#include "ll.h"

song_node *library[27]; //A-Z, #

void add_song( char *name, char *artist );

struct song_node * search_Name( char *name );

struct song_node * search_Artist( char *artist );

void print_letter( char letter );

void print_artist( char *artist );

void print_library();

void shuffle();

void delete_song( char *name );

void clear();
