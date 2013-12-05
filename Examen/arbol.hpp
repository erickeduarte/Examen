#include <cstdlib>
#include <iostream>
#include "nodo2.hpp"
#include <list>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;
#ifndef ABTREE_H
#define ABTREE_H

/** \brief esta clase construye el 2,4 tree.
 * 
 */
template <typename T>
class tree
{
	private:
		vector<nodo<T> > arbol; ///Este es el vector de los nodos del arbol.
		nodo<T>* raiz; ///Este es el puntero del nodo a partir del cual se inicia el arbol.
	public:
		tree(nodo<T> &primernodo);
		~tree();
		void agregar_valor(T &nuevadupla);
		void agregar_nodo(nodo<T> &nuevonodo);
		void escribir_arbol(const char* archivo);
		
		
		
};
#endif

/** \fn tree<T> :: tree(nodo<T> &primernodo)
 * \brief Esta función construye un arbol a partir de el primer nodo.
 */
template <typename T>
tree<T> :: tree(nodo<T> &primernodo)
{
	
	this->arbol.push_back(primernodo);
	this->raiz=&this->arbol[0];
}

/** \fn tree<T> ::~tree()
 * \brief Esta función es el destructor del árbol.
 */
template <typename T>
tree<T> ::~tree()
{	
}

/*template <typename T>
void tree<T> :: agregar_valor(T &nueva_dupla)
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
		
		
	}
	
}*/

/** \fn void tree<T> ::agregar_nodo(nodo<T> &nuevonodo)
 * \brief Esta función agrega un nuevo nodo al árbol.
 */
template <typename T>
void tree<T> ::agregar_nodo(nodo<T> &nuevonodo)
{
	this->arbol.push_back(nuevonodo);
	
}

/** \fn void tree<T> :: escribir_arbol(const char* archivo)
 * \brief Esta función escribe en el archivo que utiliza DOT para generar la imagen del árbol.
 */
template<typename T>
void tree<T> :: escribir_arbol(const char* archivo)
{
	ofstream arch;

	arch.open(archivo);
	arch << "graph arbol { \n node [shape = record, height .1]; \n";
	arch<< this->raiz->escribir_nodo_num(arch);
	arch<< this->raiz->escribir_hijos(arch);
	arch << "\n}";
	arch.close();
}
	
