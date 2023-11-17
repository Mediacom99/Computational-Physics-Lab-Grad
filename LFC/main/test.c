#include <stdlib.h>
#include <stdio.h>
#include "global.h"
#include "action.h"



void fillXX()
{
	int i;
	for(i = 0; i < N-1; i++)
	{
		xx[i] = i;
	}
	return;

}

void printXX()
{
	int i;
	for(i = 0; i < N - 1; i++)
	{
		printf("%f\n",xx[i]);
	}
	return;
}

int main(int argc, char* argv[])
{
	fillXX();
	printf("Hello World\n");
	printXX();

	return(0);

}
