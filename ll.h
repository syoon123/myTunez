typedef struct song_node {
  char *name;
  char *artist;
  struct song_node *next;
} song_node;

void print_node( struct song_node *n);

int len( struct song_node *l );

struct song_node * insert_front( struct song_node *l, char *name, char *artist); 

struct song_node * insert( struct song_node *l, char *name, char *artist ); 

void print_list( struct song_node *l ); 

struct song_node * search_name ( struct song_node *l, char *name ); 

struct song_node * search_artist( struct song_node *l, char *artist ); 

struct song_node * random_song ( struct song_node *l ); 

struct song_node * remove_song( struct song_node *l, char *name );

struct song_node * free_list( struct song_node *l ); 
