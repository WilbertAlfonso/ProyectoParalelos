#include "RSA.h"


RSA::RSA()
{
	alfabeto = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	do
	{
		p = GenPrime_ZZ(1024);
		q = GenPrime_ZZ(1024);
	} while (p == q);
	n = p*q;
	on = (p - 1)*(q - 1);
}


RSA::~RSA()
{
}
