// ProyectoStl.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Heap.h"
#include <list>

int main()
{
	std::list<int> lista;
	lista.push_back(10);
	lista.push_back(20);
	lista.push_back(15);
	lista.push_back(30);
	lista.push_back(40);


	/*lista.push_back(40);
	lista.push_back(30);
	lista.push_back(15);
	lista.push_back(20);
	lista.push_back(10);*/


	Heap<int> hp;
	lista = hp.MaxHeap(lista);
	hp.MostrarHeap();

	//hp.EliminarMaxHeap();

	int n;
	std::cout << "\nDigite el valor a insertar: ";
	std::cin >> n;
	hp.InsertarMaxHeap(n);
	hp.MostrarHeap();
	/*hp.Insertar(1);
	hp.Insertar(2);
	hp.Insertar(3);
	hp.Insertar(4);
	hp.Insertar(5);
	hp.Insertar(6);*/


}

