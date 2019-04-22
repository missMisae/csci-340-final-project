#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "cache_functions.h"

#define VERBOSE
#define NUM_POLLS 100
#define NUM_ACCESSES 31072896
#define BFN 7000042

long block_size() {
}

long cache_size(double time_difference, int chunk_size) {
  char * bigass_array = malloc(sizeof(char)*BFN);
  char trash_variable;
  long num_bytes, i, j;
  clock_t time_anchor;
  double cached_access_time, recorded_access_time;

  time_anchor = clock();
  for (i = 0; i < chunk_size; i++) {
    trash_variable = bigass_array[i];
  }
  // We assume the first 100 accesses are cached
  cached_access_time = (double)(clock() - time_anchor) / chunk_size;
  num_bytes++;

  j = 0;
  while(true) {
    time_anchor = clock();
    for (j++; i < chunk_size && i + (100 * j) < BFN; i++) {
      trash_variable = bigass_array[i+(100*j)];
    }
    recorded_access_time = (double)(clock() - time_anchor) / chunk_size;
    if (recorded_access_time < cached_access_time + time_difference) {
      num_bytes++;
    } else if (i >= BFN) {
#ifdef VERBOSE
      printf("Did not successfully fill the cache / find access time difference.\n");
#endif
      break;
    } else {
#ifdef VERBOSE
      printf("Successfully filled the cache.\n");
#endif
      break;
    }
  }
  return num_bytes;
}

double speed_main_memory() {
  long j;
  int i, r;
  clock_t time_anchor;
  double access_time_total, access_time, poll_time;
  char * slots = malloc(sizeof(char)*NUM_ACCESSES);
  char trash_variable;

#ifdef VERBOSE
  printf("Iterating through 666 * 6^6 values, %d times ( ͡° ͜ʖ ͡°)\n", NUM_POLLS);
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

double speed_cache_memory() {
  int i;
  long j;
  clock_t time_anchor;
  double access_time_total, access_time, poll_time;
  char * slots = malloc(sizeof(char)*NUM_ACCESSES);
  char trash_variable;

#ifdef VERBOSE
  printf("Iterating through 666 * 6^6 values, %d times ( ͡° ͜ʖ ͡°)\n", NUM_POLLS);
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

int main() {
  double access_speed_cache, access_speed_main, magic_difference;
  long cache_size_estimate;
  access_speed_cache = speed_cache_memory();
  access_speed_main = speed_main_memory();
  printf("It takes %f to access cached memory.\n", access_speed_cache);
  printf("It takes %f to access main memory.\n", access_speed_main);
  magic_difference = access_speed_main - access_speed_cache;
  cache_size_estimate = cache_size(magic_difference, 100);
  printf("We're estimating the cache size to be %ld bytes.\n", cache_size_estimate);
}
