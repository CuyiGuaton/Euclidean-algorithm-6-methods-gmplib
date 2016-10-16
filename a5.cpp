#include <cstdlib>
#include <gmp.h>
#include <iostream>
using namespace std;
void Div2(mpz_t u, mpz_t v, mpz_t A, mpz_t B){
  mpz_t aux;
  mpz_init(aux);
  if(mpz_even_p(u)!=0 && mpz_even_p(v)!=0){
     mpz_tdiv_q_ui(u,u,2);
     mpz_tdiv_q_ui(v,v,2);
   }else{
     //(s+B)/2
     mpz_add(aux,u,B);
     mpz_tdiv_q_ui(u,aux,2);
     //(t-A)/2
     mpz_sub(aux,v,A);
     mpz_tdiv_q_ui(v,aux,2);
   }
}


int main(int argc, char const *argv[]) {

  mpz_t a;
  mpz_t b;
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

  mpz_init(a);
  mpz_init(b);
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

  mpz_set_str(a, argv[1],10);
  mpz_set_str(b, argv[2],10);
  mpz_set_ui(d,1);

  //si a y b son par.
  while (mpz_even_p(a)!=0 && mpz_even_p(b)!=0) {
     mpz_tdiv_q_ui(a,a,2); //a=a/2 trunca el resultado
     mpz_tdiv_q_ui(b,b,2);//b=b/2
     mpz_mul_ui(d,d,2); // d=d*2
  }
  mpz_set(A,a);
  mpz_set(B,b);
  mpz_set_ui(s1,1);
  mpz_set_ui(t1,0);
  mpz_set_ui(s2,0);
  mpz_set_ui(t2,1);

  while (mpz_even_p(a)!=0) {
    mpz_tdiv_q_ui(a,a,2); //a=a/2
    Div2(s1,t1,A,B);

  }

  cout<<endl;
  mpz_out_str(stdout,10,u);
  cout<<" ";
  mpz_out_str(stdout,10,v);
  cout<<" ";
  mpz_out_str(stdout,10,s1);
  cout<<" ";
  mpz_out_str(stdout,10,t1);
  cout<<endl;

  mpz_clear(a);
  mpz_clear(b);
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
