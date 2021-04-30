#include <iostream>
#include <string>
#include <stdio.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
int mcd_euclides(int a,int tamAlfa);
class Afin
{
    private:
        int a;
        int b;
        string alf{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        //string alfAlternativo{"ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 1234567890-,.()"};
    public:
        Afin()
        {
            generarClaves();
        }
        Afin(int a1,int b1)
        {
            this->a=(alf.size())-a1;
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
                if(((a*((busqueda)-b)))<(1))
                {
                    mens_cifrado[pasada1]=alf[(alf.size())+(((a*((busqueda)-b))%((int)alf.size())))];
                }
                else
                {
                    mens_cifrado[pasada1]=alf[((a*((busqueda)-b))%(alf.size()))];
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
