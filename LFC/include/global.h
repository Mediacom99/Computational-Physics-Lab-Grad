
/*******************************************************************************
*
* File global.h
*
* Global parameters and arrays
*
*******************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#define N 64
#define M 1.0
#define OM 1.0
/*DELTA to be chosen between 0.5 and 3*/
#define DELTA 1.7

#if defined MAIN_PROGRAM
  #define EXTERN
#else
  #define EXTERN extern
#endif

/*
 * nel main program xx sarà variabile globale ovunque (nel main sarà
 * inclusa come double xx[N], perciò è full global), nei moduli invece devo passargli extern minuscolo così che quando ven * gono compilati anche loro sanno cos'è, cioè devo dire a gcc di non prendersela se non trova extern nei moduli perchè
 * quando viene linkato va in global.h e sa cos'è, perciò se vuoi variabile ultraglobale mettile qui.) 
 */
EXTERN double xx[N];

#undef EXTERN

#endif

