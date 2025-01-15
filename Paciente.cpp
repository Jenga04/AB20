#include "Paciente.h"
#include <iostream>
using namespace std;

paciente::paciente (int id, string n, string fecha):
	idPaciente(id),
	nombrePaciente(n),
	fechaIngreso(fecha),
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
void paciente::setNombrePaciente(string nuevoNombrePaciente) {
	nombrePaciente = nuevoNombrePaciente;
}
void paciente::setFechaIngreso(string nuevaFecha) {
	fechaIngreso = nuevaFecha;
}
void paciente::actualizarHistorial(string nuevoHistorial) {
	historial = nuevoHistorial;
}
void paciente::DatosPaciente() const{
	cout << "ID del paciente: " << idPaciente << ".\nNombre: " << nombrePaciente << ".\nFecha de ingreso: " << fechaIngreso;
}