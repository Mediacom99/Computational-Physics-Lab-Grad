 
#define ACTION_C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "global.h"
#include "action.h" /* The object file must include its own header file */
#include "random.h"

/*
 * Modulo dell'oscillatore armonico con tutte le funzioni
 * necessarie per calcolare numericamente quello che serve.
 *
 *
 */

/*UTILITY*/

void print_state(void)
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%e ",xx[i]);
    if(i%3 == 0){
      printf("\n");
    }
	}
  printf("\n");
	return;
}

/*
 * Devo calcolare: S e Delta S in due routine diverse, è importante
 * che la routine di DeltaS sia la più efficiente possibile.
 */

/*returns the action calculated at the current state of xx[N] as a double*/
double action_dbl(void)
{
  /*Check that xx sia stato inizializzato*/
	double sum;
	int i;
  sum = 0.0;
	for(i = 0; i < N; i++)
	{
		sum += M*0.5 * (xx[(i+1)%N] - xx[i])*(xx[(i+1)%N] - xx[i]) 
		       + (OM*OM)*M*0.5*(xx[(i)]*xx[(i)]);
	}
  return sum;

}

/*This function calculates DeltaS = S(..,x,..) - S(...,y,...)*/
/*
 *  Args:  dx = xx[j]_new - xx[j]_old
 *        j = which coordinate to change
 *  Returns: the difference of the action with when x_j -> x_j + dx 
 * */

/* NEEDS TO BE FIXED */
double delta_action_dbl(double dx, int j){ 
  
  double temp;
  /*Check that j is a valid position */
  if( j < 0 || j >= N){
    printf("Wrong argument 'j = %d' in function delta_action_dbl (out of bounds)\nExiting...\n",j);
    exit(EXIT_FAILURE);
  }
  
  /* CONTROLLARE CHE SIA GIUSTA */
  /*
  res = M * 0.5 * (2*xx[j]*dx*(1+ OM*OM) - 2*xx[j+1]*dx)
        + (OM*OM)*M*0.5*(dx*dx + 2*xx[j]*dx) + M*0.5*(2*dx*xx[j-1] - 2*xx[j]*dx);
  */ 
  if(j==0)
  {
    temp = xx[0] - xx[1];
  }else{
    temp = xx[j-1] - xx[(j+1)%N];
  }
  return M*0.5 * 
        (
          (2+OM*OM)*dx*dx
          + 2*OM*OM*dx*xx[j]
          + 2*dx*temp
        );
} 

/* Sweep: sweep through the current state, change each coordinate and check 
 * whether or not to update the state*/
/*NEEDS TO BE FIXED*/
void sweep(void)
{
  /*Array of 2N random numbers, N for variation of state and N for test*/
  double r[2*N];
  int j;
  double edeltaS;
  double var;
  /*Make sure randome generator is initialized in MAIN before this step*/
  ranlxd(r, 2*N);

  /*Loop sullo stato xx[N]*/
  for(j = 0; j < N; j++){
    var = 2*DELTA*(r[j]-0.5);
    edeltaS = exp(-1*delta_action_dbl(var, j));
    if(edeltaS >= r[j+N]){
      xx[j] += var;
    }
  }
  return;
}



