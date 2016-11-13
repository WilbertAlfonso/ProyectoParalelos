#include "RSA.h"


RSA::RSA(int bits)
{
	datos=" abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        do
        {
            //p=GenPrime_ZZ(bits);
			p=Funciones.generaPrimo(bits);
            //q=GenPrime_ZZ(bits);
			q=Funciones.generaPrimo(bits);
        }
        while(p==q);

        n=p*q;
        on=(p-1)*(q-1);

		//e=Funciones.generaPrimo(bits);
	   //e=GenPrime_ZZ(bits); 
	do{
            e=Funciones.aleatorioBits(1024);
        }
        while((GCD(e,on))!=1);


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
	cout << s<<endl;
	return datos[s];
}
RSA::~RSA()
{
}
