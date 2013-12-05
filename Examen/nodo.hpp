#include <cstdlib>
#include <iostream>
#include "dupla.hpp"
#include <list>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
#ifndef NODE_H
#define NODE_H

template <typename T>
class nodo
{
	private:
		
		nodo *padre;
		int numelems;
		list<T> keys;
		list<nodo*> hijos ;
		int nodo_num;
		
	public:
		nodo(T& primero);
		nodo(nodo &copia);
		~nodo();
		void set_Padre(nodo *nuevopadre);
		void agregar_valor(T& nueva_dupla);
		nodo *get_Padre();
		bool es_Hijo(nodo &padre);
		//void cual_Camino(nodo &nuevohijo);
		/*nodo *busqueda();*/
		
		//void set_hijos();
		int get_nodo_num();
		void escribir_nodo_num(ofstream &archivoarbol);
		
		template <typename M>
		friend ostream& operator<<(ostream &out, nodo<M> &imprimir);
		friend string to_string(int num);
};

#endif

template <typename T>
nodo<T>::nodo(T& primero)
{
	this->keys.push_back(primero);
	this->hijos.resize(2);
	typename list<nodo<T> * >::iterator i;
	for(i=this->hijos.begin(); i != this->hijos.end(); ++i)
		*i=NULL;
	this->padre=NULL;
	this->numelems=1;
	this->nodo_num=0;
}

/*template <typename T>
nodo<T>::nodo(const nodo &copy)
{
	this->numelems=copy.numelems;
	this->padre=copy.padre;
	list<dupla> lista (numelems+1);
	this->hijos=lista
	for (int i=lista.begin();i<lista.end(); ++i)
	{
		*i=copy.hijos[i];
	}
}*/

template <typename T>
nodo<T>::~nodo()
{

}

template <typename T>
void nodo<T>:: set_Padre(nodo *nuevopadre)
{
	this->padre=*nuevopadre;
} 

template <typename T>
void nodo<T> :: agregar_valor(T &nueva_dupla)
{
	if(this->keys.size()<3)
	{
		this->keys.push_back(nueva_dupla);
		this->numelems++;
		this->keys.sort();
		this->hijos.resize(numelems+1);
		
	}
	else
	{
		cerr<<"Demasiados Valores no se puede insertar al nodo"<<endl;
	}
	
}

template <typename T>
nodo<T>* nodo<T>::get_Padre()
{
	return this->padre;
}

template <typename T>
bool nodo<T>::es_Hijo(nodo &padre)
{
	if(this->padre==&padre)
		return true;
	else
		return false;
}

/*template <typename T>
void nodo<T>::cual_Camino(nodo &nuevohijo)
{
	typename list<T>::iterator i,j,k;
	for(i=this->keys.begin(); i != this->keys.end(); ++i)
	{
		k=i;
		for(j=nuevohijo.keys.begin(); j != nuevohijo.keys.end(); ++j)
		{
			if(*i < *j && *j< *(++k))
			{
				nuevohijo.padre=this;
				
			}
		}
	}
}*/
template<typename T>
int nodo<T> :: get_nodo_num()
{
	return this->nodo_num;
}

string to_string(int num)
{
	stringstream st;
	st << num;
	string str=st.str();
	return str;
}

template<typename T>
void nodo<T> :: escribir_nodo_num(ofstream &archivoarbol)
{
	string inicio = "node";
	string num = this->get_nodo_num().to_string();
	
	typename list<T>::iterator i=this->keys.begin();
	
	inicio.append(num);
	inicio.append("[ label= \"<f0> ");
	inicio.append(dupla_string(i));
	inicio.append("| <f1> ");
	inicio.append(dupla_string(++i));
	inicio.append("| <f2> ");
	inicio.append(dupla_string(++i));
	inicio.append(" ];");
}

template <typename M>
ostream& operator<<(ostream &out, nodo<M> &imprimir)
{
	typename list<M>::iterator i;

	for(i=imprimir.keys.begin(); i != imprimir.keys.end(); ++i) 
		cout << *i << " "; 
	cout << endl;
	
}


