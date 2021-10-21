#pragma once
//Uso de templates
template<class T> class ColaDePrioridad{

private:

#pragma once

	template<class T> class Heap {
	private:
		//Instancia la lista doblementente enlazada con su nodo y sus atributos
		template<class T> class ListaDoblementeEnlazada {

		private:
			//Creando el nodo de la lista doblemente enlazada 
			struct Nodo {
				T dato;
				Nodo* siguiente;
				Nodo* anterior;
				Nodo(T d, Nodo* sig = nullptr, Nodo* ant = nullptr) : dato{ d }, siguiente{ sig }, anterior{ ant } {}
			};

			Nodo* inicio;
			Nodo* final;
			int size;
			//Inicializando Heap
			void Inicializar() { inicio = nullptr; final = nullptr; size = 0; }
			//Metodos basico de la contruccion
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
			//Este metodo retorna el valor del nodo por posicion
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
				return nullptr;
			}

			//Metodo utilizado para intercambiar los datos de los nodos por medio de las posiciones
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
					T& aux = nodo1->dato;
					nodo1->dato = nodo2->dato;
					nodo2->dato = aux;
				}
			}

			//Metodo utilizado para insertar un nodo, si el inicio esta vacio, 
			//lo inserta en la primera posicion y si no se cumple esta condicion,
			//lo inserta en el siguiente
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

			//Metodo se encarga de eliminar el ultimo nodo del Heap por modelo 
			//de dos punteros temporales
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
			//Forma utlizada para ocultar el nodo
			typedef Nodo* listaptr;

			// Uso de wrappers para la encapsulacion de los metodos de la lista
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

			//Metodo que intercambia las posiciones
			void intercambiar(int pos1, int pos2) {
				intercambiarDatoPorPosiciones(pos1, pos2);
			}

			//Metodo que inserta valores
			void Insertar(const T& val) {
				InsertarNodo(val);
			}

			//Metodo que elimina el ultimo nodo
			void EliminarUltimo() {
				EliminarUltimoNodo();
			}

		};

		//HEAP PRIVADO

		ListaDoblementeEnlazada<T> lista;
		int tipo;
		//Valor del nodo padre
		int Padre(int i) {
			return i / 2;
		}

		//Valor del nodo hijo izquierdo
		int HijoIzquierdo(int i) {
			return 2 * i;
		}

		//Valor del nodo hijo derecho
		int HijoDerecho(int i) {
			return (2 * i) + 1;
		}

		//Metodo inizializador para el Heap privado
		void Inicializar() {
			tipo = 1;
		}

		//METODOS HEAP PRIVADO
		//Retorna la lista que esta instanciada en el heap
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

		//Metodo para eliminar todo el heap
		void EliminarHeap() {
			typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
			Nodoptr inicio = this->lista.getInicio();
			Nodoptr final = this->lista.getFinal();
			//std::cout << "\nELIMINAR HEAP\n";

			this->lista.intercambiar(1, lista.getSize());
			this->lista.EliminarUltimo();

			//MostrarHeap();

			//crearHeap(this->lista, tipo);
			Heapify();
		}

		//Metodo para imprimir el heap
		void PrintHeap() {
			typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
			Nodoptr tmp;
			tmp = lista.getInicio();
			while (tmp != nullptr) {
				std::cout << tmp->dato;
				tmp = tmp->siguiente;
			}
			std::cout << "\n\n";
		}

		//Metodo que inserta valores en el heap
		void InsertarHeap(const T& t) {
			//std::cout << "\nINSERTAR HEAP\n";
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

		//Metodo para mantener la propiedad del nodo de forma recursiva
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
					//std::cout << "Se compara " << i << " con " << HijoIzquierdo(i) << "\n\n";
					if (HijoIzquierdo(i) < lista.getSize() && l->dato < tmp->dato) {
						val = l->dato;
						l->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
					//std::cout << "Se compara " << i << " con " << HijoDerecho(i) << "\n\n";
					if (HijoDerecho(i) < lista.getSize() && r->dato < tmp->dato) {
						val = r->dato;
						r->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
				}
				else {
					if (HijoIzquierdo(i) < lista.getSize() && l->dato > tmp->dato) {
						val = l->dato;
						l->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
					if (HijoDerecho(i) < lista.getSize() && r->dato > tmp->dato) {
						val = r->dato;
						r->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
				}
				i--;
				tmp = tmp->anterior;
			}
		}

	public:

		//Metodos wrapper del heap
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

	Heap<T> heap;

public:

	ColaDePrioridad() {
	}

	void crearColaDePrioridad() {
		int n;
		//std::cout<<"Digite (1) si desea que la cola de prioridad trabaje con elementos maximos o (2) con minimos: ";
		std::cout << "Digite (1) si desea trabajar con la lista de pacientes que necesiten ser atendidos con urgencia\n"; 
		std::cout << "o (2) si desea trabajar  con la lista de pacientes cuya situacion no sea prioritaria: ";
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
		return heap.getLista().getSize();
	}
};

