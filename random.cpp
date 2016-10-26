
#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdarg.h>             /* Variable args   ISOC  */
#include <gmp.h>                /* GNU GMP Library       */
#include <math.h>
#include <time.h>
#include "a1.cpp"
#include "a2.cpp"
#include "a3.cpp"
#include "a4.cpp"
#include "a5.cpp"


int main(int argc, char const *argv[]) {
  mpz_t a; // Random number a
  mpz_t b; // random number b
  mpz_t piso;
  int nBit; // 2^(nbit) cantidad de bits
  gmp_randstate_t state;
  gmp_randstate_t stateb;


  // a y b van a contener números random
  mpz_init(a);
  mpz_init(b);
  mpz_init(piso);


  mpz_ui_pow_ui(piso,2,nBit); // piso= 2^(nBit)
  gmp_randinit_default(state);
  gmp_randseed_ui(state, 10);


	clock_t tStart, tEnd;
  float t;
  float min;

  for(int j=0, nBit = 2; j<10; j++, nBit=nBit*2){

    float MAX = 0;
    float min = 10;
    float t=0;
    for(int i = 0; i<20; i++){

      tStart = clock();

      mpz_urandomb(a, state, nBit);
      mpz_add(a,a,piso); // le suma a un número de  2^(nBit) para asegurarse que sea el minimo número a mostrar
      mpz_urandomb(b, state, nBit);
      mpz_add(b,b,piso); // le suma a un número de  2^(nBit) para asegurarse que sea el minimo número a mostrar
      if(mpz_cmp(b,a)>0) // si b es mayor que a
        mpz_swap(a,b); //entonces cambia los valores para que a sea más grande

      mpz_set(b,a);
      mpz_sub_ui(b,b,10);
      a2(a,b);
      tEnd = clock();
      t += (double)(tEnd - tStart)/CLOCKS_PER_SEC;
      if(min >(double)(tEnd - tStart)/CLOCKS_PER_SEC)
        min = (double)(tEnd - tStart)/CLOCKS_PER_SEC;
      if(MAX < (double)(tEnd - tStart)/CLOCKS_PER_SEC)
        MAX=(double)(tEnd - tStart)/CLOCKS_PER_SEC;
      //printf("\n i= %d t =  %.7f", i, (double)(tEnd - tStart)/CLOCKS_PER_SEC);
    }
    printf("\n %d \t %.7f \t %.7f \t %.7f ",nBit, t/20, MAX,min);
}

  gmp_randclear(state);
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(piso);
  return 0;

}
