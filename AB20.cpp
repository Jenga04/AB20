// AB20.cpp: define el punto de entrada de la aplicación.
//
#include "AB20.h"
#include "Windows.h"
#include <string>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class paciente {
private:
	int idPaciente;
	string nombre;
	string fechaIngreso;
	string historial;
public:
	paciente(int id, string n, string fecha): 
		idPaciente(id),
		nombre(n),
		fechaIngreso(fecha),
		historial("") {}
	void mostrarDatos() {
		cout << "ID del paciente: " << idPaciente << ".\n Nombre: " << nombre << ".\n Fecha de ingreso: " << fechaIngreso << endl;
	}
	void actualizarHistorial(string nuevoHistorial) { historial = nuevoHistorial; }
	int getId() { return idPaciente; }
	string getNombre() { return nombre; }
};

class médico{
private:
	int idMédico;
	string nombre;
	string especialidad;
	bool disponibilidad;
public:
	médico (int id, string n, string tipo, bool disponible): 
		idMédico(id), 
		nombre(n), 
		especialidad(tipo), 
		disponibilidad(true) {}
	void mostrarDatos() {
		cout << "ID del médico: " << idMédico << ".\n Nombre: " << nombre << ".\n Especialidad: " << especialidad << ".\n Disponibile:  " << (disponibilidad ? "Si" : "No") << endl;
	}
	void cambiarDisponibilidad(bool estado) { disponibilidad = estado; }
	int getID() { return idMédico; }
	string getEspecialidad() { return especialidad; }
};

class cita {
private:
	int idCita;
	string fechaHora;
	int idPaciente;
	int idMédico;
	int urgencia;
public:
	cita (int id, string fecha, int idp, int idm, int urgente):
		idCita(id),
		fechaHora(fecha),
		idPaciente(idp),
		idMédico(idm) {
		if (urgencia < 1) {
			this-> urgencia = 1;
			cout << "La urgencia es mínima.\n";
		}
		else if (urgencia >5) {
			this-> urgencia = 5;
			cout << "La urgencia es máxima.\n";
		}
		else {
			this-> urgencia = urgencia;
		}
	}
	void mostrarDatos() {
		cout << "ID de cita: " << idCita << ".\n Fecha y hora: " << fechaHora << ".\n ID del paciente: " << idPaciente << ".\n ID del médico: " << idMédico << ". \n Urgencia: " << urgencia << endl;
	}
	string getFechaHora() { return fechaHora; }
	int getUrgencia() { return urgencia; }

};

class servicio {
private:
	int idServicio;
	string tipoServicio;
public:
	servicio(int id, string tipo): 
		idServicio(id), 
		tipoServicio(tipo) {}
	void mostrarDatos() {
		cout << "ID de Servicio: " << idServicio << ".\n Tipo de servicio: " << tipoServicio << endl;
	};
};

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <médico> listaMédicos;
	vector <cita> listaCitas;
	vector <servicio> listaServicios;
public:
	void registrarPaciente(int id, string nombre, string fecha) {
		listaPacientes.push_back(paciente(id, nombre, fecha));
		cout << "Paciente registrado. \n";
	}
	void listadoPacientes() {
		cout << "Lista de pacientes: \n";
		for (auto& paciente : listaPacientes) {
			paciente.mostrarDatos();
		}
	}
	void registrarMédico(int id, string n, string tipo, bool disponible) {
		listaMédicos.push_back(médico(id, n, tipo, disponible));
		cout << "Médico registrado. \n";
	}
	void listadoMédicos() {
		cout << "Lista de médicos: \n";
		for (auto& médico : listaMédicos) {
			médico.mostrarDatos();
		}
	}
	void asignarCita(int id, string fecha, int idp, int idm, int urgente) {
		listaCitas.push_back(cita(id, fecha, idp, idm, urgente));
		cout << "Cita asignada. \n";
	}
	void listadoCitas() {
		cout << "Lista de citas: \n";
		for (auto& cita : listaCitas) {
			cita.mostrarDatos();
		}
	}
};