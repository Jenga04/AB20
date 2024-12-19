#include "Paciente.h"
#include "M�dico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <m�dico> listaM�dicos;
	vector <cita> listaCitas;
public:
	void listadoPacientes() {
		cout << "Lista de pacientes:\n";
		for (auto& paciente : listaPacientes) {
			paciente.DatosPaciente();
		}
	}
	void registrarPaciente(paciente Paciente) {
		listaPacientes.push_back(Paciente);
	};
	void listadoM�dicos() {
		cout << "Lista de m�dicos:\n";
		for (auto& m�dico : listaM�dicos) {
			m�dico.datosM�dico();
		}
	}
	void registrarM�dico(m�dico medico) {
		listaM�dicos.push_back(medico);
	}
	void listadoCitas() {
		cout << "Lista de citas: \n";
		for (auto& cita : listaCitas) {
			cita.datosCitas();
		}
	}
	void a�adirCita(cita Cita) {
		listaCitas.push_back(Cita);
	}
};