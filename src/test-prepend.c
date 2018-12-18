#include <stdlib.h>
#include <string.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "./polygon.h"
#include "./polygon.inc"

int main(void) {
  polygon_init();
  {
    Polygon* polygon = polygon_create();
    
    assert(polygon->points == NULL);
    
    polygon = polygon_prepend(polygon,42,32);
    
    printf("x : %.2f   y: %.2f\n",polygon->points[0].x,polygon->points[0].y);
    
    polygon_destroy(polygon);
   
  }
  
  polygon_finish();
  return EXIT_SUCCESS;
}
