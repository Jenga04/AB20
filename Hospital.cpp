#include "Hospital.h"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;


hospital::hospital(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas):
	archivoPacientes(archivoPacientes), 
	archivoMedicos(archivoMedicos), 
	archivoCitas(archivoCitas) {}

//Validaciones de fecha y hora

bool bisiesto(int a�o) {
	return (a�o % 4 == 0 &&(a�o % 100 != 0 || a�o % 400 == 0));
}

bool mesValido(int mes) {
	return mes >= 1 && mes <= 12;
}

bool diaValido(int dia, int mes, int a�o) {
	vector<int> diasPorMes = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (bisiesto(a�o)) {
		diasPorMes[1] = 29;
	}
	return dia >= 1 && dia <= diasPorMes[mes - 1];
}

bool hospital::validarFecha(const string& fecha) {
	int dia, mes, a�o;
	char barraLateral;
	stringstream defFecha(fecha);
	defFecha >> dia >> barraLateral >> mes >> barraLateral >> a�o;

	if (defFecha.fail() || barraLateral != '/' || !mesValido(mes) || !diaValido(dia, mes, a�o)) {
		return false;
	}
	return true;
	
	//fecha actual
	time_t fechaExacta = time(nullptr);
	tm* diaLocal = localtime(&fechaExacta);

	int diaExacto = diaLocal->tm_mday;
	int mesExacto = diaLocal->tm_mon+1;
	int a�oExacto = diaLocal->tm_year+1900;

	//Comprobar la fecha actual
	if (a�o < a�oExacto || (a�o == a�oExacto && mes < mesExacto) || (a�o == a�oExacto && mes == mesExacto && dia < diaExacto)) {
		return false;
	}
	return true;
}
	
bool hospital::validarHora(const string& fecha, const string& hora){
	int horas, minutos;
	char puntos;
	stringstream defHora(hora);
	defHora >> horas >> puntos >> minutos;

	if (defHora.fail() || puntos != ':' || horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
		return false;
	} 
	return true;
}

//Opciones de pacientes

void hospital::registrarPaciente(
	int id,
	const string& n,
	const string& fecha) {
	listaPacientes.push_back(paciente(id, n, fecha));
	guardarPaciente();
	cout << "Paciente registrado correctamente. \n";
}

void hospital::eliminarPaciente(int idPaciente) {
	auto buscarPaciente = find_if(listaPacientes.begin(), listaPacientes.end(),
		[idPaciente](const paciente& listadoPacientes) {
			return listadoPacientes.getIdPaciente() == idPaciente;
		});
	if (buscarPaciente != listaPacientes.end()) {
		listaPacientes.erase(buscarPaciente);
		cout << "Paciente " << idPaciente << "Eliminado correctamente.\n";
	}
	else {
		cout << "Paciente no enccontrado.\n";
	}
}

void hospital::modificarPaciente(int idPaciente, string nuevaFechaIngreso, string nuevoHistorial) {
	auto buscarPaciente = find_if(listaPacientes.begin(), listaPacientes.end(),
		[idPaciente](const paciente& listadoPacientes) {
		return listadoPacientes.getIdPaciente() == idPaciente;
		});
	if (buscarPaciente != listaPacientes.end()) {
		buscarPaciente->setFechaIngreso(nuevaFechaIngreso);
		buscarPaciente->actualizarHistorial(nuevoHistorial);
		cout << "Paciente " << idPaciente << " ha sido modificado\n";
	}
	else {
		cout << "Paciente no encontrado.\n";
	}
}

void hospital::listadoPacientes() const {
	cout << "Lista de pacientes:\n";
	for (auto& paciente : listaPacientes) {
		paciente.DatosPaciente();
	}
}

void hospital::listaPacientesNombre() const {
	cout << "Lista por nombre: \n";
	vector<paciente> pacientes = listaPacientes;
	sort(pacientes.begin(), pacientes.end(), [](const paciente& a, const paciente& z) {
		return a.getNombrePaciente() < z.getNombrePaciente();
		});
	for (const auto& paciente : pacientes) {
		paciente.DatosPaciente();
	}
}

void hospital::listaPacientesFecha() const {
	cout << "Lista por fecha: \n";
	vector<paciente> pacientes = listaPacientes;
	sort(pacientes.begin(), pacientes.end(), [](const paciente& fechaCercana, const paciente& fechaLejana) {
		return fechaCercana.getFechaIngreso() > fechaLejana.getFechaIngreso();
		});
	for (const auto& paciente : pacientes) {
		paciente.DatosPaciente();
	}
}

//Opciones de medicos

void hospital::registrarMedico(
	int id,
	const string& n,
	const string& tipo,
	bool disponible) {
	listaMedicos.push_back(medico(id, n, tipo, disponible));
	guardarMedico();
	cout << "Medico registrado correctamente. \n";
}
void hospital::eliminarMedico(int idMedico) {
	auto buscarMedico = find_if(listaMedicos.begin(), listaMedicos.end(),
		[idMedico](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == idMedico;
		});
	if (buscarMedico != listaMedicos.end()) {
		listaMedicos.erase(buscarMedico);
		cout << "Medico " << idMedico << "Eliminado correctamente.\n";
	}
	else {
		cout << "Medico no enccontrado.\n";
	}
}

