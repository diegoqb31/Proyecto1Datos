#include <iostream>
#include "ListaDoblementeEnlazada.h"

void Mostrar(const ListaDoblementeEnlazada<int>&);

int main()
{
    ListaDoblementeEnlazada<int> li;

    li.InsertarInicio(1);
	li.InsertarInicio(2);
	li.InsertarInicio(3);
	li.InsertarInicio(4);
	li.InsertarInicio(5);
    Mostrar(li);

	return 0;
}

void Mostrar(const ListaDoblementeEnlazada<int>& lista) {
	ListaDoblementeEnlazada<int>::listaptr tmp;
	tmp = lista.getInicio();
	while (tmp != nullptr) {
		std::cout << tmp->dato << " ";
		tmp = tmp->siguiente;
	}
	std::cout << "\n\n";
}
