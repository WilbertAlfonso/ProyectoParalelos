#pragma once
#include<string>
#include<iostream>
#include <NTL/ZZ.h>
#include<vector>
#include<algorithm>
#include <sstream>      // std::stringstream
#include<fstream>
using namespace NTL;
using namespace std;
class RSA
{
public:
	string alfabeto;
	ZZ p;
	ZZ q;
	ZZ n;
	ZZ on;
	ZZ e;
	ZZ d;
	aritmetica Funciones; //Aqui pondremos todas las funciones que hagamos en paralelo y algunos algortimos.
	
	/**
	Author: luis
	Constructor rsa
	int bits: es el numero de bits que tendra cada numero generado
	datos: es el abecedario de caracteres 
	*/
	RSA(int bits):datos(" abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    {

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
	~RSA();
	ZZ getLlavePublica(){
		return e;
	}
	string Encriptar(string datos);
	string Desencriptar(string datos);
};

