// AB20.cpp: define el punto de entrada de la aplicación.
//
#include "AB20.h"
#include "Windows.h"
#include <string>
#include <iostream>
using namespace std;

class servicio{
private:
	int idServicio;
	string tipoServicio;
};
class paciente{
private:
	int idPaciente;
	string nombre;
	DATE fechaIngreso;


};

class médico{
private:
	int idMédico;
	string nombre;
	string especialidad;
	boolean disponibilidad;
};

class cita{
private:
	int idCita;
	string fechaHora;
	int urgencia;
	int idPaciente;
	int idMédico;
};

class Hospital{
private:
	vector<paciente> listaPacientes;
	vector<médico> listaMédicos;
	vector<cita> listaCitas;
	vector<servicio> listaServicios;
public:
	void registrarPacientes(
		int id, 
		string nombre, 
		DATE fecha)
