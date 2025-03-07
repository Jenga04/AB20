#ifndef MEDICO_H
#define MEDICO_H

#include <iostream>
using namespace std;

class medico {
private:
	int idMedico;
	string nombreMedico;
	string especialidad;
	bool disponibilidad;

public:
	medico(int id,
		string n,
		string tipo,
		bool disponible);

	int getIdMedico() const;
	string getNombreMedico() const;
	string getEspecialidad() const;
	bool estaDisponible() const;

	void setDisponibilidad(bool nuevaDisponibilidad);
	void datosMedico() const;
	void datosPorEspecialidad() const;
	void datosPorDisponibilidad() const;
};

#endif // !MEDICO_H