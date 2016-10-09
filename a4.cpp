#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[]) {
  mpz_t a;
  mpz_t b;
  mpz_t s1;
  mpz_t s2;
  mpz_t t1;
  mpz_t t2;
  mpz_t r;
  mpz_t q;

  mpz_init(q);
  mpz_init_set_str(a, argv[1],10);
  mpz_init_set_str(b, argv[2],10);
  mpz_init_set_ui(s1, 1);
  mpz_init_set_ui(t1, 0);
  mpz_init_set_ui(s2, 0);
  mpz_init_set_ui(t2,1);

  while (/* condition */) {
     mpz_fdiv_q(q,a,b); //fdiv rounds q down towards -infinity
     mpz_tdiv_r(r,a,b); //calcula r en a = q*b + r
  }

  return 0;
}
