class cita {
private:
	int idCita;
	string fechaHora;
	int idPaciente;
	int idMedico;
	int urgencia;
public:
	cita(int id, string fecha, int idp, int idm, int urgente) :
		idCita(id),
		fechaHora(fecha),
		idPaciente(idp),
		idMedico(idm) {
		this->urgencia = (urgencia < 1) ? 1 : (urgencia > 5) ? 5 : urgencia;
	}

	void datosCitas() {
		cout << "ID de cita: " << idCita << ".\nFecha y hora: " << fechaHora << ".\nID del paciente: " << idPaciente << ".\nID del médico: " << idMedico << ". \nUrgencia: " << urgencia << endl;
	}

	int getIdPaciente() {
		return idPaciente;
	}
	int getIDMedico(){
		return idMedico;
		}
	string getFechaHora() { 
		return fechaHora; 
	}
	void setFechaHora(const string& nuevaFecha) {
		fechaHora = nuevaFecha;
	}
	int setUrgencia() { 
		return urgencia; 
	}
};