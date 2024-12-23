#include "fargo3d.h"

void Explode() {

    INPUT(Energy);
    OUTPUT(Energy);

    int i,j,k;
    real  yr, zr;
    int   yr0, zr0;
    real  p;
    real* e = Energy->field_cpu;
    //printf("Using Explote function");
    real Rate = 1.0; //Average number of explosions per unit time
    real sphere_radius = 0.05;

    sphere_radius *= sphere_radius; //we take the square.

    p = drand48();
    if (p < 1.0-exp(-DT*Rate)) {
    real sphere_radius = 0.1;

    yr = YMIN+drand48()*(YMAX-YMIN);
    zr = ZMIN+drand48()*(ZMAX-ZMIN);
    yr0 = yr;
    zr0 = zr;

    if (yr > YMIN + (YMAX-YMIN)/2.0)
          yr -= (YMAX-YMIN);
    else
       yr += (YMAX-YMIN);
    if (zr > ZMIN + (ZMAX-ZMIN)/2.0)
       zr -= (ZMAX-ZMIN);
    else
       zr += (ZMAX-ZMIN);

    sphere_radius *= sphere_radius; //we take the square.

    for (k=0; k<Nz+2*NGHZ; k++) {
      for (j=0; j<Ny+2*NGHY; j++) {
        for (i=0; i<Nx; i++) {
          if ((Ymed(j)-yr)*(Ymed(j)-yr) + (Zmed(k)-zr)*(Zmed(k)-zr) <= sphere_radius)
            e[l] = 5.0;
          if ((Ymed(j)-yr0)*(Ymed(j)-yr0) + (Zmed(k)-zr)*(Zmed(k)-zr) <= sphere_radius)
            e[l] = 5.0;
          if ((Ymed(j)-yr)*(Ymed(j)-yr) + (Zmed(k)-zr0)*(Zmed(k)-zr0) <= sphere_radius)
            e[l] = 5.0;
          if ((Ymed(j)-yr0)*(Ymed(j)-yr0) + (Zmed(k)-zr0)*(Zmed(k)-zr0) <= sphere_radius)
            e[l] = 5.0;
        }
      }
    }
  }
}

