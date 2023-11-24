
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
	for(i = 0; i < N - 1; i++)
	{
		sum += 0.5 * (xx[i+1] - xx[i])*(xx[i+1] - xx[i]) 
		       + (OM*OM)*0.25*(xx[i+1]*xx[i+1] + xx[i]*xx[i]);
	}
  /* Adding the i = N-1 term where xx[N] = x[0]*/
	sum +=  0.5*(xx[0] - xx[N - 1])*(xx[0] - xx[N-1]) 
          + (OM*OM)*0.25*(xx[0]*xx[0] + xx[N-1]*xx[N-1]);
  sum*= M/(2.0);
	return sum;

}

/*This function calculates DeltaS = S(..,x,..) - S(...,y,...)*/
/*
 *  Args:  dx = xx[j]_new - xx[j]_old
 *        j = which coordinate to change
 *  Returns: the difference of the action with when x_j -> x_j + dx 
 * */
double delta_action_dbl(double dx, int j){
 
  double res;
  /*Check that j is a valid position */
  if( j < 0 || j >= N){
    printf("Wrong argument 'j = %d' in function delta_action_dbl (out of bounds)\nExiting...\n",j);
    exit(EXIT_FAILURE);
  }

  /*Basically we are only calculating the difference at i = j and i = j-1, the
   * only two terms that are not zero*/
  /*First line: Difference of part (x[i+1] - x[i])^2
   *Second line: Difference of part (x[i+1]^2 + x[i]^2)*/
  res = 0.5*(dx*dx - xx[j]*xx[j] - dx*xx[j-1] + xx[j-1]*xx[j])
        + (OM*OM)*0.25*(dx*dx - xx[j]*xx[j]);
  return res;

}




