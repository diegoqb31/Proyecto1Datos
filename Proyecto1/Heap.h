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
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr tmp;
		tmp = lista.getInicio();
		int i = 1;
		while (tmp != nullptr && i <= lista.getSize()) {
			if (i == 1) {
				i++;
				tmp = tmp->siguiente;
			}
			Nodoptr hijo = lista.obtenerNodoPorPosicion(i);
			Nodoptr padre = lista.obtenerNodoPorPosicion(Padre(i));
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
		this->lista = listad;
		return listad;
	}

	//Quitar los dos metodos mostrar despues hacer pruebas
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

	ListaDoblementeEnlazada<T> MinHeap(ListaDoblementeEnlazada<T> lista) {
		ListaDoblementeEnlazada<T> listad = lista;
		std::cout << "Entra al metodo MinHeap\n";
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr tmp;
		tmp = lista.getInicio();
		int i = 1;
		while (tmp != nullptr && i <= lista.getSize()) {
			if (i == 1) {
				i++;
				tmp = tmp->siguiente;
			}
			Nodoptr hijo = lista.obtenerNodoPorPosicion(i);
			Nodoptr padre = lista.obtenerNodoPorPosicion(Padre(i));
			std::cout << i << "(" << hijo->dato << ") > " << Padre(i) << "(" << padre->dato << ")?";
			if (hijo->dato < padre->dato) {
				std::cout << " R/Si\n";
				lista.intercambiarNodos(lista.obtenerNodoPorPosicion(Padre(i)), lista.obtenerNodoPorPosicion(i));
				std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
				MostrarIzquierdaADerecha(lista);
				MostrarDerechaAIzquierda(lista);
				listad = this->MinHeap(lista);
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

	void Eliminar() {
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr inicio = this->lista.getInicio();
		Nodoptr final = this->lista.getFinal();
		std::cout << "\nEliminar:\n";
		/*std::cout << "Inicio: " << inicio->dato << "\n";
		std::cout << "Final: " << final->dato<<"\n";
		MostrarIzquierdaADerecha(lista);*/

		this->lista.intercambiarNodos(inicio, final);
		//MostrarIzquierdaADerecha(lista);
		this->lista.EliminarUltimo();
		//MostrarIzquierdaADerecha(lista);
		//MostrarDerechaAIzquierda(lista);
	}

	void Heapify() {

	}

};

