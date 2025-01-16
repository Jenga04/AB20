#include "Paciente.h"
#include <iostream>
using namespace std;

paciente::paciente (int id, string n, string fechaCita):
	idPaciente(id),
	nombrePaciente(n),
	fechaIngreso(fechaCita),
	historial(""){}

int paciente::getIdPaciente() const {
	return idPaciente;
}
string paciente::getNombrePaciente() {
	return nombrePaciente;
}
string paciente::getFechaIngreso() {
	return fechaIngreso;
}
void paciente::setFechaIngreso(string nuevaFecha) {
	fechaIngreso = nuevaFecha;
}
void paciente::actualizarHistorial(string nuevoHistorial) {
	historial = nuevoHistorial;
}
void paciente::DatosPaciente() const{
	cout << "ID del paciente: " << idPaciente << ", nombre: " << nombrePaciente << ", fecha de ingreso: " << fechaIngreso << "\n";
}