#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
    mpz_t a, b, r, a_b;

    mpz_init_set_ui (a_b,1);
    mpz_init_set_ui (r,1);
    mpz_init_set_str (a, argv[1], 10);
    mpz_init_set_str (b, argv[2], 10);
    mpz_add ( a_b, a, b );

// Decalración


  if( argc != 3 ) { cout<<"Solo tiene que ingresar un valor para A y otro para B!"<<endl; }
  else if( ( mpz_cmp_ui ( a,0 ) < 0 ) || ( mpz_cmp_ui ( b,0 ) < 0 ) ) { cout<<"Error! A y B tienen que ser >= 0 "<<endl; }
  else{

  while( mpz_cmp_ui ( b,0 ) != 0 )
  {
    mpz_init_set_ui (r,1); mpz_mod ( r, a, b );

    mpz_init_set (a,b); mpz_init_set (b,r);

  }

  cout<<"Valor de a:";	mpz_out_str(stdout,10,a);  cout<<"\n"<<endl;

  mpz_clear( a_b );
  mpz_clear( a );
  mpz_clear( b );
  mpz_clear( r );

  return 0;
//return i;

      }
}
