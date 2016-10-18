#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) 
{

 // Declaración

  mpz_t a, b, r;

  mpz_init_set_ui (r,1);
  mpz_init_set_str (a, argv[1], 10);
  mpz_init_set_str (b, argv[2], 10);

  if( argc != 3 ) { cout<<"Solo tiene que ingresar un valor para A y otro para B!"<<endl;	}
  else if( mpz_cmp ( a, b ) < 0 ) { cout<<"Error! A tiene que ser >= que B"<<endl; }
  else if( mpz_cmp_ui ( b, 0 ) < 0 ) { cout<<"Error! B tiene que ser >= 0 "<<endl; } 
  else if( mpz_cmp_ui ( a, 0 ) == 0 ) { cout<<"Error! A tiene que ser distinto de 0 "<<endl; }
  else{   

  while ( mpz_cmp_ui (b, 0) != 0 )
  {
    mpz_sub ( r, a, b );

    if ( mpz_cmp (r, b) >= 0 ){ mpz_set (a,r); }
    else { mpz_set (a,b); mpz_set (b,r); }

  }

  cout<<"Valor de a:";	mpz_out_str(stdout,10,a);  cout<<"\n"<<endl;

  mpz_clear( a );
  mpz_clear( b );
  mpz_clear( r );

  return 0;
//return i;

      }
}
