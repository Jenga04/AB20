#include <string>
class médico {
private:
	int idMédico;
	string nombre;
	string especialidad;
	bool disponibilidad;

public:
	médico(int id, string n, string tipo, bool disponible) :
		idMédico(id),
		nombre(n),
		especialidad(tipo),
		disponibilidad(true) {}

	void datosMédico() {
		cout << "ID del médico: " << idMédico << ".\nNombre: " << nombre << ".\nEspecialidad: " << especialidad << ".\nDisponibile:  " << (disponibilidad ? "Si" : "No") << endl;
	}

	int getID() {
		return idMédico;
	}
	string getNombre() {
		return nombre;
	}
	string getEspecialidad() {
		return especialidad;
	}
	bool estáDisponible() {
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