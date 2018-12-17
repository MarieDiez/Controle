#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "prime-factors.h"
#include "prime-factors.inc"

int min(int a , int b ){

	if (a>b){
		return b;
	}
	else {
		return a;
	}

}

int max(int a , int b ){

	if (a<b){
		return b;
	}
	else {
		return a;
	}
}

int main (void){
	
	prime_factors_init();
	
	PrimeFactor * a = prime_factors_create_full(32);
	PrimeFactor * b = prime_factors_create_full(56);
	PrimeFactor * resultPgcd = NULL;
	PrimeFactor * resultLcm = NULL;
	int (*f) (int,int);
	f=min;
	resultPgcd=prime_factors_pgcd_lcm(resultPgcd, a, b,f);	
	
	f=max;
	resultLcm=prime_factors_pgcd_lcm(resultLcm, a, b,f);	
	
	printf("PGCD ");
	for (int i=0;i<resultPgcd->count;i++){
		printf("%d ",resultPgcd->powers[i]);
	}
	printf("\n");
	printf("LCM ");
	for (int i=0;i<resultLcm->count;i++){
		printf("%d ",resultLcm->powers[i]);
	}
	
	printf("\n");
	prime_factors_finish();
	return EXIT_SUCCESS;
}
