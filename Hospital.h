#include "Paciente.h"
#include "Médico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <médico> listaMédicos;
	vector <cita> listaCitas;
public:
	void registrarPaciente(paciente paciente) {
		listaPacientes.push_back(paciente);
	};
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
};
