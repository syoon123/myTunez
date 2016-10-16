#include <stdio.h>
#include <stdlib.h>

#include "playlist.h"

int main() {
  add_song("99 Problems", "Jay Z");
  add_song("3005","Childish Gambino");
  add_song("Good as Hell", "Lizzo");
  add_song("Girls", "The 1979");
  add_song("Paris", "The 1979");
  print_node(search_Name("Girls"));
  print_node(search_Name("She's a Lady"));
  print_node(search_Artist("Jay Z"));
  print_node(search_Artist("The 1979"));
  print_node(search_Artist("The Beatles"));
  return 0;
}
