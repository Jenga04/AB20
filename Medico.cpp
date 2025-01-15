#include "Medico.h"
#include <iostream>
using namespace std;

medico::medico (int id, string n, string tipo, bool disponible):
	idMedico(id),
	nombreMedico(n),
	especialidad(tipo),
	disponibilidad(disponible) {}

int medico::getIdMedico() const {
	return idMedico;
}
string medico::getNombreMedico() const{
	return nombreMedico;
}
string medico::getEspecialidad() const{
	return especialidad;
}
bool medico::estaDisponible() const{
	return disponibilidad;
}
void medico::cambiarDisponibilidad(bool estado) {
	disponibilidad = estado;
}
void medico:: setNombreMedico(string nuevoNombreMedico) {
	nombreMedico = nuevoNombreMedico;
}
void medico::setEspecialidad(string nuevaEspecialidad) {
	especialidad = nuevaEspecialidad;
}
void medico::setDisponibilidad(bool nuevaDisponibilidad) {
	disponibilidad = nuevaDisponibilidad;
}
void medico::datosMedico() const {
	cout << "ID del Medico: " << idMedico << ".\nNombre: " << nombreMedico << ".\nEspecialidad: " << especialidad << "\nDisponibilidad: " << (disponibilidad ? "Sí" : "No");
}
