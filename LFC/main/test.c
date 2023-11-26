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


  t1 = (double)clock();

  /* Initialize state either with std gauss pdf or given a seed for the generator*/
  if (argc == 2) {
    
    /* Initialize random generator */ 
    rlxd_init(1, atoi(argv[1]));
    /*Get random generator values */
    ranlxd(xx, N);
  }
  else if (argc > 2) {
    printf("Too many arguments, exiting...\n");
    return(1);
  }
  else {
    gauss_dble(xx, N);
  }
  
  /* Execute a sweep, calculate action, save action value and markov time (step)
   * loop this and then plot (markov time, S(markov time))*/
  
  /*
  printf("Printing initial state: \n");
	print_state();
	printf("----------------------------------\n");
	
  printf("Action : %.9e\n", action_dbl());
  printf("Delta_Action: %.9e\n", delta_action_dbl(0.1,0));
  
  for (i = 0; i < N - 1; i+=3) {
    printf("Delta_Action : %.9e\n", delta_action_dbl(xx[i], i + 1));
  }  */ 
  
  file = fopen("./plot/data","w");
  for(i=0; i < 10000; i++)
  {
    fprintf(file,"%e,%d\n", action_dbl(), i);
    sweep();
  }
  fclose(file);


  t2 = (double)clock();
  printf("TIME ELAPSED: %.9e s \n", t2/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC);
	return(0);

}
