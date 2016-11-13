#include "aritmetica.h"
__global__
void FFTKernel(double* y_even, double* y_odd, double* y, double omega, int tam){
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i<tam / 2){
		int n = pow((double)omega, (double)i);
		y[i] = (y_even[i] + n*y_odd[i]);
		int indice = i + tam / 2;
		y[indice] = (y_even[i] - n*y_odd[i]);
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
	FFTKernel << < ceil(tam / 256.0), 256 >> > (d_y_even, d_y_odd, d_y, *X, tam);
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
	y_even = four(even, n, tam / 2);
	y_odd = four(odd, n, tam / 2);
	double* y = new double[tam];
	fourpara(y, y_even, y_odd, &n, tam);
	return y;
}

__global__
void FFTIKernel(double* y_even, double* y_odd, double* y, double omega, int tam){
	int i = threadIdx.x + blockDim.x * blockIdx.x;
	if (i<tam / 2){
		int n = pow((double)omega, (double)i);
		y[i] = (y_even[i] + n*y_odd[i]) / 2;
		int indice = i + tam / 2;
		y[indice] = (y_even[i] - n*y_odd[i]) / 2;
	}
}
void fourIpara(double* y, double* y_even, double* y_odd, double* X, int tam)
{
	int size = tam* sizeof(double);
	double *d_y, *d_y_even, *d_y_odd;
	cudaMalloc((void **)&d_y_even, size / 2);
	cudaMemcpy(d_y_even, y_even, size / 2, cudaMemcpyHostToDevice);
	cudaMalloc((void **)&d_y_odd, size / 2);
	cudaMemcpy(d_y_odd, y_odd, size / 2, cudaMemcpyHostToDevice);
	cudaMalloc((void **)&d_y, size);
	FFTIKernel << < ceil(tam / 256.0), 256 >> > (d_y_even, d_y_odd, d_y, *X, tam);
	cudaMemcpy(y, d_y, size, cudaMemcpyDeviceToHost);
	cudaFree(d_y); cudaFree(d_y_even); cudaFree(d_y_odd);
}
double* aritmetica::fourI(double* data, double n, int tam)
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
	y_even = fourI(even, n, tam / 2);
	y_odd = fourI(odd, n, tam / 2);
	double* y = new double[tam];
	fourIpara(y, y_even, y_odd, &n, tam);
	return y;
}

double* aritmetica::Mult(double* X, double* Y, int numbits)
{
	double* MX = (double*)malloc(numbits*sizeof(double));
	double* MY = (double*)malloc(numbits*sizeof(double));
	memset(MX, 0, numbits*sizeof(double));
	memset(MY, 0, numbits*sizeof(double));
	memcpy(MX, X, 2 * sizeof(*X));
	memcpy(MY, Y, 2 * sizeof(*X));
	for (int i = 0; i < numbits; i++)
	{
		cout << MY[i] << ";";
	}
	cout << endl;
	cout << endl;
	double* FX = four(MX, -1, numbits);

	double* FY = four(MY, -1, numbits);
	for (int i = 0; i < numbits; i++)
	{
		cout << FY[i] << ";";
	}
	cout << endl;
	cout << endl;
	double* FYI = fourI(FY, -1, numbits);
	for (int i = 0; i < numbits; i++)
	{
		cout << FYI[i] << ";";
	}
	cout << endl;
	cout << endl;
	double* Resp = new double[numbits];
	for (int i = 0; i < numbits; i++)
	{
		Resp[i] = FX[i] * FY[i];
		cout << Resp[i] << ";";
	}
	cout << endl;
	cout << endl;
	double* Inv = fourI(Resp, -1, numbits);
	for (int i = 0; i < numbits; i++)
	{
		cout << Inv[i] << ";";
	}
	return X;
}
ZZ aritmetica::powM(ZZ a, ZZ m, ZZ modulo)
{

	ZZ respuesta;
	respuesta = 1;
	ZZ x;
	x = a;
	while (m != 0)
	{

		if ((m & 1) == 1)
		{
			respuesta = (respuesta*x) % modulo;
			//cout<<"respuesta_ "<<respuesta<<" x: "<<x<<endl;


		}
		x = (x*x) % modulo;
		m >>= 1;
		// cout<<"m: "<<m<<" x: "<<x<<" respuesta: "<<respuesta<<endl;
		//if(mod(x,modulo)==1) break;

	}
	//cout<<endl;
	return respuesta;
}
ZZ aritmetica::Blum(long n)
{
    ZZ N,semilla, p, q, bits,x, res, temp;

    p = 7171153257;
    q =5;

    N = p * q;
    clock_t t;
    t=clock();
    semilla =t;
    x = semilla%N;
    res = 0, bits = 0;

    #pragma omp parallel for
    for(int i=n; i>0; i--)
    {
        x = powM(x, to_ZZ(2), N);
        bits = x-((x>>1)<<1);
        power(temp,to_ZZ(2),(i-1));
        res += bits*temp;
    }
    return res;
}
ZZ aritmetica::aleatorioBits(long long i)
{
    ZZ d =Blum(i);
    // cout<<d<<endl;
    if((d &1)==0)
        return d+1;
    else
        return d;
}
/*ZZ aritmetica::generaPrimo(long long bits)
{
    ZZ n =aleatorioBits(bits);
    while(MillerWitness((n),to_ZZ(80))==0)
        n=aleatorioBits(bits);
    return n;
}*/
ZZ aritmetica::generaPrimo(long long bits)
{
    ZZ n;
   
   do {
        n=aleatorioBits(bits);
        //cout<<n<<endl<<endl;
        //cout<<ProbPrime(n)<<endl<<endl;
    } while(ProbPrime(n)==0);
    return n;
}





