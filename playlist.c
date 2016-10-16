#include <stdio.h>
#include <stdlib.h>
//#include "ll.h"
#include "playlist.h"

song_node *library[27]; //A-Z, #

void add_song( char *name, char *artist ) {
  //0 = 48, 9 = 57
  //A = 65, Z = 90
  char first = name[0];
  if (first>=48 && first<=57) {
    library[0] = insert(library[0], name, artist);
  }
  else {
    int k = first - 64;
    library[k] = insert(library[k], name, artist);
  }
}

song_node * search_Name( char *name ) {
  char first = name[0];
  if (first>=48 && first<=57) {
    return search_name( library[0], name );
  }
  else {
    int k = first - 64;
    return search_name( library[k], name );
  }
}

song_node * search_Artist( char *artist ) {
  int k = 0;
  while (k<28) {
    if (search_artist(library[k], artist)) {
      return search_artist(library[k], artist);
    }
    k++;
  }
  printf("Artist not found.\n");
  return 0;
}

void print_letter(char letter) {
  if (letter<9) {
    print_list(library[letter]);
  }
  else {
    int k = letter - 64;
    print_list(library[k]);
  }
}


  
