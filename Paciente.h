// AB20.h: archivo de inclusión para archivos de inclusión estándar del sistema,
// o archivos de inclusión específicos de un proyecto.
class paciente {
private:
	int idPaciente;
	string nombre;
	string fechaIngreso;
	string historial;
public:
	paciente(int id, string n, string fecha) :
		idPaciente(id),
		nombre(n),
		fechaIngreso(fecha) {}
	void mostrarDatos() {
		cout << "ID del paciente: " << idPaciente << ".\nNombre: " << nombre << ".\nFecha de ingreso: " << fechaIngreso << endl;
	}
	int getId() { return idPaciente; }
	string getNombre() { return nombre; }
};