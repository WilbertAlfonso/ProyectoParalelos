#pragma once
#include<string>
#include<iostream>
#include <NTL/ZZ.h>
#include<vector>
#include<algorithm>
#include <sstream>      // std::stringstream
#include<fstream>
#include "aritmetica.h"
using namespace NTL;
using namespace std;
class RSA
{
public:
	string datos;
	ZZ p;
	ZZ q;
	ZZ n;
	ZZ on;
	ZZ e;
	ZZ d;
	aritmetica Funciones; //Aqui pondremos todas las funciones que hagamos en paralelo y algunos algortimos.
	
	/**
	Constructor rsa
	int bits: es el numero de bits que tendra cada numero generado
	datos: es el abecedario de caracteres 
	*/
	RSA(int bits);
	~RSA();
	ZZ getLlavePublica(){
		return e;
	}
	/**
	Metodos de Encriptar y Desencriptar
	msj: Se refiere al mensaje a encriptar
	j: Es el mensaje ya encriptado que se representara como un ZZ
	Nota: En esta fase solo usamos algunos metodos de la libreria para probar la 
	consistencia del metodo criptografico, solo encriptamos una letra por ahora.
	*/
	ZZ Encriptar(string msj);
	char Desencriptar(ZZ j);
};

