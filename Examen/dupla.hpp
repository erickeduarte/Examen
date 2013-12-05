#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
#ifndef DUPLA_H
#define DUPLA_H


/** \brief Esta clase construye el objeto dupla que va dentro de los nodos.
 * 
 */
template <typename K, typename V>
class dupla
{
	private:
		K key; ///Esta es la llave que representa al valor en el árbol.
		V valor; ///Este es el valor principal.
	public:
		dupla(K key,V valor);
		dupla(const dupla &copia);
		~dupla();
		bool operator<(const dupla &second);
		bool operator>(const dupla &second);
		bool operator==(const dupla &second);
		
		template <typename M, typename N>
		friend ostream& operator<<(ostream &out, dupla<M,N> &imprimir);
		template <typename O, typename G >
		friend string dupla_string(dupla<O,G> duplastr);
};

#endif

/** \fn dupla<K,V> ::dupla(K llave, V value)
 * \brief Esta función construye una dupla a partir de una key y un valor dados.
 */
template<typename K, typename V>
dupla<K,V> ::dupla(K llave, V value)
{
	this->key = llave;
	this->valor=value;
}

/** \fn dupla<K,V> ::dupla(const dupla &copia)
 * \brief Esta función construye una dupla a partir de otra dupla.
 */
template<typename K, typename V>
dupla<K,V> ::dupla(const dupla &copia)
{
	this->key = copia.key;
	this->valor=copia.valor;
}

/** \fn bool dupla<K,V>::operator<(const dupla &second)
 * \brief Esta función sobrecarga el operador < para que compare dos duplas a partir de su key.
 */
template<typename K, typename V>
bool dupla<K,V>::operator<(const dupla &second)
{
	return this->key < second.key;

}

/** \fn dupla<K,V>::~dupla()
 * \brief Esta función es el destructor de la clase.
 */
template<typename K, typename V>
dupla<K,V>::~dupla()
{	
}

/** \fn bool dupla<K,V>::operator>(const dupla &second)
 * \brief Esta función sobrecarga el operador > para que compare dos duplas a partir de su key.
 */
template<typename K, typename V>
bool dupla<K,V>::operator>(const dupla &second)
{
	return this->key > second.key;

}

/** \fn bool dupla<K,V>::operator==(const dupla &second)
 * \brief Esta función sobrecarga el operador >== para que compare dos duplas a partir de su key.
 */
template<typename K, typename V>
bool dupla<K,V>::operator==(const dupla &second)
{
	return this->key == second.key;
}

/** \fn string dupla_string(dupla<O,G> duplastr)
 * \brief Esta función cambia una dupla dada en un string.
 */
template<typename O, typename G>
string dupla_string(dupla<O,G> duplastr)
{
	stringstream st;
	st << duplastr.key;
	st<< " - ";
	st<< duplastr.valor;
	string str=st.str();
	return str;
}

/** \fn ostream& operator<<(ostream &out, dupla<M,N> &imprimir)
 * \brief Esta función imprime una dupla en consola.
 */
template<typename M, typename N>
ostream& operator<<(ostream &out, dupla<M,N> &imprimir)
{
	out <<"("<<imprimir.key<<" , "<<imprimir.valor<<")";
	
}
