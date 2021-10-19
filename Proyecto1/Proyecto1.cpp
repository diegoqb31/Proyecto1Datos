#include <iostream>
#include "Heap.h"
#include "ColaDePrioridad.h"
#include "Paciente.h"

int main()
{


	/*Heap<int> hp;
	hp.crearHeap(hp.getLista(), 1);

	hp.MostrarHeap();

	hp.Insertar(11);
	hp.Insertar(5);
	hp.Insertar(6);
	hp.Insertar(15);
	hp.MostrarHeap();

	hp.Eliminar();
	hp.MostrarHeap();

	hp.Heapify();
	hp.MostrarHeap();*/

	ColaDePrioridad<Paciente> cola;
	cola.crearColaDePrioridad();


	cola.Insertar(*(new Paciente("Diego", 100)));
	cola.Insertar(*(new Paciente("Kevin", 200)));
	cola.Insertar(*(new Paciente("Jairo", 150)));
	cola.Insertar(*(new Paciente("Tigre", 300)));
	cola.Insertar(*(new Paciente("Pablo", 400)));
	cola.MostrarCola();
	cola.Eliminar();
	cola.MostrarCola();

	return 0;
}
