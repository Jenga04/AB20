#ifndef CITA_H
#define CITA_H

#include <iostream>
using namespace std;

class cita {
private:
	int idCita;
	string fechaCita;
	string horaCita;
	int idPaciente;
	int idMedico;
	int urgencia;
public:
	cita(
		int id,
		const string& fecha,
		const string& hora,
		int idp,
		int idm,
		int urgente);

	int getIdCita() const;
	string getFechaCita() const;
	string getHoraCita() const;
	int getIdPaciente() const;
	int getIdMedico() const;
	int getUrgencia() const;

	void setFechaCita(string nuevaFechaCita);
	void setHoraCita(string nuevaHoraCita);
	void datosCitas() const;
};

#endif