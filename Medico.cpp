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
void medico::setDisponibilidad(bool nuevaDisponibilidad) {
	disponibilidad = nuevaDisponibilidad;
}
void medico::datosMedico() const {
	cout << "ID del medico: " << idMedico << ", nombre: " << nombreMedico << ",  especialidad: " << especialidad << ", disponibilidad: " << (disponibilidad ? "Si" : "No") <<"\n";
}
void medico::datosPorEspecialidad() const {
	cout << "Especialidad: " << especialidad << ", ID: " << idMedico << ", nombre: " << nombreMedico << ", disponibilidad: " << (disponibilidad ? "Si" : "No") << "\n";
}
void medico::datosPorDisponibilidad() const {
	cout <<"ID del medico: " << idMedico << ", nombre: " << nombreMedico << ",  especialidad: " << especialidad << "\n";
}