void hospital::modificarMedico(int idMedico, bool nuevaDisponibilidad) {
	auto buscarMedico = find_if(listaMedicos.begin(), listaMedicos.end(),
		[idMedico](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == idMedico;
		});
	if (buscarMedico != listaMedicos.end()) {
		buscarMedico->setDisponibilidad(nuevaDisponibilidad);
		cout << "Medico " << idMedico << " modificado correctamente.\n";
	}
	else {
		cout << "Medico no encontrado.\n";
	}
}
void hospital::listadoMedicos() const {
	cout << "Lista de medicos:\n";
	for (auto& medico : listaMedicos) {
		medico.datosMedico();
	}
}
void hospital::listaMedicosEspecialidad() const {
	cout << "Lista de medicos segun su especialidad:\n";

	vector<medico> medicos = listaMedicos;
	sort(medicos.begin(), medicos.end(), [](const medico& a, const medico& z) {
		return a.getEspecialidad() < z.getEspecialidad();
		});
	for (const auto& medico : medicos) {
		medico.datosMedico();
	}
}

void hospital::listaMedicosDisponibles() const {
	cout << "Medicos disponibles:\n";
	for (const auto& medico : listaMedicos) {
		if (medico.estaDisponible()) {
			medico.datosMedico();
		}
	}
	cout << "Medicos no disponobles:\n";
	for (const auto& medico : listaMedicos) {
		if (!medico.estaDisponible()) {
			medico.datosMedico();
		}
	}
}

//Opciones de citas

void hospital::registrarCita(
	int id,
	const string& fecha,
	const string& hora,
	int idp,
	int idm,
	int urgente) {
	auto buscarMedico = find_if(listaMedicos.begin(), listaMedicos.end(),
		[idm](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == idm;
		});

	if (buscarMedico == listaMedicos.end()) {
		cout << "ID de medico no valido.\n";
		return;
	}
	if (!buscarMedico->estaDisponible()) {
		cout << "Este medico no esta disponible. \n";
		return;
	}
	if (!validarFecha(fecha) || !validarHora(fecha, hora)) {
		cout << "Fecha u hora invalidas. Intenta de nuevo.\n";
		return;
	}
	listaCitas.push_back(cita(id, fecha, hora, idp, idm, urgente));
	guardarCita();
	cout << "Cita registrada correctamente.\n";
	for (auto& paciente : listaPacientes) {
		if (paciente.getIdPaciente() == idp) {
			paciente.setFechaIngreso(fecha);
			break;
		}
	}
}

void hospital::cancelarCita(int idCita) {
	auto buscarCita = find_if(listaCitas.begin(), listaCitas.end(),
		[idCita](const cita& listaCitas) {
			return listaCitas.getIdCita() == idCita;
		});
	if (buscarCita != listaCitas.end()) {
		listaCitas.erase(buscarCita);
		cout << "Cita " << idCita << "Eliminada correctamente.\n";
	}
	else {
		cout << "Cita no enccontrada.\n";
	}
}
void hospital::modificarCita(int idCita, string nuevaFechaCita, string nuevaHoraCita) {
	if (!validarFecha(nuevaFechaCita) || !validarHora(nuevaFechaCita, nuevaHoraCita)) {
		cout << "Fecha u hora invalidas. Intenta de nuevo.\n";
		return;
	}
	auto buscarCita = find_if(listaCitas.begin(), listaCitas.end(),
		[idCita](const cita& listaCitas) {
			return listaCitas.getIdCita() == idCita;
		});
	if (buscarCita != listaCitas.end()) {
		buscarCita->setFechaCita(nuevaFechaCita);
		buscarCita->setHoraCita(nuevaHoraCita);
		cout << "Cita " << idCita << " modificada correctamente\n";
		for (auto& paciente : listaPacientes) {
			if (paciente.getIdPaciente() == buscarCita->getIdPaciente()); {
				paciente.setFechaIngreso(nuevaFechaCita);
				break;
			}
		}
	}
	else {
		cout << "Cita no encontrada.\n";
	}
}

void hospital::listadoCitas() const {
	cout << "Lista de citas: \n";
	for (auto& cita : listaCitas) {
		cita.datosCitas();
	}
}

void hospital::listaCitasUrgencia() const {
	cout << "Lista de citas urgentes: \n";

	vector<cita> citas = listaCitas;
	sort(citas.begin(), citas.end(), [](const cita& urgenciaMayor, const cita& urganciaMenor) {
		return urgenciaMayor.getUrgencia() > urganciaMenor.getUrgencia();
		});
	for (const auto& cita : citas) {
		cita.datosCitas();
	}
}

void hospital::listaCitasFecha() const {
	cout << "Lista de citas por fecha: \n";

	vector <cita> citas = listaCitas;
	sort(citas.begin(), citas.end(), [](const cita& fechaCercana, const cita& fechaLejana) {
		return fechaCercana.getFechaCita() > fechaLejana.getFechaCita();
		});
	for (const auto& cita : citas) {
		cita.datosCitas();
	}
}

//Guardar datos en los archivos

void hospital::guardarPaciente(){
	ofstream archivo(archivoPacientes);
	for (auto& paciente : listaPacientes) {
		archivo << paciente.getIdPaciente() << ", " << paciente.getNombrePaciente() << ", " << paciente.getFechaIngreso();
	}
}

void hospital::guardarMedico(){
	ofstream archivo(archivoMedicos);
	for (const auto& medico : listaMedicos) {
		archivo << medico.getIdMedico() << "," << medico.getNombreMedico() << "," << medico.getEspecialidad() << "," << (medico.estaDisponible() ? "1" : "0") << "\n";
	}
}

void hospital::guardarCita() {
	ofstream archivo(archivoCitas);
	for (const auto& cita : listaCitas) {
		archivo << cita.getIdCita() << ", " << cita.getFechaCita() << ", " << cita.getHoraCita()<< ", " << cita.getIdPaciente() << ", " << cita.getIdMedico() << ", " << cita.getUrgencia() << "\n";
	}
}