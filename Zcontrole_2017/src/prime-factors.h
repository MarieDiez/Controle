#ifndef _PRIME_FACTORS_
#define _PRIME_FACTORS_

#include <stdbool.h>

typedef struct _PrimeFactor PrimeFactor;

extern bool prime_factors_init(void);
extern bool prime_factors_finish(void);

extern PrimeFactor *prime_factors_create_full(unsigned long number);
extern PrimeFactor *prime_factors_create_default(void);
extern void prime_factors_destroy(PrimeFactor *factors);
extern unsigned long prime_factors_get_number(const PrimeFactor *factors);
extern PrimeFactor *prime_factors_gcd( PrimeFactor *result, 
	const PrimeFactor *a, const PrimeFactor *b );
extern PrimeFactor *prime_factors_lcm( PrimeFactor *result,
	const PrimeFactor *a, const PrimeFactor *b );
	
extern PrimeFactor *prime_factors_pgcd_lcm( PrimeFactor *result, 	const PrimeFactor *a, const PrimeFactor *b, int (*funct)(int,int));	

extern const char *prime_factors_to_string(
	const PrimeFactor *factors);

extern PrimeFactor *prime_factors_fwrite(
const PrimeFactor * factors,
FILE * stream
);
extern PrimeFactor *prime_factors_fread(PrimeFactor * factors,FILE * stream);
#endif /* _PRIME_FACTORS_ */
