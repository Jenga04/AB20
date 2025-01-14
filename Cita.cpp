#include "Cita.h"
#include <iostream>
using namespace std;

cita::cita(int id, string fecha, int idp, int idm, int urgente) :
	idCita(id),
	fechaHora(fecha),
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

int cita::getIdCita() {
	return idCita;
}
string cita::getFechaHora() {
	return fechaHora;
}
int cita::getIdPaciente() {
	return idPaciente;
}
int cita::getIDMedico() {
	return idMedico;
}
int cita::getUrgencia() {
	return urgencia;
}

void cita::datosCitas() {
	cout << "Id de la cita: " << idCita << "\nFecha y hora: " << fechaHora << "\nID del paciente: " << idPaciente << "\n ID del medico: " << idMedico << "\nNivel de urgencia: " << urgencia;
}

