#include <string>
class m�dico {
private:
	int idM�dico;
	string nombre;
	string especialidad;
	bool disponibilidad;

public:
	m�dico(int id, string n, string tipo, bool disponible) :
		idM�dico(id),
		nombre(n),
		especialidad(tipo),
		disponibilidad(true) {}

	void datosM�dico() {
		cout << "ID del m�dico: " << idM�dico << ".\nNombre: " << nombre << ".\nEspecialidad: " << especialidad << ".\nDisponibile:  " << (disponibilidad ? "Si" : "No") << endl;
	}

	int getID() {
		return idM�dico;
	}
	string getNombre() {
		return nombre;
	}
	string getEspecialidad() {
		return especialidad;
	}
	bool est�Disponible() {
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