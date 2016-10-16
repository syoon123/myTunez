#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playlist.h"

song_node *library[27];

void add_song(char *name, char *artist ) {
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

void print_artist(char *artist) {
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
  while (k<28) {
    print_list(library[k]);
    k++;
  }
}

void add(song_node *lib[], char *name, char *artist) {
  char first = name[0];
  if (first>=48 && first<=57) {
    lib[0] = insert(lib[0], name, artist);
  }
  else {
    int k = first - 64;
    lib[k] = insert(lib[k], name, artist);
  }
}
  
void shuffle() {
  song_node *library_copy[27];
  int k = 0;
  while (k<28) {
    while (library[k]) {
      add(library_copy, library[k]->name, library[k]->artist);
      library[k] = library[k]->next;
    }
    k++;
  }
  srand(time(NULL));
  int i = 27;
  while(i) {
    int j = rand() % i;
    song_node *temp = library_copy[j];
    library_copy[j] = library_copy[i];
    library_copy[i] = temp;
    i--;
  }
  while(i<28) {
    while(library[i]) {
      song_node *randsong = random_song(library[i]);
      print_node(randsong);
      library[i] = remove_song(library[i], randsong->name);
    }
    i++;
  }
}
