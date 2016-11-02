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
	RSA(int bits);
	~RSA();
	ZZ getLlavePublica(){
		return e;
	}
	string Encriptar(string datos);
	string Desencriptar(string datos);
};

