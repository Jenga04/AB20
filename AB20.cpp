// AB20.cpp: define el punto de entrada de la aplicación.
//
#include "AB20.h"
#include "Windows.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class servicio{
private:
	int idServicio;
	string tipoServicio;
};

servicio::servicio(){

}

servicio::~servicio(){
}
class Paciente{
private:
	int idPaciente;
	string nombre;
	DATE fechaIngreso;


};

Paciente::Paciente(){
}

Paciente::~Paciente(){
}
class Médico{
private:
	int idMédico;
	string nombre;
	string especialidad;
	boolean disponibilidad;
};

Médico::Médico(){
}

Médico::~Médico()
{
}
class cita{
private:
	int idCita;
	DATE fecha;
	clock_t hora;
};

cita::cita()
{
}

cita::~cita()
{
}
class Hospital{
private:


};

Hospital::Hospital()
{
}

Hospital::~Hospital()
{
}