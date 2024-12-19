// AB20.cpp: define el punto de entrada de la aplicación.
//
#include "Windows.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include"Paciente.h"
#include "Médico.h"
#include "Cita.h"
#include "Hospital.h"

using namespace std;

void mostrarMenú() {
	cout << "Menú \n";
	cout << "1: Pacientes \n\n";
	cout << "2: Médicos \n";
	cout << "3: Citas \n";
	cout << "4: Reporte \n";
	cout << "5: Respaldo de datos \n";
	cout << "0: Salir \n";
	cout << "Seleccione una opción: ";
}

void menuPacientes(hospital& Hospital) {
	cout << "Pacientes \n\n";
	cout << "Lista de pacientes \n";
	cout << "2: Registrar paciente \n";
	cout << "3: Dar de baja un paciente \n";
	cout << "4: Modificar paciente \n";
	cout << "5: Buscar paciente \n";
	cout << "0: Volver al menú principal";
	cout << "¿Qué desea realizar?";
	int opcionP;

	switch (opcionP) {
			case 1: {
				int id;
				string nombre, fecha;
				cout << "Ingrese ID: ";
				cin >> id;
				cout << "Ingrese nombre: ";
				cin.ignore();
				getline(cin, nombre);
				cout << "Ingrese fecha de ingreso (DD/MM/AAAA): ";
				getline(cin, fecha);
				Hospital.registrarPaciente(paciente(id, nombre, fecha));
				cout << "Paciente agregado correctamente.\n";
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				int opcionBP;
				cout << "";
				break;
			}
			case 5:
				Hospital.listadoPacientes();
				break;
			case 0:
				cout << "Volviendo al menú principal \n";
			default:
				cout << "Elija una opción válida.";
				break;
			} while (opcionP != 0);
}

int main() {
	SetConsoleOutputCP(1252);
	hospital Hospital;
	int opcion;
	int opcionP;
	int opcionM;
	int opcionC;
	int opcionR;
	int opcionB;
	int opcionBP;
	int opcionBM;

	do {
		mostrarMenú();
		cin >> opcion;

		switch (opcion) {
		case 1:
			menuPacientes(Hospital);
			break;
		case 2:
			menuMédicos

	} while (opcion != 0);
};