#define MAIN_PROGRAM


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "global.h"
#include "action.h"
#include "random.h"
#include "start.h" 


/*
 * TO DO: add vector utility function in a new module
 *        add process time calculation in a util module
 */ 




int main(int argc, char* argv[])
{
  /*Measuring time*/
  double t1;
  double t2;
  int i; 
  FILE* file;
  unsigned int seed;
   
  t1 = (double)clock();
   
  seed = 15031999;
  /* Initialize random generator */ 
  start_ranlux(1, seed);
  
  /*
  WARM START
  ranlxd(xx, N);
  */

  /*COLD START*/
  for(i = 0; i < N; i++)
  {
    xx[i] = 0.0;
  } 
   
  file = fopen("./plot/data","w");
  for(i=0; i < 1000; i++)
  {
    fprintf(file,"%f,%d\n", action_dbl(xx), i);
    sweep(xx);
  }
  fclose(file); 
 
  t2 = (double)clock();
  printf("TIME ELAPSED: %.9e s \n", t2/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC);
  return(0);

}
