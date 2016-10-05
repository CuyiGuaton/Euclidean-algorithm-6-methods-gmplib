#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) 
{
  if( argc != 3 ) { cout<<"Solo tiene que ingresar un valor para A y otro para B!"<<endl;	}
  else if( atoi(argv[1]) < atoi(argv[2]) ) { cout<<"Error! A tiene que ser >= que B"<<endl; }
  else if( atoi(argv[2]) < 0 ) { cout<<"Error! B tiene que ser >= 0 "<<endl; } 
  else if( atoi(argv[1]) == 0 ) { cout<<"Error! A tiene que ser distinto de 0 "<<endl; }
  else{   

// Decalración

  int i, b_int, a_int, r_int, a_1 , b_1; 

  mpz_t a, b, r, mod_a, mod_b, mod_r, d;

  mpz_init_set_ui (r,1);
  mpz_init_set_ui (d,1);
  mpz_init_set_ui (mod_a,1); mpz_init_set_ui (mod_b,1); mpz_init_set_ui (mod_r,1);
  mpz_init_set_str (a, argv[1], 10);
  mpz_init_set_str (b, argv[2], 10);
  
//---------------/ Módulos /-----------------------------//
// A
  mpz_mod_ui ( mod_a, a, 2 ); a_int = mpz_get_ui(mod_a); 
// B
  mpz_mod_ui ( mod_b, b, 2 ); b_int = mpz_get_ui(mod_b); 

// A y B son pares //-------------------------------------------/
  while ( ( a_int == 0 ) || ( b_int == 0 ) )
  {cout<<"ini_a_b"<<endl;
    mpz_div_ui ( a, a, 2); mpz_div_ui ( b, b, 2); mpz_mul_ui ( d, d, 2);

    // A
    mpz_mod_ui ( mod_a, a, 2 ); a_int = mpz_get_ui(mod_a);
    // B
    mpz_mod_ui ( mod_b, b, 2 ); b_int = mpz_get_ui(mod_b);

    a_1 = mpz_get_ui(a); b_1 = mpz_get_ui(b);

// Cortar ciclo //-----------------------------------------//

    if ( ( a_1 == 1 ) || ( b_1 == 1 ) ){ a_int = 1;}
  }

// A es par //-------------------------------------------/
  mpz_mod_ui ( mod_a, a, 2 ); a_int = mpz_get_ui(mod_a); 
 
  while ( a_int == 0 )
  { cout<<"ini_a"<<endl;
    mpz_div_ui ( a, a, 2);
//-----------/ M-A /------------------//
    mpz_mod_ui ( mod_a, a, 2 ); a_int = mpz_get_ui(mod_a); 
  }

// B es par //-------------------------------------------/
  mpz_mod_ui ( mod_b, b, 2 ); b_int = mpz_get_ui(mod_b); 
 
  while ( b_int == 0 )
  { cout<<"ini_b"<<endl;
    mpz_div_ui ( b, b, 2);
//-----------/ M-B /------------------//
    mpz_mod_ui ( mod_b, b, 2 ); b_int = mpz_get_ui(mod_b); 
  }

// B > A //-------------------------------------------/
  i=mpz_cmp (b, a);

  if ( i > 0 ){ mpz_init_set (r,b); mpz_init_set (b,a); mpz_init_set (a,r); }

// B != 0 //-------------------------------------------/

  i=mpz_cmp_ui (b, 0);

  while ( i == 0 )
  { cout<<"ini_b_0"<<endl;
    mpz_sub ( r, a, b );

// Preparando la condición /-----------------------------/

    mpz_mod_ui ( mod_r, r, 2 ); r_int = mpz_get_ui(mod_r); i=mpz_cmp_ui (r, 0);

    while ( r_int == 0 && i > 0 )
    {  cout<<"ini_r"<<endl;
      mpz_div_ui ( r, r, 2); mpz_mod_ui ( mod_r, r, 2 ); r_int = mpz_get_ui(mod_r); i=mpz_cmp_ui (r, 0);
    }

    i=mpz_cmp (r, b);
    if ( i >= 0 ){ mpz_init_set (a,r); }else{ mpz_init_set (a,b); mpz_init_set (b,r); }
    i=mpz_cmp_ui (b, 0);

  }
//-------------------------------------------------------------------------------------------//

  mpz_mul( d , d , a ); 
  i = mpz_get_ui(d); 

  cout<<"Valor de a:";  cout<<i<<endl;  // Lo puse solo para ver resultado final, pero se supone que devuelve "i".

// Eliminación de punteros //

  mpz_clear( a );
  mpz_clear( b );
  mpz_clear( r );
  mpz_clear( d );
  mpz_clear( mod_a );
  mpz_clear( mod_b );
  mpz_clear( mod_r );


  return 0;
//return i;

      }
}
