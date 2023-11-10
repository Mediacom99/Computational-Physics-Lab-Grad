
/*******************************************************************************
*
* File time2.c
*
* Measurement of the processor time required to produce double-precision
* random numbers using ranlxd
*
* Author: Martin Luescher <luscher@mail.cern.ch>
*
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "random.h"

#define N 100
#define NLOOPS 100000

  int main()
  {
    int k,level;
    float t1,t2,dt;
    double r[N];

    printf("\n");
    printf("Timing of ranlxd (average time per random number in microsec)\n");
    printf("\n");
	
    /*Devo inizializzare il generatore di numeri random, solo 1 volta per simulazione, con certo seed*/
    for (level=1;level<=2;level++)
    {
      
      /*
       * Va inizializzato solo una volta init e mai nei moduli, solo nel main
       * se me ne servono altri posso chiamare ranlxd(r,N)
       */
      rlxd_init(level,1); /*Level può essere 0,1,2 mentre l'altro è il seed, devo cambiare seed tra simulazioni*/

      t1=(float)clock();
      for (k=1;k<=NLOOPS;k++) 
        ranlxd(r,N);
      t2=(float)clock();
      
      dt=(t2-t1)/(float)(CLOCKS_PER_SEC);
      dt*=1.0e6f/(float)(N*NLOOPS);      
      
      printf("%4.3f (level %1d)  ",dt,level);
    }
    printf("\n");
    printf("\n");
    exit(0);
  }


