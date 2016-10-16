#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ll.h"

void print_node( struct song_node *n) {
  if (n) {
    printf("%s / %s\n", n->name, n->artist);
  }
}

void print_list( struct song_node *l ) {
  if (l) {
    print_node(l);
    print_list(l->next);
  }
}

struct song_node * insert_front( struct song_node *l, char *name, char *artist ) {
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  new->name = name;
  new->artist = artist;
  new->next = l;
  return new;
}

struct song_node * insert( struct song_node *l, char *name, char *artist ) {
  if (l==0) {
    l = insert_front(l, name, artist);
    return l;
  }
  if ( strcmp(l->name, name) > 0 ) {
    l = insert_front (l, name, artist);
    return l;
  }
  struct song_node *f = l;
  while ( f && strcmp(f->name, name) <= 0 ) {
    f = f->next;
  }
  struct song_node *g = l;
  while (g->next != f) {
    g = g->next;
  }
  g->next = insert_front(f, name, artist);
  return l;
}

struct song_node * search_name ( struct song_node *l, char *name ) {
  struct song_node *f = l;
  while(f) {
    if (f->name == name) {
      return f;
    }
    f = f->next;
  }
  printf("Song not found.\n");
  return 0;
}

struct song_node * search_artist( struct song_node *l, char *artist ) {
  struct song_node *f = l;
  while(f) {
    if (f->artist == artist) {
      return f;
    }
    f = f->next;
  }
  printf("Artist not found.\n");
  return 0;
}

int len( struct song_node *l ) {
  int ret = 0;
  while (l) {
    l = l->next;
    ret++;
  }
  return ret;
}

struct song_node * random_song ( struct song_node *l ) {
  srand(time(NULL));
  int r = rand() % len(l);
  struct song_node *f = l;
  while (r) {
    f = f->next;
    r--;
  }
  return f;
}

struct song_node * remove_song( struct song_node *l, char *name ) {
  struct song_node *g = search_name(l, name);
  if (g==l) {
    return l->next;
  }
  if (g) {
    while (l->next != g) {
      l = l->next;
    }
    l->next = g->next;
    free(g);
    return l;
  }
  return 0;
}

struct song_node * free_list( struct song_node *l ) {
  struct song_node *f = l;
  while(l) {
    l = l->next;
    printf("freeing songnode: %s / %s\n", f->name, f->artist);
    free(f);
    f=l;
  }
  return l;
}


  