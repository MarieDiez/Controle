#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "polygon.h"
#include "polygon.inc"

static int counter = 0;

bool polygon_init(void){
	
	if (!counter++){
		assert(printf("polygon initialised\n"));
	}
	return true;
}

bool polygon_finish(void){

	if (counter){
		if (!--counter){
			assert(printf("polygon finished\n"));
		}
		return true;
	}
	else {
		return false;
	}
}
