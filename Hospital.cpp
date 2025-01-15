#include "Hospital.h"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


hospital::hospital(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas):
	archivoPacientes(archivoPacientes), 
	archivoMedicos(archivoMedicos), 
	archivoCitas(archivoCitas) {}

//Opciones de pacientes
void hospital::listadoPacientes() const {
	cout << "Lista de pacientes:\n";
	for (auto& paciente : listaPacientes) {
		paciente.DatosPaciente();
	}
}
void hospital::registrarPaciente(
	int id, 
	const string& n, 
	const string& fecha) {
	listaPacientes.push_back(paciente(id, n, fecha));
	guardarPaciente;
	cout << "Paciente registrado correctamente. \n";
}
void hospital::eliminarPaciente(int idPaciente) {
	auto idp = find_if(listaPacientes.begin(), listaPacientes.end(),
		[idPaciente](const paciente& listaPacientes) {
			return listaPacientes.getIdPaciente() == idPaciente;
		});
	if (idp != listaPacientes.end()) {
		listaPacientes.erase(idp);
		cout << "Paciente " << idPaciente << "Eliminado correctamente.\n";
	} else {
		cout << "Paciente no enccontrado.\n";
	}
}
//Opciones de medicos
void hospital::listadoMedicos() const{ 
	cout << "Lista de medicos:\n";
	for (auto& medico : listaMedicos) {
		medico.datosMedico();
	}
}
void hospital::registrarMedico(
	int id,
	const string& n, 
	const string& tipo, 
	bool disponible) {
	listaMedicos.push_back(medico(id, n, tipo, disponible));
	guardarMedico;
	cout << "Medico registrado correctamente. \n";
}
void hospital::eliminarMedico(int idMedico) {
	auto idm = find_if(listaMedicos.begin(), listaMedicos.end(),
		[idMedico](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == idMedico;
		});
	if (idm != listaMedicos.end()) {
		listaMedicos.erase(idm);
		cout << "Medico " << idMedico << "Eliminado correctamente.\n";
	}
	else {
		cout << "Medico no enccontrado.\n";
	}
}
//Opciones de citas
void hospital::listadoCitas() const{
	cout << "Lista de citas: \n";
	for (auto& cita : listaCitas) {
		cita.datosCitas();
	}
}
void hospital::registrarCita(
	int id, 
	const string& fecha, 
	int idp, 
	int idm, 
	int urgente) {
	listaCitas.push_back(cita(id, fecha, idp, idm, urgente));
	guardarCita;
	cout << "Cita registrada correctamente.\n";
}
void hospital::cancelarCita(int idCita) {
	auto idc = find_if(listaCitas.begin(), listaCitas.end(),
		[idCita](const cita& listaCitas) {
			return listaCitas.getIdCita() == idCita;
		});
	if (idc != listaCitas.end()) {
		listaCitas.erase(idc);
		cout << "Cita " << idCita << "Eliminada correctamente.\n";
	}
	else {
		cout << "Cita no enccontrada.\n";
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

void hospital::guardarCita(){
	ofstream archivo(archivoCitas);
	for (const auto& cita : listaCitas) {
		archivo << cita.getIdCita() << "," << cita.getFechaHora() << "," << cita.getIdPaciente() << "," << cita.getIdMedico() << ","<< cita.getUrgencia() << "\n";
	}
}