#include <iostream>
#include <cstdlib>
#include <list>
#include "arbol.hpp"

using namespace std;

int main()
{
	dupla<int, double > m(8,4.1);
	dupla<int, double > n(52,8.6);
	dupla<int, double > o(1,4);
	dupla<int, double > j(2,4);
	dupla<int, double > k(3,4);
	dupla<int, double > y(4,4);
	dupla<int, double > x(80,4);
	nodo<dupla<int, double> > nodotest(m);
	nodo<dupla<int, double> > nodohijo(j);
	nodo<dupla<int, double> > nodohijo2(n);
	nodo<dupla<int, double> > nodohijo3(y);
	nodo<dupla<int, double> > nodohijo4(x);
	nodotest.agregar_valor(o);
	nodohijo.agregar_valor(k);
	nodohijo.set_Padre(nodotest);
	nodohijo2.set_Padre(nodotest);
	nodohijo3.set_Padre(nodotest);
	nodohijo4.set_Padre(nodohijo);
	//nodotest.cual_Camino(nodohijo);
	bool t=nodohijo.es_Hijo(nodotest);
	cout<<nodotest<<endl;
	cout<<nodohijo<<endl;
	cout<<t<<endl;

	tree< dupla<int,double> > arbtest(nodotest);

	arbtest.escribir_arbol("arbol.txt");

	return 0;
}
