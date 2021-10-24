#pragma once
//Cola de prioridad generica que administra operaciones ejecutables 
//a los objetos contenidos en esta 
template<class T> class ColaDePrioridad{

private:

#pragma once
	//Clase Heap basada en una lista doblemente enlazada
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
			
			//Metodos basicos de la construccion
			bool vacia() {
				return (inicio == NULL);
			}
			
			//retorna el primer nodo de la lista
			Nodo* getPrimero() {
				return inicio;
			}

			Nodo* getPrimero() const {
				return inicio;
			}
			
			//retorna el ultimo nodo de la lista
			Nodo* getUltimo() {
				return final;
			}

			Nodo* getUltimo() const {
				return final;
			}
			
			//retorna el tamano de la lista
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
				if (tmp->siguiente == nullptr) {
					delete tmp;
					inicio = nullptr;
					final = nullptr;
				}
				else {
					while (tmp2->siguiente != nullptr) {
						tmp = tmp->siguiente;
						tmp2 = tmp2->siguiente;
					}
					tmp->siguiente = nullptr;
					delete tmp2;
					final = tmp;
					size--;
				}
			}
			
			//Metodo que recibe una lista doblemente enlazada y la copia para agregarla al Heap
			void copiaLista(const ListaDoblementeEnlazada<T>& l2) {
				listaptr tmp = inicio;
				listaptr tmp2 = l2.inicio;
				while (tmp2 != nullptr) {
					this->Insertar(tmp2->dato);
					tmp2 = tmp2->siguiente;
				}
			}

		public:
			
			//Forma utlizada para ocultar el nodo
			typedef Nodo* listaptr;
			
			// Uso de wrappers para la encapsulacion de los metodos de la lista
			ListaDoblementeEnlazada() {
				Inicializar();
			}
			
			//Copia una lista y la agrega al Heap
			void ListaCopia(const ListaDoblementeEnlazada<T>& l2) {
				copiaLista(l2);
			}
			
			//Devuelve un valor booleano dependiendo del estado de la lista
			bool listaVacia() {
				return vacia();
			}

			//Devuelve el primer nodo de la lista doblemente enlazada
			listaptr getInicio() {
				return getPrimero();
			}

			
			listaptr getInicio() const {
				return getPrimero();
			}

			//Devuelve el ultimo nodo de la lista doblemente enlazada
			listaptr getFinal() {
				return getUltimo();
			}

			listaptr getFinal() const {
				return getUltimo();
			}

			//Devuelve el tamano de la lista doblemente enlazada
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

		//Metodo que crea un nuevo Heap a partir de que recibe una lista doblemente enlazada y un entero 
		//que dependiendo su valor permitira trabajar con un MaxHeap o MinHeap
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
					if (tipo == 2) {
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
		
		//Metodo que retorna y elimina el elemento que esta en el tope del Heap
		T EliminarHeap() {
			typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
			Nodoptr inicio = this->lista.getInicio();
			Nodoptr final = this->lista.getFinal();
			T aux = inicio->dato;
			//std::cout << "\nELIMINAR HEAP\n";

			this->lista.intercambiar(1, lista.getSize());
			this->lista.EliminarUltimo();

			//MostrarHeap();

			//crearHeap(this->lista, tipo);
			Heapify();
			return aux;
		}
		
		//Metodo para imprimir el contenido del heap
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
			this->MostrarHeap();
			typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
			Nodoptr tmp, l, r;
			tmp = lista.getFinal();
			int i = this->lista.getSize();
			T val;
			while (i > 0 && tmp != nullptr) {
				l = lista.obtenerNodoPorPosicion(HijoIzquierdo(i));
				r = lista.obtenerNodoPorPosicion(HijoDerecho(i));
				if (this->tipo == 2) {
					//std::cout << "Se compara " << i <<" con " << HijoIzquierdo(i) << "\n\n";
					if (HijoIzquierdo(i) <= lista.getSize() && l->dato < tmp->dato) {
						//std::cout << "Se hace el intercambio \n";
						val = l->dato;
						l->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
					//std::cout << "Se compara " << i << " con " << HijoDerecho(i) << "\n\n";
					if (HijoDerecho(i) <= lista.getSize() && r->dato < tmp->dato) {
						//std::cout << "Se hace el intercambio \n";
						val = r->dato;
						r->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
				}
				else {
					if (HijoIzquierdo(i) <= lista.getSize() && l->dato > tmp->dato) {
						val = l->dato;
						l->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
					if (HijoDerecho(i) <= lista.getSize() && r->dato > tmp->dato) {
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

		void CopiaHeap(const Heap<T>& h) {
			this->tipo = h.tipo;
			lista.ListaCopia(h.lista);
		}

	public:
		//Metodos wrapper del heap
		//Metodo que crea e inizializa el heap 
			Inicializar();
		}

		//Constructor de copia de la clase Heap
		void HeapCopia(const Heap<T>& h) {
			CopiaHeap(h);
		}

		//Metodo que retorna la lista doblemente enlazada con la que se esta trabajando
		ListaDoblementeEnlazada<T> getLista() {
			return getListaHeap();
		}

		//Crea el Heap de acuerdo a las preferencias del usuario (MaxHeap/MinHeap) 
		ListaDoblementeEnlazada<T> crearHeap(ListaDoblementeEnlazada<T> list, int opcion) {
			return nuevoHeap(list, opcion);
		}

		//Metodo que retorna y elimina el elemento que esta en el tope del Heap
		T Eliminar() {
			return EliminarHeap();
		}

		//Metodo para imprimir el contenido del Heap
		void MostrarHeap() {
			PrintHeap();
		}

		//Metodo que agrega un elemento en el Heap
		void Insertar(const T& t) {
			InsertarHeap(t);
		}

		//Metodo que ayuda a menatener la propiedad del Heap como tal
		void Heapify() {
			HeapifyPriv();
		}

	};

	Heap<T> heap;

public:
	//Constructor por defecto de la cola de prioridad
	ColaDePrioridad() {
	}
	
	//Constructor de copia de la cola de prioridad
	ColaDePrioridad(const ColaDePrioridad& colaHecha){
		heap.HeapCopia(colaHecha.heap);
	}

	//Metodo que determina (segun las preferencias del usuario) si la cola va a 
	//trabajar/darle prioridad a elementos maximos o minimos (MaxHeap/MinHeap)
	void crearColaDePrioridad() {
		int n;
		std::cout<<"Digite (1) si desea que la cola de prioridad trabaje con elementos maximos o (2) con minimos: ";
		std::cin >> n;
		heap.crearHeap(heap.getLista(), n);
	}

	//Metodo que agrega un elemento a la cola de prioridad
	void Insertar(const T& val) {
		heap.Insertar(val);
	}

	//Metodo que devuelve y elimina el objeto que se encuentra en el tope de la cola de prioridad
	T Pop() {
		return heap.Eliminar();
	}

	//Metodo que muestra los elementos que se encuentran contenidos dentro de la cola de prioridad
	void MostrarCola() {
		heap.MostrarHeap();
	}
	
	//*Podriamos eliminar este metodo*
	//Metodo que devuele el tamano 
	//de la cola de prioridad (de acuerdo a los objetos contenidos en esta)
	int getSize() {
		return heap.getLista().getSize();
	}
	
	//Metodo que retorna verdadero si la cola de prioridad se encuentra vacia
	bool colaVacia()
	{
		return heap.getLista().listaVacia();	
	}
};

