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

void hospital::listaPacientes() const {
	cout << "Lista de pacientes:\n";
	for (auto& paciente : p) {
		paciente.DatosPaciente();
	}
}
void hospital::registrarPaciente(int id, const string& n, const string& fecha) {
	p.push_back(paciente(id, n, fecha));
	guardarPaciente;
	cout << "Paciente registrado correctamente. \n";
}

void hospital::listaMedicos() const{ 
	cout << "Lista de medicos:\n";
	for (auto& medico : m) {
		medico.datosMedico();
	}
}
void hospital::registrarMedico(int id, const string& n, string tipo, bool disponible) {
	m.push_back(medico(id, n, tipo, disponible));
	guardarMedico;
	cout << "Medico registrado correctamente. \n";
}
void hospital::listaCitas() const{
	cout << "Lista de citas: \n";
	for (auto& cita : c) {
		cita.datosCitas();
	}
}
void hospital::registrarCita(int id, const string& fecha, int idp, int idm, int urgente){
	c.push_back(cita(id, fecha, idp, idm, urgente));
	guardarCita;
	cout << "Cita registrada correctamente.\n";
}

//Guardar datos en los archivos

void hospital::guardarPaciente(){
	ofstream archivo(archivoPacientes);
	for (auto& paciente : p) {
		archivo << paciente.getId() << ", " << paciente.getNombre() << ", " << paciente.getFechaIngreso();
	}
}

void hospital::guardarMedico(){
	ofstream archivo(archivoMedicos);
	for (const auto& medico : m) {
		archivo << medico.getId() << "," << medico.getNombre() << "," << medico.getEspecialidad() << "," << medico.estaDisponible() ? "1" : "0") << "\n";
	}
}

void hospital::guardarCita(){
	ofstream archivo(archivoCitas);
	for (const auto& cita : c) {
		archivo << cita.getIdCita() << "," << cita.getFechaHora() << "," << cita.getIdPaciente() << "," << cita.getIdMedico() << ","<< cita.getUrgencia() << "\n";
	}
}