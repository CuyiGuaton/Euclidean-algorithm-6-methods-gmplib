#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int a2(mpz_t a, mpz_t b)
{
    mpz_t r, a_b;

    mpz_init_set_ui (a_b,1);
    mpz_init_set_ui (r,1);
    mpz_add ( a_b, a, b );

// Decalración


    while( mpz_cmp_ui ( b,0 ) != 0 )
    {
      mpz_init_set_ui (r,1); mpz_mod ( r, a, b );

      mpz_init_set (a,b); mpz_init_set (b,r);

    }

  mpz_clear( a_b );
  mpz_clear( r );

  return 0;
//return i;

}
