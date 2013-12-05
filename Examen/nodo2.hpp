#include <cstdlib>
#include <iostream>
#include "dupla.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
#ifndef NODE_H
#define NODE_H

/** \brief Esta clase crea los nodos del 2-4 tree. 
 * 
 * 
 */
template <typename T>
class nodo
{
	private:
		
		nodo *padre; /// Esta variable es un puntero al padre de cada nodo.
		int numelems; /// Este es el numero de elementos contenidos en un nodo.
		vector<T> keys; /// Este es un vector con los elementos del nodo.
		vector<nodo*> hijos ; /// Este es un vector de punteros a los hijos de cada nodos.
		int nodo_num; /// Este es el número que identifica a cada nodo.
		int i=0; ///
		
	public:
		nodo(T& primero);
		// nodo(nodo &copia);
		~nodo();
		void set_hijos(nodo &nuevohijo);
		void set_Padre(nodo &nuevopadre);
		void agregar_valor(T& nueva_dupla);
		nodo *get_Padre();
		bool es_Hijo(nodo &padre);
		bool es_Hoja();
		//void cual_Camino(nodo &nuevohijo);
		/*nodo *busqueda();*/
		

		int get_nodo_num();
		string escribir_nodo_num(ofstream &archivoarbol);
		string escribir_hijos(ofstream &archivoarbol);
		template <typename M>
		friend ostream& operator<<(ostream &out, nodo<M> &imprimir);
		friend string to_string(int num);
};

#endif

/** \fn nodo<T>::nodo(T& primero)
 * \brief Esta función construye un nodo a partir de un valor inicial que se quera insertar en él.
 * \param T& primero, es el valor de la primera dupla en el árbol.
 */
