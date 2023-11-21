#define MAIN_PROGRAM

#define TEST_C

#include <stdlib.h>
#include <stdio.h>
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
		printf("%f\n",xx[i]);
	}
	return;
}



int main(int argc, char* argv[])
{

  
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



	printXX();
	printf("\n");
	printf("Action : %.20f\n", action_dbl());
	

	return(0);

}
