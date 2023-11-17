
#include <stdio.h>
#include <stdlib.h>
#include "global.h"

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

double action ()
{
	/*Check that xx sia stato inizializzato*/

	double sum = 0.0;
	int i;
	for(i = 0; i < N - 1; i++)
	{
		sum += 0.5 * (xx[i+1] - xx[i])*(xx[i+1] - xx[i]) 
			+ (OM*OM)*0.25*(xx[i+1]*xx[i+1] + xx[i]*xx[i]);
	}
	sum*= M/(2.0);
	return sum;

}


