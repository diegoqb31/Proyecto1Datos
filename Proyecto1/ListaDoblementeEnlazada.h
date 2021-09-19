#pragma once
#include<iostream>


template<class T> class ListaDoblementeEnlazada{

private:

	struct Nodo {
		T dato;
		Nodo* siguiente;
		Nodo* anterior;
		Nodo(T d, Nodo* sig = nullptr, Nodo* ant = nullptr) : dato{ d }, siguiente{ sig }, anterior{ant} {}
	};

	Nodo* inicio;
	Nodo* final;
	int size;

	void Inicializar() { inicio = nullptr; final = nullptr; size = 0; }

public:

	typedef Nodo* listaptr;



	ListaDoblementeEnlazada() {
		Inicializar();
	}

	bool listaVacia() {
		return (inicio == NULL);
	}

	listaptr getInicio() {
		return inicio;
	}

	listaptr getInicio() const{
		return inicio;
	}

	listaptr getFinal() {
		return final;
	}

	listaptr getFinal() const{
		return final;
	}

	void InsertarInicio(const T& val) {
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
			nuevo->siguiente = tmp;
			tmp->anterior = nuevo;
			inicio = nuevo;
		}
	}


};
