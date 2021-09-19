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

	/*bool listaVacia();
	bool agregaFinal(T*);
	string imprimir();
	void borrarTodo();
	~listaGenerica();
	int getSize();*/


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

	
//
//
//template<class T>
//bool listaGenerica<T>::agregaFinal(T* dato)
//{
//	nodo<T>* _nodo = new nodo<T>(dato);
//	nodo<T>* temp = primero;
//
//	if (vacio())
//	{
//		primero = _nodo;
//	}
//	else
//	{
//		while (temp->getSig())
//		{
//			temp = temp->getSig();
//		}
//		temp->setSig(_nodo);
//	}
//	size++;
//	return true;
//}
//
////--------------------------------------------
//template<class T>
//string listaGenerica<T>::toString()
//{
//	nodo<T>* temp = primero;
//	stringstream s;
//	int i = 1;
//
//	while (temp)
//	{
//		s << i << " - ";
//		s << temp->getElemento()->toString() << endl;
//		temp = temp->getSig();
//		i++;
//	}
//	return s.str();
//}
//
////--------------------------------------------
//template<class T>
//listaGenerica<T>::~listaGenerica()
//{
//	borrarTodo();
//}
//
////--------------------------------------------
//template<class T>
//void listaGenerica<T>::borrarTodo()
//{
//
//	nodo<T>* temp = primero;
//	size = 0;
//	while (temp != NULL)
//	{
//		temp = primero;
//		primero = primero->getSig();
//		delete temp;
//	}
//}
////--------------------------------------------------------------
//
//
//template<class T>
//T* listaGenerica<T>::operator[](int indice) {
//	T* dato;
//	nodo<T>* temp = primero;
//	int i = 0;
//
//	if (indice > size)
//	{
//		return NULL;
//	}
//	while (i < indice) {
//		temp = temp->getSig();
//		i++;
//	}
//
//	dato = temp->getElemento();
//	return dato;
//}
//
//template<class T>
//int listaGenerica<T>::getSize() {
//	return size;
//}
};
