#pragma once
#include "ListaDoblementeEnlazada.h"


template<class T> class Heap{
private:
	
	ListaDoblementeEnlazada<T> lista;

	int Padre(int i) {
		return i / 2;
	}

	int HijoIzquierdo(int i) {
		return 2 * i;
	}

	int HijoDerecho(int i) {
		return (2 * i) + 1;
	}

public:

	Heap() {
		lista = new ListaDoblementeEnlazada<T>();
	}


	//Metedo que crea el MaxHeap a partir de una lista, se necesita un metodo intercambie dos nodos para poder implementarlo
	void MaxHeap(ListaDoblementeEnlazada<T> lista) {
		 
	}

	void MinHeap(ListaDoblementeEnlazada<T> lista) {

	}

	void Heapify() {

	}

	void imprimirHeap() {
		
	}

};

