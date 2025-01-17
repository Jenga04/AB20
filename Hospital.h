#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <medico> listaMedicos;
	vector <cita> listaCitas;
	string archivoPacientes;
	string archivoMedicos;
	string archivoCitas;

public:
	
hospital(
	//fututo uso de archivos

	const string& archivoPacientes,
	const string& archivoMedicos,
	const string& archivoCitas);

	//Validaciones
	bool validarFecha(const string& fecha);
	bool validarHora(const string& fecha, const string& hora);
	
	//Pacientes
	
	void registrarPaciente(int idPaciente, const string& n, const string& fecha);
	void eliminarPaciente(int idPaciente);
	void modificarPaciente(int idPaciente, string nuevaFechaIngreso, string nuevoHistorial);
	void listadoPacientes() const;
	void listaPacientesNombre() const;
	void listaPacientesFecha() const;

//Medicos
	
	void registrarMedico(int idMedico, const string& n,const string& tipo, bool disponible);
	void eliminarMedico(int idMedico);
	void modificarMedico(int idMedico, string nuevoNombre, string nuevaEspcialidad, bool nuevaDisponibilidad);
	void listadoMedicos() const;
	void listaMedicosEspecialidad() const;
	void listaMedicosDisponibles() const;
	
//Citas
	
	void registrarCita(int idCita, const string& fecha, const string& hora, int idp, int idm, int urgente);
	void cancelarCita(int idCita);
	void modificarCita(int idCita, string nuevaFechaCita, string nuevaHoraCita);
	void listadoCitas() const;
	void listaCitasUrgencia() const;
	void listaCitasFecha() const;
	

//Archivos
	void guardarPaciente();
	void guardarMedico();
	void guardarCita();
	
	//void cargarPaciente();
	//void cargarMedico();
	//void caragrCita();
};