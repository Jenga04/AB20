#include <iostream>
using namespace std;

class medico {
private:
	int idMedico;
	string nombreMedico;
	string especialidad;
	bool disponibilidad;

public:
	medico(int id, string n, string tipo, bool disponible);
	
	int getIdMedico() const;
	string getNombreMedico() const;
	string getEspecialidad() const;
	bool estaDisponible() const;
	void cambiarDisponibilidad(bool estado);

	void setNombreMedico(string nuevoNombreMEdico);
	void setEspecialidad(string nuevaEspecialidad);
	void setDisponibilidad(bool nuevaDisponibilidad);
	void datosMedico() const;
};