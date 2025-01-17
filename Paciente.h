﻿#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
using namespace std;

class paciente {
private:
	int idPaciente;
	string nombrePaciente;
	string fechaIngreso;
	string historial;

public:
	paciente(
		int id,
		string n,
		string fecha);

	int getIdPaciente() const;
	string getNombrePaciente() const;
	string getFechaIngreso() const;

	void setFechaIngreso(string nuevaFechaIngreso);
	void actualizarHistorial(string nuevoHistorial);
	void DatosPaciente() const;
};

#endif // !Paciente.h