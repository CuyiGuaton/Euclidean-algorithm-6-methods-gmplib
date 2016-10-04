#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) 
{
    int i, b_int, a_int;
  
    mpz_t a, b, r;

    mpz_init_set_ui (r,1);
    mpz_init_set_str (a, argv[1], 10);
    mpz_init_set_str (b, argv[2], 10);

// Decalración
  
    b_int = mpz_get_ui(b); 
    a_int = mpz_get_ui(a); 

  if( argc != 3 ) { cout<<"Solo tiene que ingresar un valor para A y otro para B!"<<endl; }
  else if( a_int < b_int ) { cout<<"Error! A tiene que ser >= que B"<<endl; }
  else if( ( a_int + b_int ) <= 0 ) { cout<<"Error! B tiene que ser > 0 "<<endl; } 
  else if( ( mpz_cmp_ui ( a,0 ) < 0 ) || ( mpz_cmp_ui ( b,0 ) < 0 ) ) { cout<<"Error! A y B tienen que ser >= 0 "<<endl; }
  else{   

  while( b_int != 0 )
  {
    mpz_init_set_ui (r,1); mpz_mod ( r, a, b );

    mpz_init_set (a,b); mpz_init_set (b,r); b_int = mpz_get_ui(b); 

  }

  i = mpz_get_ui(a); 

  cout<<"Valor de a:";  cout<<i<<endl;  // Lo puse solo para ver resultado final, pero se supone que devuelve "i".

  mpz_clear( a );
  mpz_clear( b );
  mpz_clear( r );

  return 0;
//return i;

      }
}
