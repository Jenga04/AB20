#ifndef CITA_H
#define CITA_H

#include <iostream>
using namespace std;

class cita {
private:
	int idCita;
	string fechaHora;
	int idPaciente;
	int idMedico;
	int urgencia;
public:
	cita(int id, string fechaCita, int idp, int idm, int urgente);

	int getIdCita() const;
	string getFechaHora() const;
	int getIdPaciente() const;
	int getIdMedico() const;
	int getUrgencia() const;

	void setFechaHora(string nuevaFechaHora);
	void datosCitas() const;
};

#endif