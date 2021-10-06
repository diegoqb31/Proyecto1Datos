#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include "Heap.h"

int main()
{

	ListaDoblementeEnlazada<int> li;


	li.Insertar(10);
	li.Insertar(20);
	li.Insertar(15);
	li.Insertar(30);
	li.Insertar(40);

	Heap<int> hp;
	li = hp.crearHeap(li, 2);

	hp.MostrarHeap();

	hp.Insertar(11);
	hp.Insertar(5);
	hp.MostrarHeap();

	hp.Eliminar();
	hp.MostrarHeap();

	//hp.Heapify();
	//hp.MostrarHeap();

	return 0;
}
