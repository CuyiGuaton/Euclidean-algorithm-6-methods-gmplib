void Div2(mpz_t u, mpz_t v, mpz_t A, mpz_t B) {
  mpz_t aux;
  mpz_init(aux);
  if (mpz_even_p(u) != 0 && mpz_even_p(v) != 0) {
    mpz_tdiv_q_ui(u, u, 2);
    mpz_tdiv_q_ui(v, v, 2);
  } else {
    //(s+B)/2
    mpz_add(aux, u, B);
    mpz_tdiv_q_ui(u, aux, 2);
    //(t-A)/2
    mpz_sub(aux, v, A);
    mpz_tdiv_q_ui(v, aux, 2);
  }
  mpz_clear(aux);
}
