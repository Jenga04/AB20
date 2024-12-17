class hospital {
private:
	vector <paciente> listaPacientes;
	vector <m�dico> listaM�dicos;
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
