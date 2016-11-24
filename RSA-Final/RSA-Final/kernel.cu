
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
		string s = a.cifrarMensaje("Mi mama Me Mi r 0876543");
		cout << "Mensaje Encriptado: " << s;
		cout << a.descifrarMensaje(s) << endl;
	
	/*
	agregar metodos encriptar y desencriptar
	*/
	system("Pause");
	return 0;
}
