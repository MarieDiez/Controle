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
    
    polygon = polygon_prepend(polygon,42,32);
    polygon = polygon_append(polygon,5,5);
    polygon = polygon_append(polygon,13,5);
    polygon = polygon_append(polygon,2,0);
  
    printf("%s\n",polygon_to_string(polygon));
    
   polygon_destroy(polygon);
   
   
  }
  
  polygon_finish();
  return EXIT_SUCCESS;
}
