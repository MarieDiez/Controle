#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "prime-factors.h"
//#include "prime-factors.inc"

int main (void){

	assert(prime_factors_init());	
	assert(prime_factors_init());	
	assert(prime_factors_init());	

	assert(prime_factors_finish());
	assert(prime_factors_finish());
	assert(prime_factors_finish());
	assert(!prime_factors_finish());		


	return EXIT_SUCCESS;
}
