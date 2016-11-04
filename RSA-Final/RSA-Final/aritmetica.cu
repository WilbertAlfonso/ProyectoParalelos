#include "aritmetica.h"
__global__
void FourKernel(double* y_even, double* y_odd, double* y, int tam){
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i<tam / 2){
		y[i] = (y_even[i] + y_odd[i]);
		int indice = i + tam / 2;
		y[indice] = (y_even[i] - y_odd[i]);
	}
}
void fourpara(double* y, double* y_even, double* y_odd, double* X, int tam)
{
	int size = tam* sizeof(double);
	double *d_y, *d_y_even, *d_y_odd;
	cudaMalloc((void **)&d_y_even, size / 2);
	cudaMemcpy(d_y_even, y_even, size / 2, cudaMemcpyHostToDevice);
	cudaMalloc((void **)&d_y_odd, size / 2);
	cudaMemcpy(d_y_odd, y_odd, size / 2, cudaMemcpyHostToDevice);
	cudaMalloc((void **)&d_y, size);
	FourKernel << < ceil(tam / 256.0), 256 >> > (d_y_even, d_y_odd, d_y, tam);
	cudaMemcpy(y, d_y, size, cudaMemcpyDeviceToHost);
	cudaFree(d_y); cudaFree(d_y_even); cudaFree(d_y_odd);
}
double* aritmetica::four(double* data, double n, int tam)
{

	double * even = (double *)malloc((tam / 2)*sizeof(double));
	double * odd = (double *)malloc((tam / 2)*sizeof(double));
	double * y_even = (double *)malloc((tam / 2)*sizeof(double));
	double * y_odd = (double *)malloc((tam / 2)*sizeof(double));
	if (tam == 1) return data;
	for (int i = 0; i < tam / 2; i++)
	{
		even[i] = data[i * 2];
		odd[i] = data[i * 2 + 1];
	}
	y_even = four(even, pow(n, 2), tam / 2);
	y_odd = four(odd, pow(n, 2), tam / 2);
	double X = 1;
	double* y = new double[tam];
	fourpara(y, y_even, y_odd, &X, tam);
	return y;
}
