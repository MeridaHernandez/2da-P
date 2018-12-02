#include <iostream>
#include <time.h>
#include <stdlib.h>
//Merida Hernandez
using namespace std;
void reporte(int v[],int tam);
void insertar(int v[],int tam,int pos);
void modificar(int v[],int tam,int nuevo, int antiguo);
int buscar(int v[],int tam,int val);
void recorrer(int n[],int tam,int p);
bool eliminar(int v[],int tam, int val);
void agregar(int v[],int tam,int pos);
int aleatorio();
int menuMerida();
int main()
{

	srand(time(NULL));
	int v[20];
	int cont=0,op;
	do
	{
		op=menuMerida();
		switch(op)
		{
			case 1:
			{
				agregar(v,20,cont);
				cont++;
				break;
			}
			case 2:
			{
				int val;
				cout << "Valor a eliminar: "; //para eliminar
				cin >> val;
				cout << endl;
				if(eliminar(v,20,val))
				{
					cont--;
					cout << "Eliminado" << endl;
				}
				else
					cout << "No existe" << endl;// en caso de que no este

				break;
			}
			case 3:
			{
				int val;
				cout << "Valor: ";
				cin >> val;
				cout << endl;
				int bus=buscar(v,20,val);
				cout << "Posicion del valor: " << bus << endl <<endl;
				break;
			}
			case 4:
			{
				int nuevo,antiguo;
				cout << "Valor a reemplazar: ";
				cin >> antiguo;
				cout << endl << "Valor nuevo: ";  //reemplazo de valores
				cin >> nuevo;
				cout << endl;
				modificar(v,20,nuevo,antiguo);
				break;
			}
			case 5:
			{
				int pos;
				do
				{
					cout << "Posicion:";
					cin >> pos;
					cout << endl;
				}while(!(pos>=0 && pos<20));

				insertar(v,20,pos);
				break;
			}
			case 6:
			{
				reporte(v,20);
				break;
			}
			case 0:{
				cout << endl << "Fin del programa." << endl;
				break;
			}
			default:
				cout << "Ingrese una opcion valida." << endl;
		}
	}while(op!=0);


}

int menuMerida()
{
	int op;
	cout<<"Menu Merida :3"<<endl;
	cout << "1. Agregar" << endl;
	cout << "2. Eliminar" << endl;
	cout << "3. Buscar" << endl;
	cout << "4. Modificar" << endl;
	cout << "5. Insertar" << endl;
	cout << "6. reporte" << endl;
	cout << "0. salir" << endl;
	cin >> op;
	cout << endl;
	return op;
}
int aleatorio()
{
	int num;
	num=11+rand()%301;
	return num;
}
void agregar(int v[],int tam,int pos)
{
	int num;
	if(pos<tam)
    {
        v[pos]=aleatorio();
    }

}

bool eliminar(int v[],int tam, int val)
{
	int bus=buscar(v,tam,val);
	if(bus>=0)
	{
		v[bus]=0;
		recorrer(v,tam,bus);
		return true;
	}
	else
		return false;
}
void recorrer(int n[],int tam,int pos)
{
	for(int i=pos;i<tam-1;i++)
	{
		n[i]=n[i+1];
	}
	n[tam-1]=0;
}
int buscar(int v[],int tam,int val)
{
	for(int i=0;i<tam;i++)
	{
		if(v[i]==val)
			return i;
	}
	return -1;
}
void modificar(int v[],int tam,int nuevo, int antiguo)
{
	int bus=buscar(v,tam,antiguo);
	if(bus>=0)
	{
		v[bus]= nuevo;
	}
}
void insertar(int v[],int tam,int pos)
{
	for(int i=tam-1;i>=pos;i--)
	{
		v[i+1]=v[i];
	}
	v[pos]=aleatorio();
}
void reporte(int v[],int tam)
{
	for(int i=0;i<tam;i++)
		cout<<"[" <<i <<"]= " <<v[i] <<endl;

	cout<< endl;
}
