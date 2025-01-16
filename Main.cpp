#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Hospital.h"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

using namespace std;

void mostrarMenu() {
	cout << "Menu \n\n";
	cout << "1: Pacientes \n";
	cout << "2: Medicos \n";
	cout << "3: Citas \n";
	cout << "4: Respaldo de datos \n";
	cout << "0: Salir \n";
	cout << "Seleccione una opcion: ";
}

void menuPacientes(hospital& hospital) {
	int opcionPacientes;
	do {
		cout << "Pacientes \n\n";
		cout << "1: Lista de pacientes \n";
		cout << "2: Registrar paciente \n";
		cout << "3: Eliminar paciente \n";
		cout << "4: Modificar paciente \n";
		cout << "5: Buscar paciente \n";
		cout << "0: Volver al menu principal\n";
		cout << "Que desea realizar? ";
		cin >> opcionPacientes;

		switch (opcionPacientes) {
		case 1: 
			hospital.listadoPacientes();
			break;
		case 2: {
			int id;
			string n;
			cout << "ID del paciente: ";
			cin >> id;
			cout << "Nombre del paciente: ";
			cin.ignore();
			getline(cin, n);
			hospital.registrarPaciente(id, n, "");
			break;
		}
		case 3: {
			int idPaciente;
			cout << "Ingrese el ID del paciente a eliminar ";
			cin >> idPaciente;
			hospital.eliminarPaciente(idPaciente);
			break;
		}
		case 4: {
			int idPaciente;
			string nuevaFechaIngreso, nuevoHistorial;
			cout << "Ingrese el ID del paciente: ";
			cin >> idPaciente;
			cout << "Nueva fecha de ingreso: ";
			getline(cin, nuevaFechaIngreso);
			hospital.modificarPaciente(idPaciente, nuevaFechaIngreso, nuevoHistorial);
			break;
		}
		case 0:
			cout << "Volviendo al menu principal \n";
			break;
		default:
			cout << "Elija una opcion valida. \n";
			break;
		}
	} while (opcionPacientes != 0);
}


void menuMedicos(hospital& hospital) {
	int opcionMedicos;
	do {
		cout << "Medicos\n\n";
		cout << "1: Lista de medicos \n";
		cout << "2: Registrar medico \n";
		cout << "3: Eliminar medico \n";
		cout << "4: Modificar medico \n";
		cout << "5: Buscar medico \n";
		cout << "0: Volver al menu principal\n";
		cout << "Que desea realizar? ";
		cin >> opcionMedicos;

		switch (opcionMedicos) {
		case 1:
			hospital.listadoMedicos();
			break;
		case 2: {
			int id;
			string n, tipo;
			bool disponible;
			cout << "Ingrese ID: ";
			cin >> id;
			cout << "Ingrese nombre: ";
			cin.ignore();
			getline(cin, n);
			cout << "Ingrese su especialidad: ";
			getline(cin, tipo);
			cout << "Esta disponible? (1: Si, 0: no)";
			cin >> disponible;
			hospital.registrarMedico(id, n, tipo, disponible);
			break;
		}
		case 3: {
			int idMedico;
			cout << "Ingrese el ID del medico a eliminar: ";
			cin >> idMedico;
			hospital.eliminarMedico(idMedico);
			break;
		}
		case 0:
			cout << "Volviendo al menu principal \n";
			break;
		default:
			cout << "Elija una opcion valida.\n";
			break;
		}
	} while (opcionMedicos != 0);
}

void menuCitas(hospital& hospital) {
	int opcionCitas;
	do {
		cout << "Citas\n\n";
		cout << "1: Lista de citas \n";
		cout << "2: Añadir cita \n";
		cout << "3: Cancelar una cita \n";
		cout << "4: Modificar cita \n";
		cout << "5: Buscar cita \n";
		cout << "0: Volver al menu principal\n";
		cout << "Que desea realizar? ";
		cin >> opcionCitas;

		switch (opcionCitas) {
		case 1:
			hospital.listadoCitas();
			break;
		case 2: {
			int id, idp, idm, urgente;
			string fechaCita, horaCita;
			cout << "ID de la cita: ";
			cin >> id;
			cout << "ID del paciente: ";
			cin >> idp;
			cout << "ID del medico: ";
			cin >> idm;
			cout << "Fecha (DD/MM/YYYY)";
			cin >> fechaCita;
			cout << "Hora: ";
			cin >> horaCita;
			cout << "Urgencia  (1 a 5): \n";
			cin >> urgente;
			hospital.registrarCita(id, fechaCita, horaCita, idp, idm, urgente);
			break;
		}
		case 3: {
			int idCita;
			cout << "Ingrese el ID de la cita a cancelar: ";
			cin >> idCita;
			hospital.cancelarCita(idCita);
			break;
		}
		case 0:
			cout << "Volviendo al menu principal \n";
			break;
		default:
			cout << "Elija una opcion valida. ";
			break;
		}
	} while (opcionCitas != 0);
}

int main() {
	hospital hospital ("pacientes.csv", "medicos.csv", "citas.csv");
	int opcion;

	do {
		mostrarMenu();
		cin >> opcion;

		switch (opcion) {
		case 1:
			menuPacientes(hospital);
			break;
		case 2:
			menuMedicos(hospital);
			break;
		case 3:
			menuCitas(hospital);
			break;
		case 0:
			cout << "Saliendo";
			break;
		default:
			cout << "Elija una opcion valida\n";
			break;
		}	
	} while (opcion != 0);
	return 0;
}