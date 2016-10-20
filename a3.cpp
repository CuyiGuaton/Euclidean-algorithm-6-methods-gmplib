#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) 
{

// Decalración 

  mpz_t a, b, r, d;

  mpz_init (r);   mpz_init_set_ui (d,1);
  mpz_init_set_str (a, argv[1], 10);
  mpz_init_set_str (b, argv[2], 10);

  if( argc != 3 ) { cout<<"Solo tiene que ingresar un valor para A y otro para B!"<<endl;	}
  else if( mpz_cmp ( a,b ) < 0 ) { cout<<"Error! A tiene que ser >= que B"<<endl; }
  else if( mpz_cmp_ui ( b,0 ) < 0 ) { cout<<"Error! B tiene que ser >= 0 "<<endl; } 
  else if( mpz_cmp_ui ( a,0 ) == 0 ) { cout<<"Error! A tiene que ser distinto de 0 "<<endl; }
  else{   

// A y B son pares //-------------------------------------------/
  while ( ( mpz_even_p(a) != 0 ) && ( mpz_even_p(b) != 0 ) )
  {
    mpz_div_ui ( a, a, 2); mpz_div_ui ( b, b, 2); mpz_mul_ui ( d, d, 2);
  }
 
  while ( mpz_even_p(a) != 0 )
  { 
    mpz_div_ui ( a, a, 2);
  }
 
  while ( mpz_even_p(b) != 0 )
  {
    mpz_div_ui ( b, b, 2); 
  }

// B > A //-------------------------------------------/

  if ( mpz_cmp (b, a) > 0 ){ mpz_set (r,b); mpz_set (b,a); mpz_set (a,r); }

// B != 0 //-------------------------------------------/

  while ( mpz_cmp_ui ( b,0 ) != 0 )   // Si B != 0
  { 
    mpz_sub ( r, a, b );

    while ( ( mpz_even_p(r) != 0 ) && ( mpz_cmp_ui ( r,0 ) > 0 ) )
    { 
      mpz_div_ui ( r, r, 2);
    }

    if ( mpz_cmp (r, b) >= 0 ){ mpz_set (a,r); }else{ mpz_set (a,b); mpz_set (b,r); }

  }
//-------------------------------------------------------------------------------------------//

  mpz_mul( d , d , a );

  cout<<"Valor de d:";	mpz_out_str(stdout,10,d);  cout<<"\n"<<endl;

// Eliminación de punteros //

  mpz_clear( a );
  mpz_clear( b );
  mpz_clear( r );
  mpz_clear( d );

  return 0;
//return i;

      }
}
