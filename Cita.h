class cita {
private:
	int idCita;
	string fechaHora;
	int idPaciente;
	int idM�dico;
	int urgencia;
public:
	cita(int id, string fecha, int idp, int idm, int urgente) :
		idCita(id),
		fechaHora(fecha),
		idPaciente(idp),
		idM�dico(idm) {
		this->urgencia = (urgencia < 1) ? 1 : (urgencia > 5) ? 5 : urgencia;
	}

	void datosCitas() {
		cout << "ID de cita: " << idCita << ".\nFecha y hora: " << fechaHora << ".\nID del paciente: " << idPaciente << ".\nID del m�dico: " << idM�dico << ". \nUrgencia: " << urgencia << endl;
	}

	int getId() {
		return idCita;
	}
	string getFechaHora() { 
		return fechaHora; 
	}
	int getUrgencia() { 
		return urgencia; 
	}

	void setFechaHora(const string& nuevaFecha) {
		fechaHora = nuevaFecha;
	}
};