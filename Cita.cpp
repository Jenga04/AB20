#include "Cita.h"
#include <iostream>
using namespace std;

cita::cita(int id, string fechaCita, int idp, int idm, int urgente) :
	idCita(id),
	fechaHora(fechaCita),
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
string cita::getFechaHora() const {
	return fechaHora;
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
void cita::setFechaHora(string nuevaFechaHora) {
	fechaHora = nuevaFechaHora;
}
void cita::datosCitas() const{
	cout << "Id de la cita: " << idCita << "\nFecha y hora: " << fechaHora << "\nID del paciente: " << idPaciente << "\n ID del medico: " << idMedico << "\nNivel de urgencia: " << urgencia;
}

