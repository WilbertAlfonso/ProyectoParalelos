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
    do {
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
template <class T>
string RSA::convert(T num,bool val=1)
{
    stringstream convert;
    convert<<num;
    return convert.str();
}
ZZ RSA::convert(string Text)
{
    stringstream convert(Text);
    ZZ num;
    if ( !(convert >> num) )
        return  to_ZZ(-1);
    return num;
}
string RSA::ceros(string t,ZZ number)
{
    while((to_ZZ(t.size()))<lenNumber(number))
    {
        t="0"+t;
    }
    return t;
}
string RSA::cerosFin(string t,ZZ number)
{
    do
    {
        t+="0";
    }
    while(to_ZZ(t.length())%number!=0);
    return t;
}
string RSA::ceros(string t)
{
    return ceros(t,n);
}
ZZ RSA::lenNumber(ZZ dat)
{
    ZZ d;
    d=0;
    do
    {
        d++;
        dat=dat/10;
    }
    while(dat!=0);
    return d;
}
string  RSA::tratarMensaje(string msj)
{
    string total;
    for(int i=0; i<msj.size(); i++)
    {
        int dat= datos.find(msj[i]);
        cout<<"mi dat "<<dat<<endl;
        string aux;
        aux=convert<int>(dat);

        while((aux.length())<lenNumber(to_ZZ(datos.length()-1)))
        {
            aux="0"+aux;
            cout<<aux<<endl;
        }
        cout<<"aux: "<<aux<<endl;
        total+=aux;
    }
    return total;
}

string RSA::cifrarMensaje(string datos)
{
    string d=tratarMensaje(datos);

    ZZ val=lenNumber((n))-1;
    string total;
    string aux;


    if((to_ZZ(d.length())%val)!=0)
        d=cerosFin(d,val);

    for(long i=0; i<to_long(d.length()); i+=to_long(val))
    {
        string t=d.substr(i,to_long(val));
        ZZ temp(INIT_VAL, t.c_str());

        t=convert(PowerMod(temp,e,n));
        if(t.size()<lenNumber(n))
        {
            total+=ceros((t));
        }
        else
        {
            total+=t;
            cout<<t<<endl;
        }
    }
    return total;
}




RSA::~RSA()
{
}
