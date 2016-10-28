#pragma once
#include <string>
#include <NTL/ZZ.h>
#include <vector>
#include "aritmetica.h"
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
	RSA();
	~RSA();
	ZZ getLlavePublica(){
		return e;
	}
	string Encriptar(string datos);
	string Desencriptar(string datos);
};

