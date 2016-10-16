#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

void add_song( char *name, char *artist ) {
  //A = 65, Z = 90
  char first = name[0];
  if (first<9) {
    library[0] = insert(library[0], name, artist);
  }
  else {
    int k = first - 64;
    library[k] = insert(library[k], name, artist);
  }
}
