#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "prime-factors.h"
#include "prime-factors.inc"

int main (void){

	prime_factors_init();
	PrimeFactor *pf = prime_factors_create_full(3*7*26*13);
	
	
	int monTab[] = {1,1,0,1,0,2};	
	printf("%d\n",pf->count);
	assert(pf->count==6);
	for (int i=0;i<pf->count;i++){
		assert(pf->powers[i]==monTab[i]);
		printf("%d ",pf->powers[i]);
	}
	
	printf("\n");
	printf("                                                ^ 25\n");
	PrimeFactor *pfDef = prime_factors_create_default();
	assert(pfDef->powers==NULL);
	assert(pfDef->count==0);
	
	prime_factors_destroy(pf);
	prime_factors_destroy(pfDef);
	prime_factors_finish();
	return EXIT_SUCCESS;
}
