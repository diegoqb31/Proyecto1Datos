#pragma once
#include<iostream>

template<class T> class ListaDoblementeEnlazada {

private:

	struct Nodo {
		T dato;
		Nodo* siguiente;
		Nodo* anterior;
		Nodo(T d, Nodo* sig = nullptr, Nodo* ant = nullptr) : dato{ d }, siguiente{ sig }, anterior{ ant } {}
	};

	Nodo* inicio;
	Nodo* final;
	int size;

	void Inicializar() { inicio = nullptr; final = nullptr; size = 0; }

	bool vacia() {
		return (inicio == NULL);
	}

	Nodo* getPrimero() {
		return inicio;
	}

	Nodo* getPrimero() const {
		return inicio;
	}

	Nodo* getUltimo(){
		return final;
	}

	Nodo* getUltimo() const {
		return final;
	}

	int getTamano() {
		return size;
	}

	Nodo* obtenerPorPosicion(int pos) {
		int i = 1;
		if (inicio == nullptr) {
			return nullptr;
		}
		else {
			struct Nodo* tmp = inicio;
			while (tmp != nullptr) {
				if (i == pos) {
					return tmp;
				}
				i++;
				tmp = tmp->siguiente;
			}
		}

	}

	void intercambiarDatoPorPosiciones(int pos1, int pos2) {
		if (pos1 <= this->getSize() && pos2 <= this->getSize()) {
			listaptr nodo1 = this->getInicio();
			for (int f = 1; f < pos1; f++) {
				nodo1 = nodo1->siguiente;
			}
			listaptr nodo2 = this->getInicio();
			for (int f = 1; f < pos2; f++) {
				nodo2 = nodo2->siguiente;
			}
			int aux = nodo1->dato;
			nodo1->dato = nodo2->dato;
			nodo2->dato = aux;
		}
	}

	void InsertarNodo(const T& val) {
		listaptr nuevo;
		try {
			nuevo = new Nodo(val);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		if (inicio == nullptr)
			inicio = nuevo;
		else {
			listaptr tmp = inicio;
			while (tmp->siguiente != nullptr)
				tmp = tmp->siguiente;
			tmp->siguiente = nuevo;
			nuevo->anterior = tmp;
			final = nuevo;
		}
		size++;
	}

	void EliminarUltimoNodo() {
		listaptr tmp = inicio;
		listaptr tmp2 = tmp->siguiente;
		while (tmp2->siguiente != nullptr) {
			tmp = tmp->siguiente;
			tmp2 = tmp2->siguiente;
		}
		tmp->siguiente = nullptr;
		delete tmp2;
		final = tmp;
		size--;
	}

public:

	typedef Nodo* listaptr;

	ListaDoblementeEnlazada() {
		Inicializar();
	}

	bool listaVacia() {
		return vacia();
	}

	listaptr getInicio() {
		return getPrimero();
	}

	listaptr getInicio() const {
		return getPrimero();
	}

	listaptr getFinal() {
		return getUltimo();
	}

	listaptr getFinal() const {
		return getUltimo();
	}

	int getSize() {
		return getTamano();
	}

	//Metodo que obtiene el nodo de la lista por posicion
	listaptr obtenerNodoPorPosicion(int pos) {
		return obtenerPorPosicion(pos);

	}

	void intercambiar(int pos1, int pos2) {
		intercambiarDatoPorPosiciones(pos1, pos2);
	}

	void Insertar(const T& val) {
		InsertarNodo(val);
	}

	void EliminarUltimo() {
		EliminarUltimoNodo();
	}

};
