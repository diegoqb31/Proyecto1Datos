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

	listaptr getInicio() const {
		return inicio;
	}

	listaptr getFinal() {
		return final;
	}

	listaptr getFinal() const {
		return final;
	}

	int getSize() {
		return size;
	}

	//Metodo que obtiene el nodo de la lista por posicion
	Nodo* obtenerNodoPorPosicion(int pos) {
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

	//Metodo que intercambia nodos de la lista doble, (Dibujen la lista porque no van a entender ni madre xd)
	//SOLUCION TEMPORAL, cambiar por algo mas eficiente
	void intercambiarNodos(Nodo* n1, Nodo* n2) {
		Nodo* s1 = n1->siguiente;
		Nodo* a1 = n1->anterior;
		Nodo* s2 = n2->siguiente;
		Nodo* a2 = n2->anterior;

		if (inicio == nullptr) {
			std::cout << "Imposible realizar el intercambio";
		}

		else {

			struct Nodo* primero = inicio;
			if (primero == n1) {
				n2->siguiente = s1;
				n1->siguiente = s2;
				inicio = n2;
			}
			if (primero == n2) {
				n1->siguiente = s2;
				n2->siguiente = s1;
				inicio = n1;
			}

			struct Nodo* tmp = inicio;
			while (tmp != nullptr) {
				if (tmp->siguiente == n1) {
					if (n1->siguiente == s2) {
						tmp->siguiente = n2;
					}
					else {
						tmp->siguiente = n2;
						n2->siguiente = s1;
						n1->siguiente = s2;
					}
				}
				else {
					if (tmp->siguiente == n2) {
						if (n2->siguiente == s1) {
							tmp->siguiente = n1;
						}
						else {
							tmp->siguiente = n1;
							n1->siguiente = s2;
							n2->siguiente = s1;
						}
					}
				}
				tmp = tmp->siguiente;
			}
		}
		struct Nodo* ultimo = final;
		if (ultimo == n1) {
			n2->anterior = a1;
			n1->anterior = a2;
			final = n2;
		}
		if (ultimo == n2) {
			n1->anterior = a2;
			n2->anterior = a1;
			final = n1;
		}

		struct Nodo* tmp = final;
		while (tmp != nullptr) {

			if (tmp->anterior == n1) {
				if (n1->anterior == a2) {
					tmp->anterior = n2;
				}
				else {
					tmp->anterior = n2;
					n2->anterior = a1;
					n1->anterior = a2;
				}
			}
			else {
				if (tmp->anterior == n2) {
					if (n2->anterior == a1) {
						tmp->anterior = n1;
					}
					else {
						tmp->anterior = n1;
						n1->anterior = a2;
						n2->anterior = a1;
					}
				}
			}
			tmp = tmp->anterior;
		}

	}



	void Insertar(const T& val) {
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

	void EliminarUltimo() {
		listaptr tmp = inicio;
		listaptr tmp2 = inicio->siguiente;
		while (tmp2->siguiente != nullptr) {
			tmp = tmp->siguiente;
			tmp2 = tmp2->siguiente;
		}
		tmp->siguiente = nullptr;
		delete tmp2;
		final = tmp;
	}


};
