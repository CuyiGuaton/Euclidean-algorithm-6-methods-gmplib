#include <stdio.h>
#include <gmp.h>
#include <time.h>



void Div2 (mpz_t param1, mpz_t param2, mpz_t A, mpz_t B);




int main(int argc, char*argv[])
{
	mpz_t a, b, d, r, q, s, t, u, v;
	mpz_t auxa,auxb;
	mpz_t s1, t1;
	mpz_t s2, t2;
	mpz_t A, B;
	clock_t tinicial, tfinal; // inicio de tiempos

	mpz_init (a);
	mpz_init (b);
	mpz_init (d);
	mpz_init (q);
	mpz_init (r);
	mpz_init (s);
	mpz_init (t);
	mpz_init (u);
	mpz_init (v);
	mpz_init (A);
	mpz_init (B);

	mpz_init (s1);
	mpz_init (s2);
	mpz_init (t1);
	mpz_init (t2);

	mpz_init (auxa);
	mpz_init (auxb);


	mpz_set_str (a, argv[1], 0);
	mpz_set_str (b, argv[2], 0);

	mpz_set_ui(d,1);
	mpz_set_ui(q,1);






	//--------------------------------------------------------------------------------------//

	if (mpz_get_ui(a) < mpz_get_ui(b))
	{
		mpz_swap (a, b);
	}
	mpz_set (auxa,a);
	mpz_set (auxb,b);
	//--------------------------------------------------------------------------------------//

	if (mpz_get_ui(a) == 0)
	{
		printf("NULL");
		return 0;
	} // si a es cero retorna nulo

	//--------------------------------------------------------------------------------------//


	tinicial = clock(); // tiempo inicial

	//--------------------------------------------------------------------------------------//

	printf("estoy aqui");

	while(mpz_even_p(a) !=0 && mpz_even_p(b) != 0) // mientras a y b sean para
	{

		mpz_cdiv_q_ui (a,a,2); // a = a/2
		mpz_cdiv_q_ui (b,b,2); // b = b/2
		mpz_mul_ui(d,d,2); // d = d*2

	}

	mpz_set(A,a); // A = a
	mpz_set(B,b); // B = b

	mpz_set_ui(s1,1); // s1 = 1
	mpz_set_ui(t1,0); // t1 = 0

	mpz_set_ui(s2,0); // s2 = 0
	mpz_set_ui(t2,1); // t2 = 1

	//--------------------------------------------------------------------------------------//

	while(mpz_even_p(a) !=0)
	{
		mpz_cdiv_q_ui (a,a,2); // a = a/2

		Div2(s1, t1, A, B);

		//mpz_set(u,s1);
		//mpz_set(v,t1);

	}

	//--------------------------------------------------------------------------------------//

	while(mpz_even_p(b) !=0)
	{
		mpz_cdiv_q_ui (b,b,2); // b = b/2

		Div2(s2, t2, A, B);

		//mpz_set(u,s2);
		//mpz_set(v,t2);

	}

	//--------------------------------------------------------------------------------------//

	if(mpz_get_ui(a) > mpz_get_ui(b))
	{
		mpz_set(r,b); // r = b
		mpz_set(b,a); //  b = a
		mpz_set(a,r); // a = r
		mpz_set(u,s2); // u = s2
		mpz_set(s2,s1); // s2 = s1
		mpz_set(s1,u); // s1 = u
		mpz_set(v,t2); // v = t2
		mpz_set(t2,t1); // t2 = t1
		mpz_set(t1,v); // t1 = v
	}

	//--------------------------------------------------------------------------------------//

	while(mpz_get_ui(b) !=0) // mientras b distinto de 0
	{
		mpz_sub(r,a,b); // r = a - b
		mpz_sub(u,s1,s2); // u = s1 - s2
		mpz_sub(v,t1,t2); // v = t1 - t2

		//--------------------------------------------------------------------------------------//

		while(mpz_even_p(r) !=0 || mpz_get_ui(r) != 0) // mientras r sea para y r distinto de 0
		{
		  mpz_tdiv_q_ui (r,r,2); // r = r/2

		  Div2(u,v,A,B);
		  printf("pico");

		}

		//--------------------------------------------------------------------------------------//

		if(mpz_get_ui(r) >= mpz_get_ui(b))
		{
			mpz_set(a,r); // a = r
			mpz_set(s1,u); // s1 = u
			mpz_set(t1,v); // t1 = v

		}

		else
		{
			mpz_set(a,b); // a = b
			mpz_set(b,r); // b = r
			mpz_set(s1,s2); // s1 = s2
			mpz_set(s2,u); // s2 = u
			mpz_set(t1,t2); // t1 = t2
			mpz_set(t2,v);	// t2 = v

		}
	}

	//--------------------------------------------------------------------------------------//

	mpz_mul(d,d,a); // d = d*a
	mpz_set(s,s1); // s = s1
	mpz_set(t,t1); // t = t1


	//--------------------------------------------------------------------------------------//

	tfinal = clock(); // fin tiempo

	float tiempo;
	tiempo = (double)(tfinal - tinicial)/CLOCKS_PER_SEC;

	//--------------------------------------------------------------------------------------//

	gmp_printf (" t = %Zd ",t);
	gmp_printf ("\n s = %Zd \n",s);
	gmp_printf (" %Zd = gcd ( %Zd , %Zd ) = %Zd*%Zd  + %Zd*%Zd   \n", d, auxa, auxb, s, auxa, t, auxb);
	printf("tiempo total(en segundos) = %f\n", (tiempo));

	//--------------------------------------------------------------------------------------//

	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(A);
	mpz_clear(B);
	mpz_clear(d);
	mpz_clear(r);
	mpz_clear(q);
	mpz_clear(s);
	mpz_clear(t);
	mpz_clear(v);
	mpz_clear(u);
	mpz_clear(auxa);
	mpz_clear(auxb);
	mpz_clear(s1);
	mpz_clear(s2);
	mpz_clear(t1);
	mpz_clear(t2);




	//--------------------------------------------------------------------------------------//


	return 0;
}

void Div2 (mpz_t param1, mpz_t param2, mpz_t A, mpz_t B)
{
	if(mpz_even_p(param1) !=0 && mpz_even_p(param2) != 0)
	{

		mpz_cdiv_q_ui (param1,param1,2);
		mpz_cdiv_q_ui (param2,param2,2);

	}

	else
	{

		mpz_add(param1,param1,B);
		mpz_cdiv_q_ui (param1,param1,2);

		mpz_sub(param2,param2,A);
		mpz_cdiv_q_ui (param2,param2,2);

	}


}
