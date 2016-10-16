typedef struct song_node {
  char *name;
  char *artist;
  struct song_node *next;
} song_node;

void print_node(  song_node *n);

int len(  song_node *l );

song_node * insert_front(  song_node *l, char *name, char *artist); 

song_node * insert(  song_node *l, char *name, char *artist ); 

void print_list(  song_node *l ); 

song_node * search_name (  song_node *l, char *name ); 

song_node * search_artist(  song_node *l, char *artist ); 

song_node * random_song (  song_node *l ); 

song_node * remove_song(  song_node *l, char *name );

song_node * free_list(  song_node *l ); 


