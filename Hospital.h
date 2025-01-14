#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <medico> listaMedicos;
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
	void listadoMedicos() {
		cout << "Lista de médicos:\n";
		for (auto& medico : listaMedicos) {
			medico.datosMedico();
		}
	}
	void registrarMedico(medico Medico) {
		listaMedicos.push_back(Medico);
	}
	void listadoCitas() {
		cout << "Lista de citas: \n";
		for (auto& cita : listaCitas) {
			cita.datosCitas();
		}
	}
	void añadirCita(cita Cita) {
		listaCitas.push_back(Cita);
	}
};