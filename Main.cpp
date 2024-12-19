// AB20.cpp: define el punto de entrada de la aplicación.
//
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include "Hospital.h"
#include "Windows.h"

using namespace std;

void mostrarMenu() {
	cout << "Menu \n";
	cout << "1: Pacientes \n\n";
	cout << "2: Medicos \n";
	cout << "3: Citas \n";
	cout << "4: Reporte \n";
	cout << "5: Respaldo de datos \n";
	cout << "0: Salir \n";
	cout << "Seleccione una opcion: ";
}

void menuPacientes(hospital& Paciente) {
	cout << "Pacientes \n\n";
	cout << "1: Lista de pacientes \n";
	cout << "2: Registrar paciente \n";
	cout << "3: Dar de baja un paciente \n";
	cout << "4: Modificar paciente \n";
	cout << "5: Buscar paciente \n";
	cout << "0: Volver al menu principal";
	cout << "¿Que desea realizar?";
	int opcionP;

	switch (opcionP) {
			case 1:
				Paciente.listadoPacientes();
				break;
			case 2: {
				int id;
				string n, fecha;
				cout << "Ingrese ID: ";
				cin >> id;
				cout << "Ingrese nombre: ";
				cin.ignore();
				getline(cin, n);
				cout << "Ingrese fecha de ingreso (DD/MM/AAAA): ";
				getline(cin, fecha);
				Paciente.registrarPaciente(paciente(id, n, fecha));
				cout << "Paciente registrado correctamente.\n";
				break;
			}
			case 0:
				cout << "Volviendo al menu principal \n";
			default:
				cout << "Elija una opcion valida.";
				break;
			} while (opcionP != 0);
}

void menuMedicos(hospital& Medico) {
	cout << "Medicos\n";
	cout << "1: Lista de medicos \n";
	cout << "2: Registrar medico \n";
	cout << "3: Dar de baja un medico \n";
	cout << "4: Modificar medico \n";
	cout << "5: Buscar medico \n";
	cout << "0: Volver al menu principal";
	cout << "¿Que desea realizar?";
	int opcionM;

	switch (opcionM) {
	case 1: 
		Medico.listadoMedicos();
		break;
	case 2: {
		int id;
		string nombre, tipo;
		bool disponibilidad;
		cout << "Ingrese ID: ";
		cin >> id;
		cout << "Ingrese nombre: ";
		cin.ignore();
		getline(cin, nombre);
		cout << "Ingrese su especialidad: ";
		getline(cin, tipo);
		cout << "Esta disponible? (1: Si, 0: no)";
		cin >> disponibilidad;
		cout << "Medico registrado correctamente.\n";
		Medico.registrarMedico(medico(id, nombre, tipo, disponibilidad));
		break;
		}
	case 0:
		cout << "Volviendo al menu principal \n";
	default:
		cout << "Elija una opcion valida.";
		break;
	} while (opcionM != 0);
}

void menuCitas(hospital& Cita) {
	cout << "Citas";
	cout << "1: Lista de citas \n";
	cout << "2: Añadir cita \n";
	cout << "3: Cancelar una cita \n";
	cout << "4: Modificar cita \n";
	cout << "5: Buscar cita \n";
	cout << "0: Volver al menu principal";
	cout << "¿Que desea realizar?";
	int opcionC;

	switch (opcionC) {
	case 1:
		Cita.listadoCitas();
		break;
	case 2: {
		int id, idp, idm, urgencia;
		string fecha;
		cout << "ID de la cita: ";
		cin >> id;
		cout << "ID del paciente: ";
		cin >> idp;
		cout << "ID del medico: ";
		cin >> idm;
		cout << "Fecha (DD-MM-YYYY)";
		cin >> fecha;
		cout << "Urgencia  (1 a 5): ";
		cin >> urgencia;
		Cita.añadirCita(cita(id, fecha, idp, idm, urgencia));
		break;
	}
	case 0:
		cout << "Volviendo al menu principal \n";
	default:
		cout << "Elija una opcion valida.";
		break;
	} while (opcionC != 0);
}

int main() {
	SetConsoleOutputCP(1252);
	hospital Hospital;
	int opcion;

	do {
		mostrarMenu();
		cin >> opcion;

		switch (opcion) {
		case 1:
			menuPacientes(Hospital);
			break;
		case 2:
			menuMedicos(Hospital);
			break;
		case 3:
			menuCitas(Hospital);
			break;
		}
	} while (opcion != 0);
	return 0;
}