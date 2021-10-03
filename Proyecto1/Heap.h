#pragma once
#include <iostream>
#include <list>

template<class T> class Heap {

private:

	std::list<T> lista;
	int id;

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

	}

	std::list<T> MaxHeap(std::list<T> lista) {
		std::list<T> listad = lista;
		std::cout << "Entra al metodo MaxHeap\n";
		typedef std::list<T>::iterator iterador;
		iterador iter, hijo = lista.begin(), padre = lista.begin(), aux = lista.begin(), aux2;
		T val;
		int i = 1;
		for (iter = lista.begin(); iter != lista.end(); iter++) {
			if (i <= lista.size()) {
				//std::cout << "\nSize:" << lista.size() << "\n";
				if (i == 1) {
					i++;
				}
				std::advance(hijo, i - 1);
				std::advance(padre, Padre(i) - 1);
				std::cout << i << "(" << *hijo << ") > " << Padre(i) << "(" << *padre << ")?";
				if (*hijo > *padre) {
					std::cout << " R/Si\n";
					val = *hijo;
					*hijo = *padre;
					*padre = val;
					std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
					MostrarHeapParametro(lista);

					listad = this->MaxHeap(lista);
					return listad;
				}
				else {
					std::cout << " R/No\n";
				}
				hijo = aux;
				padre = aux;
				i++;
			}

		}
		this->lista = listad;
		return listad;
	}


	std::list<T> MinHeap(std::list<T> lista) {
		std::list<T> listad = lista;
		std::cout << "Entra al metodo MinHeap\n";
		typedef std::list<T>::iterator iterador;
		iterador iter, hijo = lista.begin(), padre = lista.begin(), aux = lista.begin(), aux2;
		T val;
		int i = 1;
		for (iter = lista.begin(); iter != lista.end(); iter++) {
			if (i <= lista.size()) {
				//std::cout << "\nSize:" << lista.size() << "\n";
				if (i == 1) {
					i++;
				}
				std::advance(hijo, i - 1);
				std::advance(padre, Padre(i) - 1);
				std::cout << i << "(" << *hijo << ") > " << Padre(i) << "(" << *padre << ")?";
				if (*hijo < *padre) {
					std::cout << " R/Si\n";
					val = *hijo;
					*hijo = *padre;
					*padre = val;
					std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
					MostrarHeapParametro(lista);

					listad = this->MinHeap(lista);
					return listad;
				}
				else {
					std::cout << " R/No\n";
				}
				hijo = aux;
				padre = aux;
				i++;
			}

		}
		this->lista = listad;
		return listad;
	}

	void EliminarMaxHeap() {
		typedef std::list<T>::iterator iterador;
		iterador primero = lista.begin();
		iterador ultimo = lista.begin();
		std::advance(ultimo, lista.size() - 1);
		T val;
		std::cout << "\nEliminar:\n";
		val = *ultimo;
		*ultimo = *primero;
		*primero = val;
		lista.pop_back();
		MostrarHeap();
		MaxHeap(lista);
	}

	void EliminarMinHeap() {
		typedef std::list<T>::iterator iterador;
		iterador primero = lista.begin();
		iterador ultimo = lista.begin();
		std::advance(ultimo, lista.size() - 1);
		T val;
		std::cout << "\nEliminar:\n";
		val = *ultimo;
		*ultimo = *primero;
		*primero = val;
		lista.pop_back();
		MostrarHeap();
		MinHeap(lista);
	}

	void InsertarMaxHeap(const T& t) {

		this->lista.push_back(t);

		typedef std::list<T>::iterator iterador;
		iterador iter, ultimo = lista.begin(), hijo = lista.begin(), padre = lista.begin();
		int i = lista.size();
		T val;

		while (i >= 1 && Padre(i) > 0) {

			std::advance(hijo, i - 1);
			std::advance(padre, Padre(i) - 1);
			
			std::cout << "Se compara " << Padre(i) << " con " << i << "\n\n";
			if (*hijo > *padre) {
				val = *hijo;
				*hijo = *padre;
				*padre = val;
			}
			MostrarHeap();
			std::cout <<"\n";
			i = Padre(i);
			hijo = lista.begin();
			padre = lista.begin();
		}
	}

	void Insertar(const T& val) {
		this->lista.push_back(val);
	}

	void MostrarHeap() {
		typedef std::list<T>::iterator iterador;
		iterador iter;
		for (iter = this->lista.begin(); iter != this->lista.end(); iter++) {
			std::cout << *iter << " ";
		}
	}

	void MostrarHeapParametro(std::list<T> l) {
		typedef std::list<T>::iterator iterador;
		iterador iter;
		for (iter = l.begin(); iter != l.end(); iter++) {
			std::cout << *iter << " ";
		}
		std::cout << "\n\n";
	}

	void Heapify() {

	}

};

