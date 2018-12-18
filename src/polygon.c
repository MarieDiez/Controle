#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./polygon.h"
#include "./polygon.inc"

static int counter = 0;

bool polygon_init(void){
	
	if (!counter++){
		assert(printf("Polygon initialised\n"));
	}
	return true;
}

bool polygon_finish(void){

	if (counter){
		if (!--counter){
			assert(printf("Polygon finished\n"));
		}
		return true;
	}
	else {
		return false;
	}
}


Polygon* polygon_create(void){
	Polygon * poly = malloc(sizeof(Polygon));
	poly->count=0;
	poly->points=NULL;
	
	return poly;
}

void polygon_destroy(Polygon* polygon){
	free(polygon->points);
	free(polygon);
}
