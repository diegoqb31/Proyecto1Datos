#pragma once
#include"Heap.h"

template<class T> class ColaDePrioridad{

private:

	Heap<T> heap;



public:

	ColaDePrioridad() {
	}

	void crearColaDePrioridad() {
		int n;
		std::cout<<"Digite (1) si desea que la cola de prioridad trabaje con elementos maximos o (2) con minimos: ";
		std::cin >> n;
		heap.crearHeap(heap.getLista(), n);
	}

	void Insertar(const T& val) {
		heap.Insertar(val);
	}

	void Eliminar() {
		heap.Eliminar();
	}

	void MostrarCola() {
		heap.MostrarHeap();
	}

	/*bool ColaVacia() {

	}*/

	int getSize() {

	}
};

