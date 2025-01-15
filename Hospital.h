#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> p;
	vector <medico> m;
	vector <cita> c;
	string archivoPacientes;
	string archivoMedicos;
	string archivoCitas;

public:
	
hospital(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas);

	//Pacientes
	void listaPacientes() const;
	void registrarPaciente(int id, const string& n, const string& fecha);
	void eliminarPaciente(int id);
	void modificarPaciente(int id, string nuevoNombre);
	

	

//Medicos
	void listaMedicos() const;
	void registrarMedico(int id, const string& n,const string& tipo, bool disponible);
	void eliminarMedico(int id);
	void modificarMedico(int id, string nuevoNombre, string nuevaEspcialidad);
	
	void listaMedicosEspecialidad(const string& especialidad);
	void listaMedicosDisponibles() const;

//Citas
	void listaCitas() const;
	void registrarCita(int id, const string& fecha, int idp, int idm, int urgente);
	void cancelarCita(int id);
	void modificarCita(int id, string nuevaFechaHora);
	
	void listaCitasUrgencia() const;
	void listaCitasFecha() const;

//Archivos
	void guardarPaciente();
	void guardarMedico();
	void guardarCita();
	void cargarPaciente();
	void cargarMedico();
	void caragrCita();
};