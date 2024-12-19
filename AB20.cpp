// AB20.cpp: define el punto de entrada de la aplicación.
//
#include "Windows.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Paciente.h"
#include "Médico.h"
#include "Cita.h"
#include "Hospital.h"

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
	hospital Hospital;
	SetConsoleOutputCP(1252);
	int opcion;

	do {
		mostrarMenú();
		cin >> opcion;

		switch (opcion) {
		case 1: {
			int opcionPaciente;
			switch (opcionPaciente) {
			case 1:
				Hospital.listadoPacientes();
				break;
			case 2: {
				int id;
				string nombre;
				cout 
