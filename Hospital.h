#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <medico> listaMedicos;
	vector <cita> listaCitas;

public:
	hospital(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas);

//Pacientes
	void registrarPaciente(int id, const string& n, const string& fecha);
	void eliminarPaciente(int id);
	void modificarPaciente(int id, string nuevoNombre);
	void listaPacientes() const;

	

//Medicos
	void registrarMedico(int id, string n, string tipo, bool disponible);
	void eliminarMedico(int id);
	void modificarMedico(int id, string nuevoNombre, string nuevaEspcialidad);
	void listaMedicos() const;
	void listaMedicosEspecialidad(const string& especialidad);
	void listaMedicosDisponibles() const;

//Citas
	void registrarCita(int id, string fecha, int idp, int idm, int urgente);
	void cancelarCita(int id);
	void modificarCita(int id, string nuevaFechaHora);
	void listaCitas() const;
	void listaCitasUrgencia() const;
	void listaCitasFecha() const;

//Archivos
	void guardarPaciente(const string& archivoPacientes);
	void guardarMedico(const string& archivoMedicos);
	void guardarCita(const string& archivoCitas);
	void cargarPaciente(const string& archivoPacientes);
	void cargarMedico(const string& archivoMedicos);
	void caragrCita(const string& archivoCitas);
};