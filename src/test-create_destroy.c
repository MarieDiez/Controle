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
    polygon_destroy(polygon);
    
  }
  polygon_finish();
  return EXIT_SUCCESS;
}
