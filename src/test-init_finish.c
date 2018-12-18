#include <stdlib.h>
#include <string.h>
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>
#include "./polygon.h"
#include "./polygon.inc"

int main (void){
	
	assert(polygon_init());
	assert(polygon_init());
	assert(polygon_init());
	
	assert(polygon_finish());
	assert(polygon_finish());
	assert(polygon_finish());
	assert(!polygon_finish());

}
