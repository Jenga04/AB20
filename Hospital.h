#include "Paciente.h"
#include "Médico.h"
#include "Cita.h"
#include <vector>

class hospital {
private:
	vector <paciente> listaPacientes;
	//vector <médico> listaMédicos;
	//vector <cita> listaCitas;
public:
	void registrarPaciente (paciente paciente) {
		listaPacientes.push_back(paciente);
	};
	void listadoPacientes() {
		for (auto& paciente : listaPacientes) {
			paciente.DatosPaciente();
		}
	}
	void registrarMédico(médico medico) {
		listaMédicos.push_back(medico);
	}

	void listadoMédicos() {
		cout << "Lista de médicos:\n";
		for (auto& médico : listaMédicos) {
			médico.datosMédico();
		}
	}
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
		getline(cin, médico);*/