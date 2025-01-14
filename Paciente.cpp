#include "Paciente.h"
#include <iostream>
using namespace std;

paciente::paciente (int id, string n, string fecha):
	idPaciente(id),
	nombre(n),
	fechaIngreso(fecha),
	historial(""){}

int paciente::getId() const {
	return idPaciente;
}
string paciente::getNombre() {
	return nombre;
}
string paciente::getFechaIngreso() {
	return fechaIngreso;
}
void paciente::setNombre(const string& nuevoNombre) {
	nombre = nuevoNombre;
}
void paciente::setFechaIngreso(const string& nuevaFecha) {
	fechaIngreso = nuevaFecha;
}
void paciente::actualizarHistorial(const string& nuevoHistorial) {
	historial = nuevoHistorial;
}
void paciente::DatosPaciente() const{
	cout << "ID del paciente: " << idPaciente << ".\nNombre: " << nombre << ".\nFecha de ingreso: " << fechaIngreso;
}