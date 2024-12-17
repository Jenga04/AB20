// AB20.cpp: define el punto de entrada de la aplicación.
//
#include "Paciente.h"
#include "Médico.h"
#include "Cita.h"
#include "Hospital.h"
#include "Windows.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

public:
	paciente(int id, string n, string fecha) :
		idPaciente(id),
		nombre(n),
		fechaIngreso(fecha) {}
void mostrarDatos() {
		cout << "ID del paciente: " << idPaciente << ".\nNombre: " << nombre << ".\nFecha de ingreso: " << fechaIngreso << endl;
	}
	int getId() { return idPaciente; }
	string getNombre() { return nombre; }
};

public:
	médico (int id, string n, string tipo, bool disponible): 
		idMédico(id), 
		nombre(n), 
		especialidad(tipo), 
		disponibilidad(true) {}
	void mostrarDatos() {
		cout << "ID del médico: " << idMédico << ".\nNombre: " << nombre << ".\nEspecialidad: " << especialidad << ".\nDisponibile:  " << (disponibilidad ? "Si" : "No") << endl;
	}
	int getID() { return idMédico; }
	string getEspecialidad() { return especialidad; }
};

public:
	cita (int id, string fecha, int idp, int idm, int urgente):
		idCita(id),
		fechaHora(fecha),
		idPaciente(idp),
		idMédico(idm) {
		this->urgencia = (urgencia < 1) ? 1 : (urgencia > 5) ? 5 : urgencia;
	}
	void mostrarDatos() {
		cout << "ID de cita: " << idCita << ".\nFecha y hora: " << fechaHora << ".\nID del paciente: " << idPaciente << ".\nID del médico: " << idMédico << ". \nUrgencia: " << urgencia << endl;
	}
	string getFechaHora() { return fechaHora; }
	int getUrgencia() { return urgencia; }

};

public:
	void registrarPaciente (int id, string nombre, string fecha) {
		listaPacientes.push_back(paciente(id, nombre, fecha));
		cout << "Paciente registrado.\n";
	}
	void listadoPacientes() {
		cout << "Lista de pacientes:\n";
		for (auto& paciente : listaPacientes) {
			paciente.mostrarDatos();
		}
	}
	void registrarMédico(int id, string n, string tipo, bool disponible) {
		listaMédicos.push_back(médico(id, n, tipo, disponible));
		cout << "Médico registrado.\n";
	}
	void listadoMédicos() {
		cout << "Lista de médicos:\n";
		for (auto& médico : listaMédicos) {
			médico.mostrarDatos();
		}
	}
	void asignarCita(int id, string fecha, int idp, int idm, int urgente) {
		listaCitas.push_back(cita(id, fecha, idp, idm, urgente));
		cout << "Cita asignada.\n";
	}
	void listadoCitas() {
		cout << "Lista de citas:\n";
		for (auto& cita : listaCitas) {
			cita.mostrarDatos();
		}
	}
};
int main() {
	SetConsoleOutputCP(1252);
	hospital hospital;

	hospital.registrarPaciente (1, "Jeremy James Atkinson", "27/11/2024");
	hospital.registrarMédico(1, "Ángel Bravo", "Pediatría", "Si");
	hospital.asignarCita(1, "27/11/2024 a las 17:30", 1, 1, 3);
	hospital.listadoPacientes();
	hospital.listadoMédicos();
	hospital.listadoCitas();
	return 0;
}