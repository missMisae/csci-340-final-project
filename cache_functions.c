#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cache_functions.h"

#define VERBOSE

long block_size() {
  
}

long cache_size() {

}

double speed_array_accesses(int num_polls) {
  const long mem_blocks = 666 * pow(6, 6);
  int i;
  long j;
  clock_t time_anchor;
  double access_time_total, access_time, poll_time;
  char * slots = malloc(sizeof(char)*mem_blocks);
  char trash_variable;

#ifdef VERBOSE
  printf("Iterating through 666 * 6^6 values, %d times( ͡° ͜ʖ ͡°)\n", num_polls);
#endif
  for (i = 0; i < num_polls; i++) {
    time_anchor = clock();
    for (j = 0; j < mem_blocks; j++) {
        trash_variable = slots[j];
    }
    poll_time = (double)(clock() - time_anchor);
    access_time_total += poll_time / mem_blocks;
  }
  access_time = access_time_total / num_polls;
  return access_time;
}

long speed_main_memory() {
  
}

long speed_cache_memory() {
  
}

int main() {
  double access_speed;
  access_speed = speed_array_accesses(666);
  printf("It takes %f to access all the slots in memory.\n", access_speed);
}
