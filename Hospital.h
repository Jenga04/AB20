#include "Paciente.h"
#include "M�dico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <m�dico> listaM�dicos;
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
	void registrarM�dico(int id, string n, string tipo, bool disponible) {
		listaM�dicos.push_back(m�dico(id, n, tipo, disponible));
		cout << "M�dico registrado.\n";
	}
	void listadoM�dicos() {
		cout << "Lista de m�dicos:\n";
		for (auto& m�dico : listaM�dicos) {
			m�dico.mostrarDatos();
		}
	}
	void a�adirCita(const string& archivoPaciente) {
		string nombre;
		int idPaciente;
		string m�dico;
		int idM�dico;
		cout << "Nombre del paciente: ";
		cin.ignore();
		getline(cin, nombre);
		cout << "N�mero de identificaci�n: ";
		cin >> idPaciente;
		cout << "Nombre del m�dico: ";
		cin.ignore();
		getline(cin, m�dico);

	}
};
