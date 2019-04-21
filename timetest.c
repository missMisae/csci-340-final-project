#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  time_t before_access, post_access;
  double access_time;
  int * slot = malloc(sizeof(int)*666*pow(10, 10));
  time(&before_access);
  *slot = 666;
  time(&post_access);
  access_time = difftime(before_access, post_access);
  printf("Took %f to access a single memory element.\n", access_time);
}
