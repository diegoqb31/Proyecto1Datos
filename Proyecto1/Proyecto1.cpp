#include <iostream>
#include "ColaDePrioridad.h"
#include "Paciente.h"

int main()
{

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
