//<FLAGS>
//#define __GPU
//#define __NOPROTO
//<\FLAGS>

//<INCLUDES>
#include "fargo3d.h"
//#include "edamp.h"
//<\INCLUDES>

void Edamp_cpu(real dt) {

//<USER_DEFINED>
  INPUT(Energy);
  OUTPUT(Energy);
//<\USER_DEFINED>

//<INTERNAL>
  int i;
  int j;
  int k;
//<\INTERNAL>

//<EXTERNAL>
  real* e = Energy->field_cpu;
  real edamp = EDAMP;
  int pitch  = Pitch_cpu;
  int stride = Stride_cpu;
  int size_x = Nx;
  int size_y = Ny+2*NGHY;
  int size_z = Nz+2*NGHZ;
//<\EXTERNAL>
  //printf("size_x,size_y,size_z: %d,%d,%d", size_x, size_y, size_z);
//<MAIN_LOOP>
  for (k=0; k<size_z; k++) {
    for (j=0; j<size_y; j++) {
      for (i=0; i<size_x; i++) {
//<#> 
        //if(CPU_Master)
        //  printf("i= %d,j= %d,k= %d,l=%d \n", i, j, k, l);
        e[l] *= 1.0 / (1.0 + edamp * dt);

//<\#>
      }
    }
  }
//<\MAIN_LOOP>
}
