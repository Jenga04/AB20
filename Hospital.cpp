#include "Hospital.h"
#include <iostream>
#include <fstream>
using namespace std;


hospital::hospital(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas) :
	archivoPacientes(archivoP), archivoMedicos(archivoM), archivoCitas(archivoC) {}

	void hospital::listadoPacientes() const {
	cout << "Lista de pacientes:\n";
	for (auto& paciente : p) {
		paciente.DatosPaciente();
	}
}
	void hospital::registrarPaciente(int id, const string& n, const string& fecha) {
		p.push_back(paciente(id, n, fecha));
		guardarPaciente();
		cout << "Paciente registrado correctamente. \n";
	}

void listadoMedicos() {
	cout << "Lista de médicos:\n";
	for (auto& medico : listaMedicos) {
		medico.datosMedico();
	}
}
void registrarMedico(medico Medico) {
	listaMedicos.push_back(Medico);
}
void listadoCitas() {
	cout << "Lista de citas: \n";
	for (auto& cita : listaCitas) {
		cita.datosCitas();
	}
}
void añadirCita(cita Cita) {
	listaCitas.push_back(Cita);
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
		archivo << medico.getId() << "," << medico.getNombre() << "," << medico.getEspecialidad() << "," << (medico.isDisponible() ? "1" : "0") << "\n";
	}
}

void hospital::guardarCitas(){
	ofstream archivo(archivoCitas);
	for (const auto& cita : c) {
		archivo << cita.getId() << "," << cita.getFechaHora() << "," << cita.getIdPaciente() << "," << cita.getIdMedico() << ","<< cita.getUrgencia() << "\n";
	}
}