template <typename T>
nodo<T>::nodo(T& primero)
{
	this->keys.push_back(primero);
	/*this->hijos.resize(4);
	for(int i=0; i < this->hijos.size(); ++i)
		this->hijos[i]=NULL;*/
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
/** \fn nodo<T>::~nodo()
 * \brief Es el destructor de la clase.
 */
template <typename T>
nodo<T>::~nodo()
{

}

/** \fn void nodo<T>:: set_hijos(nodo &nuevohijo)
 * \brief Esta función añade un nuevo hijo a un nodo.
 * \param nodo &nuevohijo, es la referencia al nodo hijo para agregar.
 */
template <typename T>
void nodo<T>:: set_hijos(nodo &nuevohijo)
{
	++i;
	nuevohijo.nodo_num=this->nodo_num+i;
	this->hijos.push_back(&nuevohijo);
}

/** \fn void nodo<T>:: set_Padre(nodo &nuevopadre)
 * \brief Esta función setea el padre de un nodo.
 * \param nodo &nuevopadre, es el nuevo padre del nodo.
 */
template <typename T>
void nodo<T>:: set_Padre(nodo &nuevopadre)
{
	this->padre=&nuevopadre;
	nuevopadre.set_hijos(*this);
} 

/** \fn void nodo<T> :: agregar_valor(T &nueva_dupla)
 * \brief Esta función agrega una nueva dupla a un nodo.
 * \param T &nueva_dupla, es la nueva dupla a insertar.
 */
template <typename T>
void nodo<T> :: agregar_valor(T &nueva_dupla)
{
	if(this->keys.size()<3)
	{
		this->keys.push_back(nueva_dupla);
		this->numelems++;
		
		int i,j;
		for(i=0; i < this->keys.size(); ++i)
		{
			for(j=0;j<i;j++)
			{
				if(this->keys[i]<this->keys[j])
				{
					swap(this->keys[i],this->keys[j]);
				}

			}

		}
		
		//this->hijos.resize(numelems+1);
		
	}
	else
	{
		cerr<<"Demasiados Valores no se puede insertar al nodo"<<endl;
	}
	
}

/** \fn nodo<T>* nodo<T>::get_Padre()
 * \brief Esta función obtiene el padre que le corresponde a un nodo.
 */
template <typename T>
nodo<T>* nodo<T>::get_Padre()
{
	return this->padre;
}

/** \fn bool nodo<T>::es_Hijo(nodo &padre)
 * \brief Esta función averigua si un nodo es hijo de otro nodo.
 * \param nodo &padre es el nodo que quiero saber si el nodo actual es el hijo.
 */
template <typename T>
bool nodo<T>::es_Hijo(nodo &padre)
{
	if(this->padre==&padre)
		return true;
	else
		return false;
}

/** \fn bool nodo<T>::es_Hoja()
 * \brief Esta función retorna true si el nodo es una hoja (no tiene hijos), y false si no es una hoja.
 */
template <typename T>
bool nodo<T>::es_Hoja()
{
	for(int i=0; i<this->hijos.size();++i)
	{
		if(this->hijos[i]!=NULL)return false;
	}
	return true;
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

/** \fn int nodo<T> :: get_nodo_num()
 * \brief Esta función retorna el numero del nodo en el árbol.
 */
template<typename T>
int nodo<T> :: get_nodo_num()
{

	return this->nodo_num;
}

/** \fn string to_string(int num)
 * \brief Esta función cambia un entero a un string.
 * \param int num, es el número que quiero cambiar a string.
 */
string to_string(int num)
{
	stringstream st;
	st << num;
	string str=st.str();
	return str;
}

/** \fn string nodo<T> :: escribir_nodo_num(ofstream &archivoarbol)
 * \brief Esta función construye un string con la sintaxis para incluir un nodo al documento de texto que usa DOT.
 * \param ofstream &archivoarbol, la referencia al archivo donde se va a escribir.
 */
template<typename T>
string nodo<T> :: escribir_nodo_num(ofstream &archivoarbol)
{
	string inicio = "node";
	string num = to_string(this->get_nodo_num());
	int i=0;
	inicio.append(num);
	inicio.append("[ label= \"<f0> ");
	inicio.append(dupla_string(this->keys[i]));

	if(this->keys.size()>1)
	{
		inicio.append("| <f1> ");
		inicio.append(dupla_string(this->keys[i+1]));	
	}

	if(this->keys.size()>2)
	{
		inicio.append("| <f2> ");
		inicio.append(dupla_string(this->keys[i+2]));
	}
	inicio.append("\"];\n");
	
	if(!this->es_Hoja())
	{
		for(int j=0; j<this->hijos.size();++j)
		{
			this->hijos[j]->escribir_nodo_num(archivoarbol);			
		}
	}
	return inicio;
}

/** \fn string nodo<T> :: escribir_hijos(ofstream &archivoarbol)
 * \brief Esta función escribe la relación entre padres e hijos en el archivo de texto, con la sintaxis DOT.
 * \param ofstream &archivoarbol, la referencia al archivo donde se va a escribir.
 */
template<typename T>
string nodo<T> :: escribir_hijos(ofstream &archivoarbol)
{
	string text;	
	if(!this->es_Hoja())
	{
		for(int i=0; i<this->hijos.size();++i)
		{
			text.append((this->hijos[i])->escribir_nodo_num(archivoarbol));

		}
		if(this->hijos.size()>=1&&this->hijos[0]!=NULL)
		{
			text.append("\n\"");
			text.append("node");
			text.append(to_string(this->get_nodo_num()));
			text.append("\": f0 --\"");
			text.append("node");
			text.append(to_string(this->hijos[0]->get_nodo_num()));
			text.append("\": f1;\n");

		}
		if(this->hijos.size()>=2&&this->hijos[1]!=NULL)
		{
			text.append("\n\"");
			text.append("node");
			text.append(to_string(this->get_nodo_num()));
			text.append("\": f1 --\"");
			text.append("node");
			text.append(to_string(this->hijos[1]->get_nodo_num()));
			text.append("\": f1;\n");

		}
		if(this->hijos.size()>=3&&this->hijos[2]!=NULL)
		{
			text.append("\n\"");
			text.append("node");
			text.append(to_string(this->get_nodo_num()));
			text.append("\": f1 --\"");
			text.append("node");
			text.append(to_string(this->hijos[2]->get_nodo_num()));
			text.append("\": f1;\n");

		}
		if(this->hijos.size()>=4&&this->hijos[3]!=NULL)
		{
			text.append("\n\"");
			text.append("node");
			text.append(to_string(this->get_nodo_num()));
			text.append("\": f2 --\"");
			text.append("node");
			text.append(to_string(this->hijos[3]->get_nodo_num()));
			text.append("\": f1;\n");

		}

		for(int j=0; j<this->hijos.size();++j)
		{
			this->hijos[j]->escribir_hijos(archivoarbol);
		}
	}
	else
	{
		return text;
	}
		
}

/** \fn ostream& operator<<(ostream &out, nodo<M> &imprimir)
 * \brief Esta función imprime un nodo en consola.
 * \param nodo<M> &imprimir, es la referencia al nodo a imprimir.
 */
template <typename M>
ostream& operator<<(ostream &out, nodo<M> &imprimir)
{
	for(int i=0; i < imprimir.keys.size(); ++i) 
		cout << imprimir.keys[i] << " "; 
	cout << endl;
	
}
