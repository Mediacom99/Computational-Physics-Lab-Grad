/* Copyright 2023 Edoardo Bertoli */

#define MAIN_PROGRAM

#include "action.h"
#include "global.h"
#include "start.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * TO DO: add vector utility function in a new module
 *        add process time calculation in a util module
 */

int main(int argc, char *argv[]) {
  /*Measuring time*/
  double t1;
  double t2;
  int i;
  FILE *file;
  unsigned int seed;
  int sweeps;

  if (argc < 3) {
    printf("Wrong arguments: ./test <start_mode> <#sweeps>\nExiting...\n");
    exit(1);
  }
  t1 = (double)clock();
  file = fopen("./plot/data", "w");
  seed = 15031999;

  /* Initialize random generator */
  start_ranlux(1, seed);

  /*Initialize state: w = warm, c = cold*/
  init_state(*argv[1], xx);

  sweeps = atoi(argv[2]);

  for (i = 0; i < sweeps; i++) {
    fprintf(file, "%f,%d\n", action_dbl(xx), i);
    sweep(xx);
  }

  fclose(file);
  t2 = (double)clock();
  printf("TIME ELAPSED: %.9e s \n", t2 / CLOCKS_PER_SEC - t1 / CLOCKS_PER_SEC);

  return 0;
}
