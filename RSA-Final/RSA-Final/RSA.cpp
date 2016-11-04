#include "RSA.h"


RSA::RSA(int bits)
{
	datos=" abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        do
        {
            p=GenPrime_ZZ(bits);
            q=GenPrime_ZZ(bits);
        }
        while(p==q);

        n=p*q;
        on=(p-1)*(q-1);

            e=GenPrime_ZZ(bits);

        d=InvMod(e,on);
    }
ZZ  RSA::Encriptar(string msj)
{
	ZZ j;
	j = datos.find(msj);
	j = PowerMod(j, e, n);
	return j;
}
char RSA::Desencriptar(ZZ j)
{
	ZZ r = PowerMod(j, d, n);
	int s = to_int(r);
	return datos[s];
}
RSA::~RSA()
{
}
