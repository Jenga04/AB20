#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <medico> listaMedicos;
	vector <cita> listaCitas;

public:
	hospital();

	//Pacientes
	void altaPaciente(int id, string n, string fecha);
	void bajaPaciente(int id);
	void modificarPaciente(int id, string nuevoNombre);
	void listadoPacientes() const;

	//Medicos
	void altaMedico(int id, string n, string tipo);
	void bajaMedico(int id);
	void modificarMedico(int id, string nuevoNombre, string nuevaEspcialidad);
	void listaMedicosEspecialidad(const string& especialidad);
	void listaMedicosDisponibles() const;

	//Citas
	void asignarCita(int id, string fecha, int idp, int idm, int urgente);
	void cancelarCita(int id);
	void modificarCita(int id, string nuevaFechaHora);
	void listaCitasUrgencia() const;
	void listaCitasFecha() const;

	//Archivos
	void guardarDatos(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas);
	void cargarDatos(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas);
};