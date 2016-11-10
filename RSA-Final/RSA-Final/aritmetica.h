#pragma once
#include<math.h>
#include <algorithm> 
#include <iostream>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<time.h>
#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

class aritmetica
{
public:
	/**
	Funcion de Transformada de Fourier en CUDA (Recursiva)
	data: Sera un vector que represente el polinomio del numero
	n : Sera una raiz primitiva por defecto usaremos 1 ya que es valida como raiz primitiva
	tam: tamaño del vector data, por razones de formula el vector debera ser de un tamaño que cumpla que sea un 2^n.
	*/
	double* four(double* data, double n, int tam);
	ZZ Blum(long n);
	ZZ aleatorioBits(long long i);
	ZZ generaPrimo(long long bits);
};