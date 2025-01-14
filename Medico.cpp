#include "Medico.h"
#include <iostream>
using namespace std;

medico::medico (int id, string n, string tipo, bool disponible):
	idMedico(id),
	nombre(n),
	especialidad(tipo),
	disponibilidad(disponible) {}

int medico::getId() const {
	return idMedico;
}
string medico::getNombre() {
	return nombre;
}
string medico::getEspecialidad() {
	return especialidad;
}
bool medico::estaDisponible() {
	return disponibilidad;
}
void medico::cambiarDisponibilidad(bool estado) {
	disponibilidad = estado;
}
void medico::datosMedico() const {
	cout << "ID del Medico: " << idMedico << ".\nNombre: " << nombre << ".\nEspecialidad: " << especialidad << "\nDisponibilidad: " << (disponibilidad ? "Sí" : "No");
}
