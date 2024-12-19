// AB20.cpp: define el punto de entrada de la aplicación.
//
#include "Windows.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
/* #include "Paciente.h"
#include "Médico.h"
#include "Cita.h"
#include "Hospital.h"*/

using namespace std;

void mostrarMenú() {
	cout << "Menú \n";
	cout << "1: Pacientes \n";
	cout << "2: Médicos \n";
	cout << "3: Citas \n";
	cout << "4: Reporte \n";
	cout << "5: Respaldo de datos \n";
	cout << "0: Salir \n";
	cout << "Seleccione una opción: ";
}
int main() {
	SetConsoleOutputCP(1252);
	int opcion;

	do {
		mostrarMenú();
		cin >> opcion;

		switch (opcion) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			break;
		default:
			cout << "Elija una opción válida. \n\n";
			break;
		}
	} while (opcion != 0);
	return 0;
}
