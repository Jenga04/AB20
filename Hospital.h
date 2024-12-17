class hospital {
private:
	vector <paciente> listaPacientes;
	vector <médico> listaMédicos;
	vector <cita> listaCitas;
public:
	void registrarPaciente(int id, string nombre, string fecha) {
		listaPacientes.push_back(paciente(id, nombre, fecha));
		cout << "Paciente registrado.\n";
	}
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
	void asignarCita(int id, string fecha, int idp, int idm, int urgente) {
		listaCitas.push_back(cita(id, fecha, idp, idm, urgente));
		cout << "Cita asignada.\n";
	}
	void listadoCitas() {
		cout << "Lista de citas:\n";
		for (auto& cita : listaCitas) {
			cita.mostrarDatos();
		}
	}
};
