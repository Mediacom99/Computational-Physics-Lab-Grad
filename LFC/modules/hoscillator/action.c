
#define ACTION_C

#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "action.h" /* The object file must include its own header file */


/*
 * Modulo dell'oscillatore armonico con tutte le funzioni
 * necessarie per calcolare numericamente quello che serve.
 *
 *
 */


/*
 * Devo calcolare: S e Delta S in due routine diverse, è importante
 * che la routine di DeltaS sia la più efficiente possibile.
 */

/*returns the action calculated at the current state of xx[N] as a double*/
double action_dbl (void)
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
 
  double res;
  /*Check that j is a valid position */
  if( j < 0 || j >= N){
    printf("Wrong argument 'j = %d' in function delta_action_dbl (out of bounds)\nExiting...\n",j);
    exit(EXIT_FAILURE);
  }
  
  /* CONTROLLARE CHE SIA GIUSTA */
  res = M * 0.5 * (2*xx[j]*dx*(1+ OM*OM) - 2*xx[j+1]*dx)
        + (OM*OM)*M*0.5*(dx*dx + 2*xx[j]*dx) + M*0.5*(2*dx*xx[j-1] - 2*xx[j]*dx);
  return res;

}


/* Sweep: sweep through the current state, change each coordinate and */
void sweep(void)
{
  return;
}



