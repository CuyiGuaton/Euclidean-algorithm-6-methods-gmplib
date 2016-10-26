#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include "a6.cpp"
using namespace std;

int a5(mpz_t a, mpz_t b) {

  mpz_t d;
  mpz_t s;
  mpz_t t;
  mpz_t s1;
  mpz_t s2;
  mpz_t t1;
  mpz_t t2;
  mpz_t u;
  mpz_t v;
  mpz_t r;
  mpz_t A;
  mpz_t B;
  mpz_t aux;


  mpz_init(d);
  mpz_init(s);
  mpz_init(t);
  mpz_init(s1);
  mpz_init(s2);
  mpz_init(t1);
  mpz_init(t2);
  mpz_init(u);
  mpz_init(v);
  mpz_init(r);
  mpz_init(A);
  mpz_init(B);
  mpz_init(aux);



    mpz_set_ui(d, 1);
    // si a y b son par.
    while (mpz_even_p(a) != 0 && mpz_even_p(b) != 0) {
      mpz_tdiv_q_ui(a, a, 2); // a=a/2 trunca el resultado
      mpz_tdiv_q_ui(b, b, 2); // b=b/2
      mpz_mul_ui(d, d, 2);    // d=d*2
    }
    mpz_set(A, a);
    mpz_set(B, b);
    mpz_set_ui(s1, 1);
    mpz_set_ui(t1, 0);
    mpz_set_ui(s2, 0);
    mpz_set_ui(t2, 1);
    // mientras a sea par
    while (mpz_even_p(a) != 0) {
      mpz_tdiv_q_ui(a, a, 2); // a=a/2
      Div2(s1, t1, A, B);
    }
    // mientras b sea par
    while (mpz_even_p(b) != 0) {
      mpz_tdiv_q_ui(b, b, 2); // b=b/2
      Div2(s2, t2, A, B);
    }
    // si b>a
    if (mpz_cmp(b, a) > 0) {
      mpz_set(r, b);
      mpz_set(b, a);
      mpz_set(a, r);
      mpz_set(u, s2);
      mpz_set(s2, s1);
      mpz_set(s1, u);
      mpz_set(v, t2);
      mpz_set(t2, t1);
      mpz_set(t1, v);
    }

    // mientras b!=0
    while (mpz_cmp_ui(b, 0) != 0) {
      mpz_sub(r, a, b);   // r= a-b
      mpz_sub(u, s1, s2); // u = s1-s2
      mpz_sub(v, t1, t2); // v=t1-t2
      //  mpz_out_str(stdout, 10, r); esto es para depurar los valores de r
      //    cout<<endl;
      while (mpz_odd_p(r) == 0 && mpz_cmp_ui(r, 0) != 0) { // mientras r sea par
        mpz_tdiv_q_ui(r, r, 2);                            // r=r/2
        Div2(u, v, A, B);
      }

      if (mpz_cmp(r, b) >= 0) {
        mpz_set(a, r);
        mpz_set(s1, u);
        mpz_set(t1, v);
      } else {
        mpz_set(a, b);
        mpz_set(b, r);
        mpz_set(s1, s2);
        mpz_set(s2, u);
        mpz_set(t1, t2);
        mpz_set(t2, v);
      }
    }

    mpz_mul(d, d, a);
    mpz_set(s, s1);
    mpz_set(t, t1);

  }

  mpz_clear(d);
  mpz_clear(s);
  mpz_clear(t);
  mpz_clear(s1);
  mpz_clear(s2);
  mpz_clear(t1);
  mpz_clear(t2);
  mpz_clear(u);
  mpz_clear(v);
  mpz_clear(r);
  mpz_clear(A);
  mpz_clear(B);
  return 0;
}
