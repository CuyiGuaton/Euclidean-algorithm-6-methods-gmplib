#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int a3(mpz_t a, mpz_t b) {

  // Decalración

  mpz_t r, d;

  mpz_init(r);
  mpz_init_set_ui(d, 1);


    // A y B son pares //-------------------------------------------/
    while ((mpz_even_p(a) != 0) && (mpz_even_p(b) != 0)) {
      mpz_div_ui(a, a, 2);
      mpz_div_ui(b, b, 2);
      mpz_mul_ui(d, d, 2);
    }

    while (mpz_even_p(a) != 0) {
      mpz_div_ui(a, a, 2);
    }

    while (mpz_even_p(b) != 0) {
      mpz_div_ui(b, b, 2);
    }

    // B > A //-------------------------------------------/

    if (mpz_cmp(b, a) > 0) {
      mpz_set(r, b);
      mpz_set(b, a);
      mpz_set(a, r);
    }

    // B != 0 //-------------------------------------------/

    while (mpz_cmp_ui(b, 0) != 0) // Si B != 0
    {
      mpz_sub(r, a, b);

      while ((mpz_even_p(r) != 0) && (mpz_cmp_ui(r, 0) > 0)) {
        mpz_div_ui(r, r, 2);
      }

      if (mpz_cmp(r, b) >= 0) {
        mpz_set(a, r);
      } else {
        mpz_set(a, b);
        mpz_set(b, r);
      }
    }
    //-------------------------------------------------------------------------------------------//

    mpz_mul(d, d, a);


    // Eliminación de punteros //
    mpz_clear(r);
    mpz_clear(d);

    return 0;
    // return i;
  }
