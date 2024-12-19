#include <string>
class medico {
private:
	int idMedico;
	string nombre;
	string especialidad;
	bool disponibilidad;

public:
	medico(int id, string n, string tipo, bool disponible) :
		idMedico(id),
		nombre(n),
		especialidad(tipo),
		disponibilidad(true) {}

	void datosMédico() {
		cout << "ID del medico: " << idMedico << ".\nNombre: " << nombre << ".\nEspecialidad: " << especialidad << ".\nDisponibile:  " << (disponibilidad ? "Si" : "No") << endl;
	}

	int getID() {
		return idMedico;
	}
	string getNombre() {
		return nombre;
	}
	string getEspecialidad() {
		return especialidad;
	}
	bool estaDisponible() {
		return disponibilidad;
	}
	void cambiarDisponibilidad(bool estado) {
		disponibilidad = estado;
	}

	void setNombre(const string& nuevoNombre) {
		nombre = nuevoNombre;
	}
	void setEspecialidad(const string& nuevaEspecialidad) {
		especialidad = nuevaEspecialidad;
	}
	void setDisponibilidad(bool nuevaDisponibilidad) {
		disponibilidad = nuevaDisponibilidad;
	}
};