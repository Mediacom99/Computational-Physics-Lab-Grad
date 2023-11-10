
/*******************************************************************************
*
* File check1.c
*
* Check for the action of OA
*
* Author: Leonardo Giusti <Leonardo.Giusti@cern.ch>
*
*******************************************************************************/
#define MAIN_PROGRAM
#define CHECK1_C

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "global.h"
#include "random.h"

int main()
{
   int i;
   float r[N];

   printf("\n");
   printf("Check of the OA action \n");
   printf("\n");

   rlxs_init(1,12345);

   ranlxs(r,N);

   for (i=0;i<N;i++)
      xx[i]=(double)(r[i]);

   printf("\n Print xx values\n");

   for (i=0;i<N;i++)
      printf("i=%d, xx[%d]=%14.10f\n",i,i,xx[i]);
   
   printf("\n\n");
   exit(0);
}


