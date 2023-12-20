
#define ACTION_C

#include "action.h" /* The object file must include its own header file */
#include "global.h"
#include "random.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Modulo dell'oscillatore
 */

/*UTILITY*/

void print_state(double *x) {
  int i;
  for (i = 0; i < N; i++) {
    printf("%e ", x[i]);
    if (i % 3 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  return;
}

/* Initialize the state, should be called once in main,
 * AFTER having initalized the random generator:
 *  arg 0: char,
 *              w = warm start (random values through ranlxd)
 *              c = cold start (all zeroes)
 *  arg 1: pointer to state to Initialize
 */

void init_state(char s, double *x) {

  int i;
  if (s == 'w') {
    ranlxd(x, N);
    return;
  } else if (s == 'c') {
    for (i = 0; i < N; i++) {
      x[i] = 0.0;
    }
    return;
  } else {
    printf("Incorrect state initialization mode:\neither 'w' for warm or 'c' "
           "for cold, check init_state() call in main\nexiting...\n");
    exit(1);
  }
}

/*
  Args:
    double* x -> current state on which to calculate the H.Oscillator action
  Returns: the action as a double
*/
double action_dbl(double *x) {
  double sum;
  int i;
  sum = 0.0;
  for (i = 0; i < N; i++) {
    sum += M * 0.5 * (x[(i + 1) % N] - x[i]) * (x[(i + 1) % N] - x[i]) +
           (OM * OM) * M * 0.5 * (x[(i)] * x[(i)]);
  }
  return sum;
}
/*
 * ARGS:
 *  x = current state on which to calculate deltaS
 *  dx = variation of the j-th coordinate
 *  j = which coordinate to change
 * Returns: deltaS S(x_j + dx) - S(x_j)
 *
 */
double deltaS_dbl(double *x, double dx, int j) {
  double temp;
  if (j == 0) {
    temp = x[N - 1];
  } else {
    temp = x[j - 1];
  }
  return M * 0.5 * (2 + OM * OM) * (2 * dx * x[j % N] + dx * dx) -
         M * dx * (x[(j + 1) % N] + temp);
}

/* Sweep: sweep through the current state, change each coordinate and check
 * whether or not to update the state*/
void sweep(double *x) {
  /*Array of 2N random numbers, N for variation of state and N for test*/
  /* double r[2 * N]; */
  int j;
  double edeltaS;
  double var;
  int size = 2 * N;
  double *r;

  /* I had to use heap allocation for it to work with N >ish 600K */
  r = (double *)malloc(size * sizeof(double));
  /*Make sure randome generator is initialized in MAIN before this step*/
  ranlxd(r, size);

  for (j = 0; j < N; j++) {
    var = 2 * DELTA * (r[j] - 0.5);
    edeltaS = exp(-1 * deltaS_dbl(x, var, j));
    if (edeltaS >= r[j + N]) {
      x[j] += var;
    }
  }

  free(r);
  return;
}
