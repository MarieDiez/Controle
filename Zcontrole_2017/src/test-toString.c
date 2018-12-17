#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "prime-factors.h"
#include "prime-factors.inc"

int main (void){
	assert(prime_factors_init());	
	
	PrimeFactor *factors = prime_factors_create_full(1*394*1163*17*17);
	
	printf("%s\n", prime_factors_to_string(factors));

	assert(prime_factors_finish());		
	return EXIT_SUCCESS;
}
