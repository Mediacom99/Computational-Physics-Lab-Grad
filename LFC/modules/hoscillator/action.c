 
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

void print_state(double* x)
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%e ",x[i]);
    if(i%3 == 0){
      printf("\n");
    }
	}
  printf("\n");
	return;
} 

/* 
  Args: 
    double* x -> current state on which to calculate the H.Oscillator action 
  Returns: the action as a double
*/
double action_dbl(double* x)
{ 
  double sum;
	int i;
  sum = 0.0;
	for(i = 0; i < N; i++)
	{
		sum += M*0.5 * (x[(i+1)%N] - x[i])*(x[(i+1)%N] - x[i]) 
		       + (OM*OM)*M*0.5*(x[(i)]*x[(i)]);
	}
  return sum;

}

/*This function calculates DeltaS = S(..,x,..) - S(...,y,...)*/
/*
 *  Args:  dx = xx[j]_new - xx[j]_old
 *        j = which coordinate to change
 *  Returns: the difference of the action with when x_j -> x_j + dx 
 * */

double delta_action_dbl(double* x, double dx, int j){ 
  
  double store[N];
  int i;

  /*Check that j is a valid position */
  if( j < 0 || j >= N){
    printf("Wrong argument 'j = %d' in function delta_action_dbl (out of bounds)\nExiting...\n",j);
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < N; i++)
  {
    if(i == j)
    {
      store[i] = x[i] + dx;
    }else{
    store[i] = x[i];
    }
  }

  return action_dbl(store) - action_dbl(xx);  

} 

/* Sweep: sweep through the current state, change each coordinate and check 
 * whether or not to update the state*/
void sweep(double* x)
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
    edeltaS = exp(-1*delta_action_dbl(x,var, j));
    if(edeltaS >= r[j+N]){
      x[j] += var;
    }
  }
  return;
}



