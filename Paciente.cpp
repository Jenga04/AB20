#include "Paciente.h"
#include <iostream>
using namespace std;

paciente::paciente (int id, string n, string fechaCita):
	idPaciente(id),
	nombrePaciente(n),
	fechaIngreso(fechaCita) {}

int paciente::getIdPaciente() const {
	return idPaciente;
}
string paciente::getNombrePaciente() const {
	return nombrePaciente;
}
string paciente::getFechaIngreso() const {
	return fechaIngreso;
}
void paciente::setFechaIngreso(string nuevaFecha) {
	fechaIngreso = nuevaFecha;
}
void paciente::DatosPaciente() const {
	cout << "ID del paciente: " << idPaciente << ", nombre: " << nombrePaciente << ", fecha de ingreso: " << fechaIngreso << "\n";
}
void paciente::DatosPorNombre() const {
	cout << "Nombre: " << nombrePaciente << ", ID: " << idPaciente << ", fecha de ingreso: " << fechaIngreso << "\n";
}
void paciente::DatosPorFecha() const {
	cout << "Fecha de ingreso: " << fechaIngreso << ", ID: " << idPaciente << ", nombre: " << nombrePaciente << "\n";
}