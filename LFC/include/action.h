

#ifndef ACTION_H
#define ACTION_H

#ifndef ACTION_C
extern void print_state(double *x);
extern double action_dbl(double *x);
extern double deltaS_dbl(double *x, double dx, int j);
extern void sweep(double *x);
#endif

#endif
