#include <iostream>
//#include "ColaDePrioridad.h"
//#include "Paciente.h"
#include "MenuPrincipal.h"
int main()
{
	MenuPrincipal menu;
	menu.mostrar();

	/*
	//Se instancia la cola de priridad
	ColaDePrioridad<Paciente> cola;

	std::cout << "Bienvenido al sistema de atencion de urgencias\n";
	std::cout << "Por aca puede elegir el orden en el que seran atendidos los pacientes segun la gravedad de su padecimiento:\n";
	cola.crearColaDePrioridad();

	//Se crean los objetos Paciente que seran evaluados
	int resp = 0;
	cola.Insertar(*(new Paciente("Diego", 100)));
	cola.Insertar(*(new Paciente("Kevin", 200)));
	cola.Insertar(*(new Paciente("Jairo", 150)));
	cola.Insertar(*(new Paciente("Tigre", 300)));
	cola.Insertar(*(new Paciente("Pablo", 400)));

	//Proceso de atencion de pacientes
	while (true)
	{
		std::cout << "Esta es la lista de pacientes segun la atencion requerida:\n";

		//Muestra a los pacientes disponibles segun sea su prioridad de atencion
		cola.MostrarCola();
		/*if (cola.getSize() == 1)
		{
			std::cout << "Ya no quedan pacientes por atender, lista vacia \n";
			break;
		}*/
		//Se elimina a un paciente de la lista que ya ha sido atendido
		/*cola.Eliminar();
		std::cout << "Ahora el paciente que estaba de primero en la cola ha sido atendido\n";
		std::cout << "Esta es la lista actualizada de pacientes segun prioridad de atencion:\n";
		cola.MostrarCola();
		std::cout << "Desea seguir atendiendo pacientes?: Digite 1 (SI) o 2 (NO)\n";
		std::cin >> resp;
		if (resp != 1)
			break;
	}*/

	return 0;
}
