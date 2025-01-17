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
void cita::setFechaCita(string nuevaFechaCita) {
	fechaCita = nuevaFechaCita;
}
void cita::setHoraCita(string nuevaHoraCita) {
	horaCita = nuevaHoraCita;
}
void cita::datosCitas() const{
	cout << "Id de la cita: " << idCita << ", fecha y hora: " << fechaCita << " a las " << horaCita << ", ID del paciente : " << idPaciente << ", ID del medico : " << idMedico << ", Nivel de urgencia : " << urgencia <<"\n";
}

