#include <stdlib.h>
#include <string.h>
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include "./polygon.h"
#include "./polygon.inc"

int main (void){
	
	polygon_init();
	{	
	
	Polygon* polygon = polygon_create();
	polygon = polygon_prepend(polygon,42,32);
	polygon = polygon_append(polygon,5,5);
	polygon = polygon_append(polygon,13,5);
	polygon = polygon_append(polygon,2,0);
	
	printf("Origine :\n");
	printf("%u\n",polygon->count);
	
	FILE * stream;
	stream = fopen("write.txt","w+");
	polygon_fwrite(polygon,stream);
	rewind(stream);
	stream = fopen("write.txt","r");
	Polygon * p = polygon_create();
	
	p=polygon_fread(p,stream);
	
	printf("Sortie :\n");
	
	printf("%u\n",p->count);
	
	
	polygon_destroy(polygon);
	
	}
	
	polygon_finish();
		
	return EXIT_SUCCESS;
}
