
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <iostream>
#include<math.h>
#include <fstream>
#include <Windows.h>
#include "RSA.h"
int main()
{
	    RSA a(1024);
		ZZ MensajeE=a.Encriptar("c");
		cout << MensajeE << endl;
		cout << a.Desencriptar(MensajeE);
	
	/*
	agregar metodos encriptar y desencriptar
	*/
	system("Pause");
	return 0;
}
