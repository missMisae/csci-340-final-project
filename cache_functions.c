#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cache_functions.h"

long block_size() {
  
}

long cache_size() {
  time_t before_access, post_access;
  double access_time;
  int * slot = malloc(sizeof(int));
  time(&before_access);
  *slot = 666;
  time(&post_access);
  access_time = difftime(before_access, post_access);
  printf("Took %f to access a single memory element.\n", access_time);
  return 0;
}

long speed_main_memory() {
  
}

long speed_cache_memory() {
  
}

int main() {
  long nose;
  nose = cache_size();
}
