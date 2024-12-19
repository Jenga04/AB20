#include "Paciente.h"
#include "Médico.h"
#include "Cita.h"

class hospital {
private:
	vector <paciente> listaPacientes;
	vector <médico> listaMédicos;
	vector <cita> listaCitas;
public:
	void listadoPacientes() {
		cout << "Lista de pacientes:\n";
		for (auto& paciente : listaPacientes) {
			paciente.DatosPaciente();
		}
	}
	void registrarPaciente (paciente paciente) {
		listaPacientes.push_back(paciente);
	};

	void listadoMédicos() {
		cout << "Lista de médicos:\n";
		for (auto& médico : listaMédicos) {
			médico.datosMédico();
		}
	}
	void registrarMédico(médico medico) {
		listaMédicos.push_back(medico);
	}
	void listadoCitas() {
		cout << "Lista de citas: \n";
		for (auto& cita : listaCitas) {
			cita.datosCitas(); }
	}
	void añadirCita(cita cita) {
		listaCitas.push_back(cita);
	};