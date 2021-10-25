#pragma once
#include "Paciente.h"
#include "ColaDePrioridad.h"
//Menu principal donde se ejecutan todas las operaciones referentes a la gestion de pacientes 
class MenuPrincipal
{
private:
	ColaDePrioridad<Paciente> cola;
	Paciente paciente;

public:

	//Metodo con switch que ejecuta las opciones de acuerdo a la seleccion del usuario
	void mostrar()
	{
		const int opcionSalida = 5;
		int opcion;
		creacionCola();
		do {

			opcion = mostrarOpciones();
			switch (opcion)
			{
			case 1:
				this->crearPaciente();
				break;
			case 2:
				this->muestraPacientes();
				break;
			case 3:
				this->atiendePaciente();
				break;
			case 4:
				this->probarConstructorDeCopia();
				break;
			case opcionSalida:
				break;
			default:
				cout << "Opcion invalida, digite una opcion nuevamente" << endl;
			}
			system("pause");
		} while (opcion != opcionSalida);

	}

private:

	//Metodo que crea la cola de prioridad
	void creacionCola()
	{
		cout << "================================================\n";
		cout << " Bienvenido al sistema de atencion de urgencias\n";
		cout << "================================================\n";
		std::cout << "Por aca puede elegir el orden en el que seran atendidos los pacientes segun la gravedad de su padecimiento:\n";
		cola.crearColaDePrioridad();
	}

	//Metodo que muestra las opciones del menu
	int mostrarOpciones()
	{
		int opcion;
		system("cls");
		cout << "================================================\n";
		cout << "      Digite la opcion que desee ejecutar\n";
		cout << "================================================\n";
		cout << "[1] Agregar pacientes al sistema \n";
		cout << "[2] Consultar la lista de pacientes disponibles \n";
		cout << "[3] Atender a un paciente \n";
		cout << "[4] Probar constructor de copia \n";
		cout << "[5] Salir \n";
		cout << "================================================\n";
		cin >> opcion;
		system("cls");

		return opcion;
	}

	//Metodo que crea un objeto paciente de acuerdo a los datos dados por el usuario
	void crearPaciente()
	{
		std::string nombre;
		int gravedad;

		cout << "================================================\n";
		cout << "		 Nuevo Paciente\n";
		cout << "================================================\n";
		std::cout << "Ingrese el nombre del Paciente\n";
		std::cin >> nombre;
		std::cout << "Ingrese el grado de gravedad de la salud del paciente\n";
		std::cin >> gravedad;

		cola.Insertar(*(new Paciente(nombre, gravedad)));
	}


	//Muestra la cola de pacientes que esperan ser atendidos
	void muestraPacientes()
	{
		cout << "================================================\n";
		cout << "              Lista de Pacientes\n";
		cout << "================================================\n";
		if (cola.colaVacia()) {
			std::cout << "La lista esta vacia \n";
		}
		else {
			cola.MostrarCola();
		}
		
	}


	//Metodo que ejecuta la atencion de pacientes, 
	//una vez que los "atiende" los elimina de la cola 
	void atiendePaciente()
	{
		cout << "================================================\n";
		cout << "	       Atender Paciente\n";
		cout << "================================================\n";
		if (cola.colaVacia()) {
			std::cout << "La lista esta vacia \n";
		}
		else {
			std::cout << "Paciente antendido -> " << cola.Pop().getNombre() << "\n";
			std::cout << "Esta es la lista actualizada de pacientes segun prioridad de atencion:\n";
			cola.MostrarCola();
		}
	}

	//Se crea un constructor de copia que replica todos los elementos 
	//que estan contenidos dentro de la cola de prioridad
	void probarConstructorDeCopia() {
		std::string nombre;
		int gravedad;
		cout << "================================================\n";
		cout << "	       Constructor de Copia\n";
		cout << "================================================\n";
		std::cout << "Se crea una lista a partir de la anterior y se muestra\n";
		ColaDePrioridad<Paciente> copia(cola);
		copia.MostrarCola();
		std::cout << "Inserte un paciente a la nueva cola\n";
		std::cout << "Ingrese el nombre del Paciente\n";
		std::cin >> nombre;
		std::cout << "Ingrese el grado de gravedad de la salud del paciente\n";
		std::cin >> gravedad;

		copia.Insertar(*(new Paciente(nombre, gravedad)));

		std::cout << "Cola Original:\n";
		cola.MostrarCola();

		std::cout << "Nueva Cola:\n";
		copia.MostrarCola();
	}
};
