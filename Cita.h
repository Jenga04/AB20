#include <iostream>
using namespace std;

class cita {
private:
	int idCita;
	string fechaHora;
	int idPaciente;
	int idMedico;
	int urgencia;
public:
	cita(int id, string fecha, int idp, int idm, int urgente);

	int getIdCita();
	string getFechaHora();
	int getIdPaciente();
	int getIDMedico();
	int getUrgencia();

	void setFechaHora(const string& nuevaFechaHora) {
		fechaHora = nuevaFechaHora;
	}
	void datosCitas();
};