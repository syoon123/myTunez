#include <stdio.h>
#include <stdlib.h>

#include "playlist.h"

int main() { 
  add_song("99 Problems", "Jay Z");
  add_song("3005","Childish Gambino");
  add_song("Good as Hell", "Lizzo");
  add_song("Girls", "The 1979");
  add_song("Paris", "The 1979");

  print_letter('G');
  printf("\n");
  print_artist("The 1979");
  printf("\n");
  
  print_library();
  printf("\n");
  shuffle();
  return 0;
}
