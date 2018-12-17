#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "prime-factors.h"
#include "prime-factors.inc"

static int count = 0;

static unsigned long primes_size = 0;
static unsigned long * primes = NULL;

bool prime_factors_init(void){
	if(!count++){
		primes_size = 25;
		unsigned long tmp[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
		primes = realloc(primes, sizeof(tmp));
		if(primes){
			for(int i=0 ; i<primes_size ; i++){
				*(primes+i) = tmp[i];
			}
			printf("Prime-factors initialised\n");
		}else{
			return false;
		}
	}
	return true;
}

bool prime_factors_finish(void){
	if (count){
		if(!--count){
			free(primes);
			primes = NULL;
			primes_size = 0;
			printf("Prime-factors ended\n");
		}
		return true;
	}
	return false;
}

void extend_primeTab(){

	int nb=primes[primes_size-1]+1;
	bool rep=false;
	int i=0;

	while(!rep){
		if(nb%primes[i]==0){
			nb++;
			i=0;
		}
		else{
			i++;
		}

		if(i==primes_size){
			primes_size++;
			primes = realloc(primes, sizeof(unsigned long)*primes_size);
			primes[primes_size-1]=nb;
			rep=true;
		}

	}	
	for (int j=0;j<primes_size;j++){
		primes[primes_size-1];
	}

}


PrimeFactor *prime_factors_create_full(unsigned long number){

	PrimeFactor *primeFact = malloc(sizeof(PrimeFactor));
	primeFact->count=-1;

	if(primeFact){

		if(number==0){
			free(primeFact);
			return NULL;
		} 
		else if (number==1){
			primeFact->count=0;
			primeFact->powers=NULL;
		}
		else{
			int i=0;
			int *tab=malloc(sizeof(unsigned long)*primes_size);
			tab[0] = 0;

			while(number>1){
				if(number%primes[i]!=0){
					i++;
					if(i==primes_size){
						extend_primeTab();
						tab=realloc(tab,sizeof(unsigned long)*primes_size);
					}
					tab[i]=0;
				}
				else {
					number=number/primes[i];
					tab[i]++;
				}
			}

			primeFact->powers = malloc(sizeof(int)*(i+1));
			primeFact->count=i+1;
			for (int j=0;j<primeFact->count;j++){
				primeFact->powers[j]=tab[j];
			}
			free(tab);
		}

		return primeFact;
	}
	else{
		return NULL;
	}


}

int getPrimes(int nb){
	while(primes_size<=nb){
		extend_primeTab();
	}
	return primes[nb];
}

PrimeFactor *prime_factors_create_default(void){
	return prime_factors_create_full(1);
}

void prime_factors_destroy(PrimeFactor *factors){
	free(factors->powers);
	free(factors);
}


unsigned long prime_factors_get_number(const PrimeFactor *factors){
	for ( int i=0;i<factors->count;i++){
		factors->powers[i]*getPrimes(i);
	}
}

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

PrimeFactor *prime_factors_gcd( PrimeFactor *result, 	const PrimeFactor *a, const PrimeFactor *b ){

	int taille = min(a->count,b->count);
	int nbMin;
	int pgcd=1;
	for(int i=0;i<taille;i++){
		nbMin = min(a->powers[i],b->powers[i]);
		if (nbMin != 0){
			pgcd *= (int)pow((double)getPrimes(i),(double)nbMin);
		}
	}
	result=prime_factors_create_full(pgcd);
	return result;	
}

PrimeFactor *prime_factors_lcm( PrimeFactor *result, 	const PrimeFactor *a, const PrimeFactor *b ){

	int taille = max(a->count,b->count);
	int nbMax;
	int lcm=1;
	for(int i=0;i<taille;i++){
		nbMax = max(a->powers[i],b->powers[i]);
		if (nbMax != 0){
			lcm *= (int)pow((double)getPrimes(i),(double)nbMax);
		}
	}
	result=prime_factors_create_full(lcm);
	return result;	
}

PrimeFactor *prime_factors_pgcd_lcm( PrimeFactor *result, 	const PrimeFactor *a, const PrimeFactor *b, int (*funct)(int,int)){

	int taille = funct(a->count,b->count);
	int nbMin;
	int val=1;
	for(int i=0;i<taille;i++){
		nbMin = funct(a->powers[i],b->powers[i]);
		if (nbMin != 0){
			val *= (int)pow((double)getPrimes(i),(double)nbMin);
		}
	}
	result=prime_factors_create_full(val);
	return result;	
}

const char* prime_factors_to_string(const PrimeFactor *factors){
	static char ch[100];
	sprintf(ch,"%s","");
	for(int i = 0 ; i < factors->count ; i++){
		int mul = factors->powers[i] ;
		int prime = getPrimes(i) ;
		int val = (int)pow((double)prime,(double)mul);
		if(mul!=0 && mul!=1){
			sprintf(ch,"%s%d^%d",ch,prime,mul);
		}
		if(mul==1){
			sprintf(ch,"%s%d",ch,prime);
		}
		if(mul!=0 && i != factors->count-1){
			sprintf(ch,"%sx",ch);
		}
	}
	return ch;	
}

PrimeFactor *prime_factors_fwrite(const PrimeFactor * factors,FILE * stream){

	if(fwrite(&factors->count,sizeof(factors->count),1,stream) == 1 && fwrite(factors->powers,sizeof(int),factors->count,stream) == factors->count ){
		return (PrimeFactor *)factors;
	}
	else {
		return NULL;
	}
}

PrimeFactor *prime_factors_fread(PrimeFactor * factors,FILE * stream){
	int count;
	if(fread(&count,sizeof(int),1,stream) == 1 ){
		int * powers = malloc(count * sizeof(int));
		if (powers){
			if(fread(powers,sizeof(int),count,stream) != count){
				return NULL;
			}
			free(factors->powers);
			factors->count = count;
			factors->powers = powers;
			return factors;
		}else{
			return NULL;
		}
	}else{
		return NULL;
	}
}



