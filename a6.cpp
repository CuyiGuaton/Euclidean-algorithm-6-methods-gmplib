#include <cstdlib>
#include <gmp.h>
#include <iostream>
using namespace std;


void Div2(mpz_t s, mpz_t t, mpz_t A, mpz_t B) {
  cout<<endl;
  mpz_out_str(stdout,10,s);
  cout<<" ";
  mpz_out_str(stdout,10,t);
  cout<<endl;
  mpz_t aux;
  mpz_init(aux);
  if (mpz_even_p(s) != 0 && mpz_even_p(t) != 0) {
    mpz_tdiv_q_ui(s, s, 2);
    mpz_tdiv_q_ui(t, t, 2);
  } else {
    //(s+B)/2
    mpz_add(aux, s, B);
    mpz_tdiv_q_ui(s, aux, 2);
    //(t-A)/2
    mpz_sub(aux, t, A);
    mpz_tdiv_q_ui(t, aux, 2);
  }
  mpz_clear(aux);
}

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

  Div2(s1,t1,a,b);
  cout<<endl;
  mpz_out_str(stdout,10,s1);
  cout<<" ";
  mpz_out_str(stdout,10,t1);
  cout<<" ";
  mpz_out_str(stdout,10,u);
  cout<<" ";
  mpz_out_str(stdout,10,v);
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
}
