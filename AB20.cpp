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

void añadirCita(const string& archivoPaciente) {
	string nombre;
	int idPaciente;
	string médico;
	int idMédico;
	cout << "Nombre del paciente: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Número de identificación: ";
	cin >> idPaciente;
	cout << "Nombre del médico: ";
	cin.ignore();
	getline(cin, médico);
	string  = cifrado(texto, clave);
	entradas.push_back(texto);
	ofstream archivo(archivoPaciente, ios::app);
	if (archivo.is_open()) {
		archivo << textoCifrado << endl;
		archivo.close();
		cout << "Entrada añadida correctamente." << endl;
	}
	else {
		cout << "No se pudo abrir el archivo." << endl;
	}
}
void mostrarMenú() {
	cout << "\n Menú";
	cout << "1: Pacientes";
	cout << "2: Médicos";
	cout << "3: Citas";
	cout << "0: Salir";
	cout << "Seleccione una opción: ";
}
int main() {
		SetConsoleOutputCP(1252);
		string archivoPaciente = "paciente.csv";
		string archivoMédico = "médico.csv";
		string archivoCitas = "citas.csv";
		int opcion;

		do {
			mostrarMenú();
			cin >> opcion;

			switch (opcion) {
			case 1:
				cin >> opcion;
				switch (opcion) {
				case 1:


				break;
			case 2:
				añadirEntrada(nombreArchivo, entradas);
				break;
			case 3:
				borrarEntrada(nombreArchivo, entradas);
				break;
			case 4:
				borrarArchivo(nombreArchivo, entradas);
				break;
			case 0:
				cout << "Saliendo del programa.";
				break;
			default:
				cout << "Opción no disponible, por favor, elija una opción válida" << endl;
			}
		} while (opcion != 0);
		return 0;
	}