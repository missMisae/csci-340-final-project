#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cache_functions.h"

#define VERBOSE
#define NUM_POLLS 666
#define NUM_ACCESSES 31072896

long block_size() {
}

long cache_size() {
}

double speed_array_accesses_sequenced() {
  int i;
  long j;
  clock_t time_anchor;
  double access_time_total, access_time, poll_time;
  char * slots = malloc(sizeof(char)*RAND_MAX);
  char trash_variable;

#ifdef VERBOSE
  printf("Iterating through 666 * 6^6 values, %d times( ͡° ͜ʖ ͡°)\n", NUM_POLLS);
#endif
  for (i = 0; i < NUM_POLLS; i++) {
    time_anchor = clock();
    for (j = 0; j < NUM_ACCESSES; j++) {
        trash_variable = slots[j];
    }
    poll_time = (double)(clock() - time_anchor);
    access_time_total += poll_time / NUM_ACCESSES;
  }
  access_time = access_time_total / NUM_POLLS;
  return access_time;
}

double speed_array_accesses_random() {
  long j;
  int i, r;
  clock_t time_anchor;
  double access_time_total, access_time, poll_time;
  char * slots = malloc(sizeof(char)*RAND_MAX);
  char trash_variable;

#ifdef VERBOSE
  printf("Iterating through 666 * 6^6 values, %d times( ͡° ͜ʖ ͡°)\n", NUM_POLLS);
#endif
  for (i = 0; i < NUM_POLLS; i++) {
    time_anchor = clock();
    for (j = 0; j < NUM_ACCESSES; j++) {
      r = rand() % NUM_ACCESSES;
      trash_variable = slots[r];
    }
    poll_time = (double)(clock() - time_anchor);
    access_time_total += poll_time / NUM_ACCESSES;
  }
  access_time = access_time_total / NUM_POLLS;
  return access_time;
}

long speed_main_memory() {
}

long speed_cache_memory() {
}

int main() {
  double access_speed_sequenced, access_speed_random;
  access_speed_sequenced = speed_array_accesses_sequenced();
  access_speed_random = speed_array_accesses_random();
  printf("It takes %f to access all the slots in memory (seq).\n", access_speed_sequenced);
  printf("It takes %f to access all the slots in memory (rand).\n", access_speed_random);
}
