#pragma once
#include "ListaDoblementeEnlazada.h"


template<class T> class Heap {
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

	/*void Inicializar() {
		lista = new ListaDoblementeEnlazada<T>();
	}*/


public:


	Heap() {
		//Inicializar();
	}

	//Metedo que crea el MaxHeap a partir de una lista, se necesita un metodo intercambie dos nodos para poder implementarlo
	ListaDoblementeEnlazada<T> MaxHeap(ListaDoblementeEnlazada<T> lista) {
		ListaDoblementeEnlazada<T> listad = lista;
		std::cout << "Entra al metodo MaxHeap\n";
		ListaDoblementeEnlazada<int>::listaptr tmp;
		tmp = lista.getInicio();
		int i = 1;
		while (tmp != nullptr && i <= lista.getSize()) {
			if (i == 1) {
				i++;
				tmp = tmp->siguiente;
			}
			ListaDoblementeEnlazada<int>::listaptr hijo = lista.obtenerNodoPorPosicion(i);
			ListaDoblementeEnlazada<int>::listaptr padre = lista.obtenerNodoPorPosicion(Padre(i));
			std::cout << i << "(" << hijo->dato << ") > " << Padre(i) << "(" << padre->dato << ")?";
			if (hijo->dato > padre->dato) {
				std::cout << " R/Si\n";
				lista.intercambiarNodos(lista.obtenerNodoPorPosicion(Padre(i)), lista.obtenerNodoPorPosicion(i));
				std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
				MostrarIzquierdaADerecha(lista);
				MostrarDerechaAIzquierda(lista);
				listad = this->MaxHeap(lista);
				return listad;
			}
			else {
				std::cout << " R/No\n";
			}
			i++;
			tmp = tmp->siguiente;
		}
		return listad;
	}

	void MostrarIzquierdaADerecha(const ListaDoblementeEnlazada<int>& lista) {
		ListaDoblementeEnlazada<int>::listaptr tmp;
		tmp = lista.getInicio();
		while (tmp != nullptr) {
			std::cout << tmp->dato << " ";
			tmp = tmp->siguiente;
		}
		std::cout << "\n\n";
	}

	void MostrarDerechaAIzquierda(const ListaDoblementeEnlazada<int>& lista) {
		ListaDoblementeEnlazada<int>::listaptr tmp;
		tmp = lista.getFinal();
		while (tmp != nullptr) {
			std::cout << tmp->dato << " ";
			tmp = tmp->anterior;
		}
		std::cout << "\n\n";
	}

	void MinHeap(ListaDoblementeEnlazada<T> lista) {

	}

	void Heapify() {

	}

	void imprimirHeap() {
		
	}

};

