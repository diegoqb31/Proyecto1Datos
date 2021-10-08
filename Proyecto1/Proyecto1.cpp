#include <iostream>
#include "ListaDoblementeEnlazada.h"
#include "Heap.h"

int main()
{


	Heap<int> hp;
	hp.crearHeap(hp.getLista(), 1);

	hp.MostrarHeap();

	hp.Insertar(11);
	hp.Insertar(5);
	hp.Insertar(6);
	hp.Insertar(15);
	hp.MostrarHeap();

	hp.Eliminar();
	hp.MostrarHeap();

	hp.Heapify();
	hp.MostrarHeap();

	return 0;
}
