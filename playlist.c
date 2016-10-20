#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playlist.h"

song_node *library[27];

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
  printf("Song not found.\n");
  return 0;
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

void print_artist( char *artist) {
  int k = 0;
  while (k<28) {
    song_node *curr = library[k];
    while (curr) {
      if (curr->artist == artist) {
	print_node(curr);	
      }
      curr = curr->next;
    }
    k++;
  }
}

void print_library() {
  int k = 0;
  int empty = 1;
  while (k<28) {
    if (len(library[k]) > 0) {
      empty = 0;
    }
    print_list(library[k]);
    k++;
  }
  if (empty) {
    printf("Your library is empty.\n");
  }
}

void delete_song( char *name ) {
  int k = 0;
  while (k<28) {
    library[k] = remove_song(library[k], name);
    k++;
  }
}

void clear() {
  int k = 0;
  while (k<28) {
    library[k] = free_list(library[k]);
    k++;
  }
}

void shuffle(int k) {
  srand(time(NULL));
  while (k) {
    int r = rand() % 27;
    if (library[r]) {
      printf("%d ", r);
      print_node(random_song(library[r]));
      k--;
    }
  }
  printf("\n");
}
    
