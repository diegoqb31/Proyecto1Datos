#pragma once
//Cola de prioridad generica que administra operaciones ejecutables 
//a los objetos contenidos en esta 
template<class T> class ColaDePrioridad{

private:

	//Clase Heap basada en una lista doblemente enlazada
	template<class T> class Heap {
	private:
		//Se crea la lista doblementente enlazada con su nodo y sus atributos
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
			
			//Indica si la lista doblemente enlazada está vacía
			bool vacia() {
				return (inicio == nullptr);
			}
			
			//Metodos que retornan el primer nodo de la lista
			Nodo* getPrimero() {
				return inicio;
			}

			Nodo* getPrimero() const {
				return inicio;
			}
			
			//Metodos que retornan el ultimo nodo de la lista
			Nodo* getUltimo() {
				return final;
			}

			Nodo* getUltimo() const {
				return final;
			}
			
			//Retorna el tamaño de la lista
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
			//lo inserta en en el nodo que apunte a nullptr como siguiente
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
					size--;
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
			
			//Metodo que recibe una lista doblemente enlazada y la copia
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
			
			//Copia una lista
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

		//Parte privada del Heap

		ListaDoblementeEnlazada<T> lista;
		int tipo;
		
		//Posición del nodo padre
		int Padre(int i) {
			return i / 2;
		}
		
		//Posición nodo hijo izquierdo
		int HijoIzquierdo(int i) {
			return 2 * i;
		}
		
		//Posición del nodo hijo derecho
		int HijoDerecho(int i) {
			return (2 * i) + 1;
		}
		
		//Metodo inizializador para el Heap privado
		void Inicializar() {
			tipo = 1;
		}

		//Retorna la lista que esta instanciada en el heap
		ListaDoblementeEnlazada<T> getListaHeap() {
			return lista;
		}

		//CrearHeap, Recibe por parámetro una lista doblemente enlazada y un entero
		//llamado opción, este entero indica el tipo de Heap con el que se trabajará,
		//si el entero es 1 se trabaja con MaxHeap y si es 2 se trabaja con MinHeap,
		//por defector se crea un MaxHeap. El metodo compara cada uno de los nodos padres 
		//con sus hijos para asegurarse de que se cumplen las propiedades y en caso de 
		//hacerse un intercambio de padre e hijo se llama recursivamente al metodo para 
		//volver a revisar la lista desde el incio. Se retorna una lista doblemente enlazada
		//con el fin de utilizarla recursivamente y al final asignarla al heap.
		ListaDoblementeEnlazada<T> nuevoHeap(ListaDoblementeEnlazada<T> list, int opcion) {
			ListaDoblementeEnlazada<T> listad = list;
			this->tipo = opcion;
			typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
			Nodoptr tmp;
			if (list.getInicio() != nullptr) {
				tmp = list.getInicio()->siguiente;
				int i = 2;
				while (tmp != nullptr && i <= list.getSize()) {
					Nodoptr hijo = list.obtenerNodoPorPosicion(i);
					Nodoptr padre = list.obtenerNodoPorPosicion(Padre(i));
					//MinHeap
					if (tipo == 2) {
						if (hijo->dato < padre->dato) {
							list.intercambiar(Padre(i), i);
							listad = this->nuevoHeap(list, 1);
							return listad;
						}
					}
					//MaxHeap
					else {
						if (hijo->dato > padre->dato) {
							list.intercambiar(Padre(i), i);
							listad = this->nuevoHeap(list, 1);
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
		
		//Metodo Eliminar, intercambia el primer elemento(el de maxima prioridad) con
		//el último y luego lo elimina, luego se utiliza el Heapify para mantener las
		//propiedades del heap. Se retorna el elemento eliminado con el fin de utilizarlo
		//en el pop de la cola de prioridad.
		T EliminarHeap() {
			typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
			Nodoptr inicio = this->lista.getInicio();
			Nodoptr final = this->lista.getFinal();
			T aux = inicio->dato;

			this->lista.intercambiar(1, lista.getSize());
			this->lista.EliminarUltimo();

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

		//Insertar, se inserta el elemento al final del Heap y para mantener
		//las propiedades se compara con sus padres en cadena, es decir, el nodo hijo
		//se compara con el padre y luego el hijo pasa a ser el padre para compararse
		//con su nuevo padre, así sucesivamente hasta que se cumplan las propiedades del Heap.
		void InsertarHeap(const T& t) {
			this->lista.Insertar(t);

			typedef ListaDoblementeEnlazada<T>::listaptr Nodoptr;
			Nodoptr nodoHijo, nodoPadre;
			int hijo = this->lista.getSize(), padre = Padre(hijo);
			T val;

			while (hijo != 0 && padre > 0) {

				nodoHijo = lista.obtenerNodoPorPosicion(hijo);
				nodoPadre = lista.obtenerNodoPorPosicion(padre);

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
			}
		}
		
		//Heapify, Metodo que se encarga de cumplir las propiedades del heap
		//este empieza por el último nodo comparandolo con sus hijos y así sucesivamente
		//hasta llegar al incio, en caso de haber alguna modificación se vuelve a llamar
		//recursivamente al método para volver al comprobar todo de nuevo, ya que hubieron
		//modificaciones que puedieron afectar las propiedades del Heap
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
					if (HijoIzquierdo(i) <= lista.getSize() && l->dato < tmp->dato) {
						val = l->dato;
						l->dato = tmp->dato;
						tmp->dato = val;
						HeapifyPriv();
					}
					if (HijoDerecho(i) <= lista.getSize() && r->dato < tmp->dato) {
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

		//Recibe un objeto tipo Heap y crea una copia de este,
		//además asigna el tipo de Heap con respecto al recibido
		void CopiaHeap(const Heap<T>& h) {
			this->tipo = h.tipo;
			lista.ListaCopia(h.lista);
		}

	public:
		//Metodos wrapper del heap
		//Metodo que crea e inizializa el heap 
		Heap(){
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
	//y en base a esto crea un nuevo Heap
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
	
	//Metodo que retorna verdadero si la cola de prioridad se encuentra vacia
	bool colaVacia()
	{
		return heap.getLista().listaVacia();	
	}
};

