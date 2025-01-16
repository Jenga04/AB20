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
	const string& archivoPacientes,
	const string& archivoMedicos,
	const string& archivoCitas);

	//Pacientes
	void listadoPacientes() const;
	void registrarPaciente(int idPaciente, const string& n, const string& fecha);
	void eliminarPaciente(int idPaciente);
	void modificarPaciente(int idPaciente, string nuevaFechaIngreso, string nuevoHistorial);
	

	

//Medicos
	void listadoMedicos() const;
	void listaMedicosEspecialidad(const string& especialidad);
	void listaMedicosDisponibles() const;
	void registrarMedico(int idMedico, const string& n,const string& tipo, bool disponible);
	void eliminarMedico(int idMedico);
	void modificarMedico(int idMedico, string nuevoNombre, string nuevaEspcialidad, bool nuevaDisponibilidad);
	
	
//Citas
	void listadoCitas() const;
	void listaCitasUrgencia() const;
	void listaCitasFecha() const;
	void registrarCita(int idCita, const string& fecha, const string& hora, int idp, int idm, int urgente);
	bool validarFecha(const string& fecha);
	bool validarHora(const string& fecha, const string& hora);
	void cancelarCita(int idCita);
	void modificarCita(int idCita, string nuevaFechaCita, string nuevaHoraCita);
	
	

//Archivos
	void guardarPaciente();
	void guardarMedico();
	void guardarCita();
	
	//void cargarPaciente();
	//void cargarMedico();
	//void caragrCita();
};