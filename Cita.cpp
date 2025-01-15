#include "Cita.h"
#include <iostream>
using namespace std;

cita::cita(int id, const string& fecha, const string& hora, int idp, int idm, int urgente) :
	idCita(id),
	fechaCita(fecha),
	horaCita(hora),
	idPaciente(idp),
	idMedico(idm) {
	if (urgente < 1) {
		this->urgencia = 1;
	}
	else if (urgente > 5) {
		this->urgencia = 5;
	}
	else {
		this->urgencia = urgente;
	}
}

int cita::getIdCita() const {
	return idCita;
}
string cita::getFechaCita() const {
	return fechaCita;
}
string cita::getHoraCita() const {
	return horaCita;
}
int cita::getIdPaciente() const{
	return idPaciente;
}
int cita::getIdMedico() const{
	return idMedico;
}
int cita::getUrgencia() const{
	return urgencia;
}
void cita::setFechaCita(string nuevaFecha) {
	fechaCita = nuevaFecha;
}
void cita::setHoraCita(string nuevaHora) {
	horaCita = nuevaHora;
}
void cita::datosCitas() const{
	cout << "Id de la cita: " << idCita << "\nFecha: " << fechaCita << "\nHora de la cita: " << horaCita << "\nID del paciente : " << idPaciente << "\n ID del medico : " << idMedico << "\nNivel de urgencia : " << urgencia;
}

