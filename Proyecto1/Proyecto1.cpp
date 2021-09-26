#include <iostream>
#include "ListaDoblementeEnlazada.h"


//Declaracion de los metodos Mostrar, unicamente para pruebas de la lista
void MostrarIzquierdaADerecha(const ListaDoblementeEnlazada<int>&);
void MostrarDerechaAIzquierda(const ListaDoblementeEnlazada<int>&);

int main()
{

	//Creando lista doble de tipo int y probandola con distintos valores
    ListaDoblementeEnlazada<int> li;


    li.Insertar(1);
	li.Insertar(2);
	li.Insertar(3);
	li.Insertar(4);
	li.Insertar(5);


	MostrarIzquierdaADerecha(li);
	MostrarDerechaAIzquierda(li);

	//Probando metodo para intercambiar nodos
	int p1, p2;
	while (true) {
		std::cout << "\nPrimera posicion: ";
		std::cin >> p1;
		std::cout << "\nSegunda posicion: ";
		std::cin >> p2;
		li.intercambiarNodos(li.obtenerNodoPorPosicion(p1), li.obtenerNodoPorPosicion(p2));
		MostrarIzquierdaADerecha(li);

		//Problema con los nodos anteriores
		MostrarDerechaAIzquierda(li);
	}

	return 0;
}

//Metodo mostrar de izquierda a derecha
void MostrarIzquierdaADerecha(const ListaDoblementeEnlazada<int>& lista) {
	ListaDoblementeEnlazada<int>::listaptr tmp;
	tmp = lista.getInicio();
	while (tmp != nullptr) {
		std::cout << tmp->dato << " ";
		tmp = tmp->siguiente;
	}
	std::cout << "\n\n";
}

//Metodo mostrar de derecha a izquierda
void MostrarDerechaAIzquierda(const ListaDoblementeEnlazada<int>& lista) {
	ListaDoblementeEnlazada<int>::listaptr tmp;
	tmp = lista.getFinal();
	while (tmp != nullptr) {
		std::cout << tmp->dato << " ";
		tmp = tmp->anterior;
	}
	std::cout << "\n\n";
}