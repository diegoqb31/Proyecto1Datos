#pragma once
#include "ListaDoblementeEnlazada.h"


template<class T> class Heap {
private:

	ListaDoblementeEnlazada<T> lista;
	int tipo;

	int Padre(int i) {
		return i / 2;
	}

	int HijoIzquierdo(int i) {
		return 2 * i;
	}

	int HijoDerecho(int i) {
		return (2 * i) + 1;
	}

	void Inicializar() {
		tipo = 1;
	}


public:

	Heap() {
		Inicializar();
	}

	ListaDoblementeEnlazada<T> crearHeap(ListaDoblementeEnlazada<T> lista, int opcion) {
		ListaDoblementeEnlazada<T> listad = lista;
		this->tipo = opcion;
		//std::cout << "Entra al metodo MaxHeap\n";
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
			//std::cout << i << "(" << hijo->dato << ") > " << Padre(i) << "(" << padre->dato << ")?";
			if (opcion == 2) {
				if (hijo->dato < padre->dato) {
					//std::cout << " R/Si\n";
					lista.intercambiar(Padre(i), i);
					//std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
					//MostrarIzquierdaADerecha(lista);
					//MostrarDerechaAIzquierda(lista);
					listad = this->crearHeap(lista, 1);
					return listad;
				}
			}
			else {
				if (hijo->dato > padre->dato) {
					//std::cout << " R/Si\n";
					//lista.intercambiarNodos(lista.obtenerNodoPorPosicion(Padre(i)), lista.obtenerNodoPorPosicion(i));
					lista.intercambiar(Padre(i), i);
					//std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
					//MostrarIzquierdaADerecha(lista);
					//MostrarDerechaAIzquierda(lista);
					listad = this->crearHeap(lista, 1);
					return listad;
				}
			}
			
			i++;
			tmp = tmp->siguiente;
		}

		this->lista = listad;
		return listad;
	}

	void Eliminar() {
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr inicio = this->lista.getInicio();
		Nodoptr final = this->lista.getFinal();
		std::cout << "\nELIMINAR HEAP\n";

		this->lista.intercambiar(1, lista.getSize());
		this->lista.EliminarUltimo();

		MostrarHeap();

		//crearHeap(this->lista, tipo);
		Heapify();
	}


	void MostrarHeap() {
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr tmp;
		tmp = lista.getInicio();
		while (tmp != nullptr) {
			std::cout << tmp->dato << " ";
			tmp = tmp->siguiente;
		}
		std::cout << "\n\n";
	}

	void Insertar(const T& t) {
		std::cout << "\nINSERTAR HEAP\n";
		this->lista.Insertar(t);

		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr nodoHijo, nodoPadre;
		int hijo = this->lista.getSize(), padre = Padre(hijo);
		T val;

		while (hijo != 0 && padre > 0) {

			nodoHijo = lista.obtenerNodoPorPosicion(hijo);
			nodoPadre = lista.obtenerNodoPorPosicion(padre);

			//std::cout << "Se compara " << padre << " con " << hijo << "\n\n";
			if (this->tipo == 2) {
				if (nodoHijo->dato < nodoPadre->dato) {
					val = nodoHijo->dato;
					nodoHijo->dato = nodoPadre->dato;
					nodoPadre->dato = val;
				}
			}
			else {
				if (nodoHijo->dato > nodoPadre->dato) {
					val = nodoHijo->dato;
					nodoHijo->dato = nodoPadre->dato;
					nodoPadre->dato = val;
				}
			}
			hijo = Padre(hijo);
			padre = Padre(hijo);
			//MostrarHeap();
			//std::cout << "\n";

		}
	}

	void Heapify() {
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr tmp, l, r;
		tmp = lista.getFinal();
		int i = this->lista.getSize();
		T val;
		while (i > 0 && tmp != nullptr) {
			l = lista.obtenerNodoPorPosicion(HijoIzquierdo(i));
			r = lista.obtenerNodoPorPosicion(HijoDerecho(i));
			if (this->tipo == 2) {
				std::cout << "Se compara " << i << " con " << HijoIzquierdo(i) << "\n\n";
				if (HijoIzquierdo(i) < lista.getSize() && l->dato < tmp->dato) {
					val = l->dato;
					l->dato = tmp->dato;
					tmp->dato = val;
					Heapify();
				}
				std::cout << "Se compara " << i << " con " << HijoDerecho(i) << "\n\n";
				if (HijoDerecho(i) < lista.getSize() && r->dato < tmp->dato) {
					val = r->dato;
					r->dato = tmp->dato;
					tmp->dato = val;
					Heapify();
				}
			}
			else {
				if (HijoIzquierdo(i) < lista.getSize() && l->dato > tmp->dato) {
					val = l->dato;
					l->dato = tmp->dato;
					tmp->dato = val;
					Heapify();
				}
				if (HijoDerecho(i) < lista.getSize() && r->dato > tmp->dato) {
					val = r->dato;
					r->dato = tmp->dato;
					tmp->dato = val;
					Heapify();
				}
			}
			i--;
			tmp = tmp->anterior;
		}
	}


};

