#include <iostream>
using namespace std;

class paciente {
private:
	int idPaciente;
	string nombre;
	string fechaIngreso;
	string historial;

public:
	paciente(int id, string n, string fecha);

	int getId() const;
	string getNombre();
	string getFechaIngreso();

	void setNombre(const string& nuevoNombre);
	void setFechaIngreso(const string& nuevaFecha);
	void actualizarHistorial(const string& nuevoHistorial);
	void DatosPaciente() const;
};