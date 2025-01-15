#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include "Hospital.h"

using namespace std;

void mostrarMenu() {
	cout << "Menu \n";
	cout << "1: Pacientes \n\n";
	cout << "2: Medicos \n";
	cout << "3: Citas \n";
	cout << "5: Respaldo de datos \n";
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
		cout << "0: Volver al menu principal";
		cout << "¿Que desea realizar?";
		cin >> opcionPacientes;

		switch (opcionPacientes) {
		case 1: 
			hospital.listaPacientes();
			break;
		case 2: {
			int id;
			string n, fecha;
			cout << "ID del paciente: ";
			cin >> id;
			cout << "Nombre del paciente: ";
			cin.ignore();
			getline(cin, n);
			cout << "Fecha de ingreso (DD/MM/AAAA): ";
			getline(cin, fecha);
			hospital.registrarPaciente(id, n, fecha);
			break;
		}
		case 0:
			cout << "Volviendo al menu principal \n";
		default:
			cout << "Elija una opcion valida.";
			break;
		}
	} while (opcionPacientes != 0);
}


void menuMedicos(hospital& hospital) {
	int opcionMedicos;
	do {
	cout << "Medicos\n";
	cout << "1: Lista de medicos \n";
	cout << "2: Registrar medico \n";
	cout << "3: Dar de baja un medico \n";
	cout << "4: Modificar medico \n";
	cout << "5: Buscar medico \n";
	cout << "0: Volver al menu principal";
	cout << "¿Que desea realizar?";


	switch (opcionMedicos) {
	case 1:
		hospital.listaMedicos();
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
		cout << "Medico registrado correctamente.\n";
		hospital.registrarMedico(id, n, tipo, disponible);
		break;
	}
	case 0:
		cout << "Volviendo al menu principal \n";
	default:
		cout << "Elija una opcion valida.";
		break;
	}
	} while (opcionMedicos != 0);
}

void menuCitas(hospital& hospital) {
	int opcionCitas;
	do {
		cout << "Citas";
		cout << "1: Lista de citas \n";
		cout << "2: Añadir cita \n";
		cout << "3: Cancelar una cita \n";
		cout << "4: Modificar cita \n";
		cout << "5: Buscar cita \n";
		cout << "0: Volver al menu principal";
		cout << "¿Que desea realizar?";
		cin >> opcionCitas;

		switch (opcionCitas) {
		case 1:
			hospital.listaCitas();
			break;
		case 2: {
			int id, idp, idm, urgente;
			string fecha;
			cout << "ID de la cita: ";
			cin >> id;
			cout << "ID del paciente: ";
			cin >> idp;
			cout << "ID del medico: ";
			cin >> idm;
			cout << "Fecha (DD/MM/YYYY)";
			cin >> fecha;
			cout << "Urgencia  (1 a 5): ";
			cin >> urgente;
			hospital.registrarCita(id, fecha, idp, idm, urgente);
			break;
		}
		case 0:
			cout << "Volviendo al menu principal \n";
		default:
			cout << "Elija una opcion valida.";
			break;
		}
	} while (opcionCitas != 0);
}

int main() {
	hospital hospital;
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
		}
	} while (opcion != 0);
	return 0;
}