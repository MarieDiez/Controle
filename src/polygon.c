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

Polygon* polygon_clone(const Polygon* polygon){

	Polygon * dest = malloc(sizeof(Polygon));
	dest= polygon_copy(dest,polygon);
	
	return dest;

}

Polygon* polygon_copy(Polygon* dest, const Polygon* src){
	dest->count=src->count;
	dest->points = malloc(sizeof(Point)*dest->count);
	
	for (int i=0;i<dest->count;i++){
		(dest->points[i]).x=(src->points[i]).x;
		(dest->points[i]).y=(src->points[i]).y;
	}
	
	return dest;
}

Polygon* polygon_prepend(Polygon* polygon, double x, double y){
	Point pts;
	pts.x = x;
	pts.y = y;
	Point *tabPoints = polygon->points;
	polygon->count += 1;
	polygon->points = malloc(sizeof(Point)*(polygon->count));
	if (polygon->points){
		polygon->points[0] = pts;
		for(int i = 1; i < polygon->count; i++){
			polygon->points[i] = tabPoints[i-1];
		}
		free(tabPoints);
	}
	return polygon;
}

Polygon* polygon_insert(Polygon* polygon, int position, double x, double y){
		if (position > polygon->count){
			position = polygon->count;
		}
		
			Point pts;
			pts.x = x;
			pts.y = y;
			Point *tabPoints = polygon->points;
			polygon->count += 1;
			polygon->points = malloc(sizeof(Point)*(polygon->count));
			if (polygon->points){

				for(int i = 0; i < position; i++){
					polygon->points[i] = tabPoints[i];
				}
				
				polygon->points[position] = pts;
				
				for(int i = position+1; i < polygon->count; i++){
					polygon->points[i] = tabPoints[i-1];
				}
				
				free(tabPoints);
			}
			return polygon;
		
}

Polygon* polygon_append(Polygon* polygon, double x, double y){
	return polygon_insert(polygon,polygon->count,x,y);
}







