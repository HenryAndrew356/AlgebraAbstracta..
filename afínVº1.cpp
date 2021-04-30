#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
int mcd_euclides(int a,int tamAlfa);
int inversa(int a,int b);
class Afin
{
    private:
        int a;
        int b;
        int invA;
        string alf{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        //string alfAlternativo{"ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 1234567890-,.()"};
    public:
        Afin()
        {
            generarClaves();
        }
        Afin(int a1,int b1)
        {
            this->invA=inversa(a1,b1);
            this->b=b1;
        }
        void generarClaves()
        {
            this->a=rand()%10;
            srand (time(NULL));
            int aa=mcd_euclides(a,alf.size());
            while(aa!=1)
            {
                this->a=rand()%10;
                aa=mcd_euclides(a,alf.size());
            }
            this->a=aa;
            this->b=rand()%10;
        }
        void cifrado(string &mensaje)
        {
            int busqueda;
            for(unsigned int pasada1{0};pasada1<mensaje.size();pasada1++)
            {
                for(unsigned int pasadaAlf{0};pasadaAlf<alf.size();pasadaAlf++)
                {
                    if(mensaje[pasada1]==alf[pasadaAlf])
                    {
                        busqueda=pasadaAlf;
                        break;
                    }
                }
                mensaje[pasada1]=alf[(((a*busqueda)+b)%(int)(alf.size()))];
            }
        }
        void descifrado(string &mens_cifrado)
        {
            int busqueda;
            for(unsigned int pasada1{0};pasada1<mens_cifrado.size();pasada1++)
            {
                for(unsigned int pasadaAlf{0};pasadaAlf<alf.size();pasadaAlf++)
                {
                    if(mens_cifrado[pasada1]==alf[pasadaAlf])
                    {
                        busqueda=pasadaAlf;
                        break;
                    }
                }
                if(((invA*((busqueda)-b)))<(1))
                {
                    //cout<<"es: "<<abs(((invA*((busqueda)-b))%((int)alf.size())))<<endl;
                    mens_cifrado[pasada1]=alf[abs(((invA*((busqueda)-b))%((int)alf.size())))];
                }
                else
                {
                    mens_cifrado[pasada1]=alf[((invA*((busqueda)-b))%((int)alf.size()))];
                }
            }
        }
};

int main()
{
    Afin mensajeAcifrar;
    string mensaje;
    cout<<"Ingrese el mensaje a cifrar: "<<endl;
    getline(cin,mensaje);
    mensajeAcifrar.cifrado(mensaje);
    cout<<"El mensaje cifrado es: "<<mensaje<<endl<<endl;
    int A;
    int B;
    cout<<"Ingrese el valor de a: ";
    cin>>A;
    cout<<"Ingrese el valor de b: ";
    cin>>B;
    Afin mensajeAdescifrar(A,B);
    string men_cifrado{"HPCCXAQ"};
    //cout<<"Ingrese el mensaje a descifrar: "<<endl;
    //getline(cin,men_cifrado);
    mensajeAdescifrar.descifrado(men_cifrado);
    cout<<"El mensaje descifrado es: "<<men_cifrado<<endl<<endl;
}

int mcd_euclides(int a,int tamAlfa)
{
    int temp;
    while (tamAlfa != 0) {
        temp = tamAlfa;
        tamAlfa = a % tamAlfa;
        a = temp;
    }
    return a;
}

int inversa(int a,int b)
{
    int m0 = b;
    int t;
    int q;
    int x0 = 0;
    int x1 = 1;
    if (b == 1)
    {
        return 0;
    }
    while (a > 1)
    {
        q = a / b;
        t = b;
        b = a % b;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
    {
        x1 += m0;
    }
    return x1;
}
