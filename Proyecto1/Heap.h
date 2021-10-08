#pragma once

template<class T> class Heap {
private:

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

		Nodo* getUltimo() {
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

	//HEAP PRIVADO

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

	//METODOS HEAP PRIVADO
	ListaDoblementeEnlazada<T> getListaHeap() {
		return lista;
	}

	ListaDoblementeEnlazada<T> nuevoHeap(ListaDoblementeEnlazada<T> list, int opcion) {
		ListaDoblementeEnlazada<T> listad = list;
		this->tipo = opcion;
		//std::cout << "Entra al metodo MaxHeap\n";
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr tmp;
		if (list.getInicio() != nullptr) {
			tmp = list.getInicio()->siguiente;
			int i = 2;
			while (tmp != nullptr && i <= list.getSize()) {
				Nodoptr hijo = list.obtenerNodoPorPosicion(i);
				Nodoptr padre = list.obtenerNodoPorPosicion(Padre(i));
				//std::cout << i << "(" << hijo->dato << ") > " << Padre(i) << "(" << padre->dato << ")?";
				if (opcion == 2) {
					if (hijo->dato < padre->dato) {
						//std::cout << " R/Si\n";
						list.intercambiar(Padre(i), i);
						//std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
						//MostrarIzquierdaADerecha(lista);
						//MostrarDerechaAIzquierda(lista);
						listad = this->crearHeap(list, 1);
						return listad;
					}
				}
				else {
					if (hijo->dato > padre->dato) {
						//std::cout << " R/Si\n";
						//lista.intercambiarNodos(lista.obtenerNodoPorPosicion(Padre(i)), lista.obtenerNodoPorPosicion(i));
						list.intercambiar(Padre(i), i);
						//std::cout << "Se intercambia " << Padre(i) << " con " << i << "\n\n";
						//MostrarIzquierdaADerecha(lista);
						//MostrarDerechaAIzquierda(lista);
						listad = this->crearHeap(list, 1);
						return listad;
					}
				}

				i++;
				tmp = tmp->siguiente;
			}
		}

		this->lista = listad;
		return listad;
	}

	void EliminarHeap() {
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

	void PrintHeap() {
		typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
		Nodoptr tmp;
		tmp = lista.getInicio();
		while (tmp != nullptr) {
			std::cout << tmp->dato << " ";
			tmp = tmp->siguiente;
		}
		std::cout << "\n\n";
	}

	void InsertarHeap(const T& t) {
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

	void HeapifyPriv() {
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

public:

	Heap() {
		Inicializar();
	}

	ListaDoblementeEnlazada<T> getLista() {
		return getListaHeap();
	}

	ListaDoblementeEnlazada<T> crearHeap(ListaDoblementeEnlazada<T> list, int opcion) {
		return nuevoHeap(list, opcion);
	}

	void Eliminar() {
		EliminarHeap();
	}

	void MostrarHeap() {
		PrintHeap();
	}

	void Insertar(const T& t) {
		InsertarHeap(t);
	}

	void Heapify() {
		HeapifyPriv();
	}

};

