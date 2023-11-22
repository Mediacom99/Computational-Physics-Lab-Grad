#define MAIN_PROGRAM

#define TEST_C

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "global.h"
#include "action.h"
#include "random.h"
#include "start.h" 


/*
 * TO DO: add vector utility function in a new module
 */
void printXX(void)
{
	int i;
	for(i = 0; i < N - 1; i++)
	{
		printf("%f ",xx[i]);
    if(i%3 == 0){
      printf("\n");
    }
	}
  printf("\n");
	return;
}



int main(int argc, char* argv[])
{
  /*Measuring time*/
  double t1;
  double t2;
  int i;

  t1 = (double)clock();
  if (argc == 2) {
    
    /* Initialize random generator */ 
    rlxd_init(2, atoi(argv[1]));
    /*Get random generator values */
    ranlxd(&xx[0], N);
  }
  else if (argc > 2) {
    printf("Too many arguments, exiting...\n");
    return(1);
  }
  else {
    gauss_dble(&xx[0], N);
  }


  printf("Printing xx[N]: \n");
	printXX();
	printf("----------------------------------\n");
	printf("Action : %.9e\n", action_dbl()); 

  for (i = 0; i < N - 1; i+=3) {
    printf("Delta_Action : %.9e\n", delta_action_dbl(xx[i], i + 1));
  }
  
  t2 = (double)clock();
  printf("TIME ELAPSED: %.9e s \n", t2/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC);
	return(0);

}
