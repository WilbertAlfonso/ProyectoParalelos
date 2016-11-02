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

RSA::~RSA()
{
}
