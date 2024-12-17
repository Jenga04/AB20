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
	void mostrarDatos() {
		cout << "ID del médico: " << idMédico << ".\nNombre: " << nombre << ".\nEspecialidad: " << especialidad << ".\nDisponibile:  " << (disponibilidad ? "Si" : "No") << endl;
	}
	int getID() { return idMédico; }
	string getEspecialidad() { return especialidad;}
};