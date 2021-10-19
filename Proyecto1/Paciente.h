#pragma once
#include<iostream>
using namespace std;
class Paciente
{
private:
	

	void IniciarPaciente() {
		this->nombre = "";
		this->gravedad = 0;
	}
public:

	std::string nombre;
	int gravedad;


	Paciente() {
		IniciarPaciente();
	}

	Paciente(std::string name, int g) {
		nombre = name;
		gravedad = g;
	}

	int getGravedad() {
		return gravedad;
	}

	void setGravedad(int g) {
		gravedad = g;
	}

	std::string getNombre() {
		return nombre;
	}

	void setNombre(std::string n) {
		nombre = n;
	}

	bool operator>(Paciente& p) {
		return(getGravedad() > p.getGravedad());
	}

	bool operator <(Paciente& p) {
		return(getGravedad() < p.getGravedad());
	}

	bool operator ==(Paciente& p) {
		return(getGravedad() == p.getGravedad());
	}

	
	friend ostream& operator<<(ostream& os, Paciente& p) {
		os << "Nombre: "<< p.getNombre()<< " - Gravedad: " << p.getGravedad()<< "\n";
		return os;
	}
};



