#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "prime-factors.h"
#include "prime-factors.inc"

int main (void){
	assert(prime_factors_init());	
	
	PrimeFactor *factors = prime_factors_create_full(1*394*1163*17*17);
	printf("Origine :\n");
	printf("%d\n",factors->count);
	printf("%s\n",prime_factors_to_string(factors));
	FILE * stream;
	stream = fopen("write.txt","w+");
	prime_factors_fwrite(factors,stream);
	rewind(stream);
	stream = fopen("write.txt","r");
	PrimeFactor *fact= prime_factors_create_default();
	
	fact=prime_factors_fread(fact,stream);
	
	printf("Sortie :\n");
	printf("%d\n",fact->count);
	printf("%s\n",prime_factors_to_string(fact));
	assert(prime_factors_finish());		
	return EXIT_SUCCESS;
}
