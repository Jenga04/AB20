#include <iostream>
using namespace std;

class medico {
private:
	int idMedico;
	string nombre;
	string especialidad;
	bool disponibilidad;

public:
	medico(int id, string n, string tipo, bool disponible);
	
	int getId() const;
	string getNombre();
	string getEspecialidad();
	bool estaDisponible();
	void cambiarDisponibilidad(bool estado);

	void setNombre(const string& nuevoNombre) {
		nombre = nuevoNombre;
	}
	void setEspecialidad(const string& nuevaEspecialidad) {
		especialidad = nuevaEspecialidad;
	}
	void setDisponibilidad(bool nuevaDisponibilidad) {
		disponibilidad = nuevaDisponibilidad;
	}
	void datosMedico() const;
};