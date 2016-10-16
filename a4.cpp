/*----------------------------------------
La salida son el el mcd, el s y el t de
s*a + t*b = gcd(a,b)
----------------------------------------*/

#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) {
  mpz_t a;
  mpz_t b;
  mpz_t d;
  mpz_t s;
  mpz_t s1;
  mpz_t s2;
  mpz_t t;
  mpz_t t1;
  mpz_t t2;
  mpz_t r;
  mpz_t q;
  mpz_t aux;
  mpz_t v;
  mpz_t u;

  mpz_init(u);
  mpz_init(v);
  mpz_init(q);
  mpz_init(r);
  mpz_init(aux);
  mpz_init(s);
  mpz_init(t);
  mpz_init(d);
  mpz_init_set_str(a, argv[1],10);
  mpz_init_set_str(b, argv[2],10);
  mpz_init_set_ui(s1, 1);
  mpz_init_set_ui(t1, 0);
  mpz_init_set_ui(s2, 0);
  mpz_init_set_ui(t2,1);

  while (mpz_sgn(b)!= 0) {
     mpz_fdiv_q(q,a,b); //fdiv rounds q down towards -infinity
     mpz_tdiv_r(r,a,b); //calcula r en a = q*b + r
     //u <- s1 - q*s2
     mpz_mul(aux,q,s2);
     mpz_sub(u, s1,aux);
     //v <- t1 - q*t2
     mpz_mul(aux,q,t2);
     mpz_sub(v, t1,aux);
     //Se asignan vaolres
     mpz_set(a,b);
     mpz_set(s1,s2);
     mpz_set(t1,t2);
     mpz_set(b,r);
     mpz_set(s2,u);
     mpz_set(t2,v);
  }

  mpz_set(d,a);
  mpz_set(s,s1);
  mpz_set(t,t1);

  cout<<endl;
  mpz_out_str(stdout,10,d);
  cout<<" ";
  mpz_out_str(stdout,10,s);
  cout<<" ";
  mpz_out_str(stdout,10,t);
  cout<<endl;

  mpz_clear(v);
  mpz_clear(a);
  mpz_clear(b);
  mpz_clear(d);
  mpz_clear(s);
  mpz_clear(s1);
  mpz_clear(s2);
  mpz_clear(t);
  mpz_clear(t1);
  mpz_clear(t2);
  mpz_clear(r);
  mpz_clear(q);
  mpz_clear(aux);
  return 0;
}
