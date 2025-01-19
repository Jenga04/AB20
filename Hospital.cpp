#include "Hospital.h"
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;


hospital::hospital(const string& archivoPacientes, const string& archivoMedicos, const string& archivoCitas):
	archivoPacientes(archivoPacientes), 
	archivoMedicos(archivoMedicos), 
	archivoCitas(archivoCitas) {}

//Validaciones de fecha y hora

bool bisiesto(int anio) {
	return (anio % 4 == 0 &&(anio % 100 != 0 || anio % 400 == 0));
}

bool mesValido(int mes) {
	return mes >= 1 && mes <= 12;
}

bool diaValido(int dia, int mes, int anio) {
	vector<int> diasPorMes = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (bisiesto(anio)) {
		diasPorMes[1] = 29;
	}
	return dia >= 1 && dia <= diasPorMes[mes - 1];
}

bool hospital::validarFecha(const string& fecha) {
	int dia, mes, anio;
	char barraLateral;
	stringstream defFecha(fecha);
	defFecha >> dia >> barraLateral >> mes >> barraLateral >> anio;

	if (defFecha.fail() || barraLateral != '/' || !mesValido(mes) || !diaValido(dia, mes, anio)) {
		return false;
	}
	return true;
	
	//fecha actual
	time_t fechaExacta = time(nullptr);
	tm* diaLocal = localtime(&fechaExacta);

	int diaExacto = diaLocal->tm_mday;
	int mesExacto = diaLocal->tm_mon+1;
	int anioExacto = diaLocal->tm_year+1900;

	//Comprobar la fecha actual
	if (anio < anioExacto || (anio == anioExacto && mes < mesExacto) || (anio == anioExacto && mes == mesExacto && dia < diaExacto)) {
		return false;
	}
	return true;
}
	
bool hospital::validarHora(const string& fecha, const string& hora){
	int horas, minutos;
	char puntos;
	stringstream defHora(hora);
	defHora >> horas >> puntos >> minutos;

	if (defHora.fail() || puntos != ':' || horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
		return false;
	} 
	return true;
}

//Opciones de pacientes

void hospital::registrarPaciente(
	int id,
	const string& n,
	const string& fecha) {
	auto buscarPaciente = find_if(listaPacientes.begin(), listaPacientes.end(),
		[id](const paciente& listaPacientes) {
			return listaPacientes.getIdPaciente() == id;
		});
	if (buscarPaciente != listaPacientes.end()) {
		cout << "Este ID de paciente ya existe. \n";
		return;
	}
	listaPacientes.push_back(paciente(id, n, fecha));
	guardarPaciente();
	cout << "Paciente registrado correctamente. \n";
}

void hospital::eliminarPaciente(int idPaciente) {
	auto buscarPaciente = find_if(listaPacientes.begin(), listaPacientes.end(),
		[idPaciente](const paciente& listaPacientes) {
			return listaPacientes.getIdPaciente() == idPaciente;
		});
	if (buscarPaciente != listaPacientes.end()) {
		listaPacientes.erase(buscarPaciente);
		cout << "Paciente " << idPaciente << "Eliminado correctamente.\n";
	}
	else {
		cout << "Paciente no enccontrado.\n";
	}
}

void hospital::modificarPaciente(int idPaciente, string nuevaFechaIngreso, string nuevoHistorial) {
	auto buscarPaciente = find_if(listaPacientes.begin(), listaPacientes.end(),
		[idPaciente](const paciente& listaPacientes) {
		return listaPacientes.getIdPaciente() == idPaciente;
		});
	if (buscarPaciente != listaPacientes.end()) {
		buscarPaciente->setFechaIngreso(nuevaFechaIngreso);
		cout << "Paciente " << idPaciente << " ha sido modificado\n";
	}
	else {
		cout << "Paciente no encontrado.\n";
	}
}

void hospital::listadoPacientes() const {
	vector<paciente> pacientes = listaPacientes;
	sort(pacientes.begin(), pacientes.end(), [](const paciente& primero, const paciente& ultimo) {
		return primero.getIdPaciente() < ultimo.getIdPaciente();
		});
	cout << "Lista de pacientes:\n";
	for (auto& paciente : listaPacientes) {
		paciente.DatosPaciente();
	}
}

void hospital::listaPacientesNombre() const {
	cout << "Lista por nombre: \n";
	vector<paciente> pacientes = listaPacientes;
	sort(pacientes.begin(), pacientes.end(), [](const paciente& a, const paciente& z) {
		return a.getNombrePaciente() < z.getNombrePaciente();
		});
	for (const auto& paciente : pacientes) {
		paciente.DatosPorNombre();
	}
}

void hospital::listaPacientesFecha() const {
	cout << "Lista por fecha: \n";
	vector<paciente> pacientes = listaPacientes;
	sort(pacientes.begin(), pacientes.end(), [](const paciente& fechaCercana, const paciente& fechaLejana) {
		return fechaCercana.getFechaIngreso() > fechaLejana.getFechaIngreso();
		});
	for (const auto& paciente : pacientes) {
		paciente.DatosPorFecha();
	}
}

void hospital::buscarPaciente(const string& nombre) const {

	bool encontrado = false;

	for (const auto& paciente : listaPacientes) {
		string nombrePaciente = paciente.getNombrePaciente();
		string nombreBuscado = nombre;

		if (nombrePaciente.find(nombreBuscado) != string::npos) {
			paciente.DatosPaciente();
			encontrado = true;
		}
	}
	if (!encontrado) {
		cout << "No se encontraron pacientes con ese nombre. \n";
	}
}

//Opciones de medicos

void hospital::registrarMedico(
	int id,
	const string& n,
	const string& tipo,
	bool disponible) {
	auto buscarMedico = find_if(listaMedicos.begin(), listaMedicos.end(),
		[id](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == id;
		});
	if (buscarMedico != listaMedicos.end()) {
		cout << "Este ID de medico ya existe. \n";
	}
	listaMedicos.push_back(medico(id, n, tipo, disponible));
	guardarMedico();
	cout << "Medico registrado correctamente. \n";
}
void hospital::eliminarMedico(int idMedico) {
	auto buscarMedico = find_if(listaMedicos.begin(), listaMedicos.end(),
		[idMedico](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == idMedico;
		});
	if (buscarMedico != listaMedicos.end()) {
		listaMedicos.erase(buscarMedico);
		cout << "Medico " << idMedico << "Eliminado correctamente.\n";
	}
	else {
		cout << "Medico no enccontrado.\n";
	}
}

void hospital::modificarMedico(int idMedico, bool nuevaDisponibilidad) {
	auto buscarMedico = find_if(listaMedicos.begin(), listaMedicos.end(),
		[idMedico](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == idMedico;
		});
	if (buscarMedico != listaMedicos.end()) {
		buscarMedico->setDisponibilidad(nuevaDisponibilidad);
		cout << "Medico " << idMedico << " modificado correctamente.\n";
	}
	else {
		cout << "Medico no encontrado.\n";
	}
}
void hospital::listadoMedicos() const {
	vector<medico> medicos = listaMedicos;
	sort(medicos.begin(), medicos.end(), [](const medico& primero, const medico& ultimo) {
		return primero.getIdMedico() < ultimo.getIdMedico();
		});
	for (const auto& medico : medicos) {
		medico.datosMedico();
		cout << "Lista de medicos:\n";
		for (auto& medico : listaMedicos) {
			medico.datosMedico();
		}
	}
}
void hospital::listaMedicosEspecialidad() const {
	cout << "Lista de medicos segun su especialidad:\n";

	vector<medico> medicos = listaMedicos;
	sort(medicos.begin(), medicos.end(), [](const medico& a, const medico& z) {
		return a.getEspecialidad() < z.getEspecialidad();
		});
	for (const auto& medico : medicos) {
		medico.datosPorEspecialidad();
	}
}

void hospital::listaMedicosDisponibles() const {
	cout << "Medicos disponibles:\n";
	for (const auto& medico : listaMedicos) {
		if (medico.estaDisponible()) {
			medico.datosPorDisponibilidad();
		}
	}
	cout << "Medicos no disponobles:\n";
	for (const auto& medico : listaMedicos) {
		if (!medico.estaDisponible()) {
			medico.datosPorDisponibilidad();
		}
	}
}

//Opciones de citas

void hospital::registrarCita(
	int id,
	const string& fecha,
	const string& hora,
	int idp,
	int idm,
	int urgente) {
	auto buscarCita = find_if(listaCitas.begin(), listaCitas.end(),
		[id](const cita& listaCitas) {
			return listaCitas.getIdCita() == id;
		});
	if (buscarCita != listaCitas.end()) {
		cout << "Este ID de cita ya existe. \n ";
		return;
	}
	auto buscarPaciente = find_if(listaPacientes.begin(), listaPacientes.end(),
		[idp](const paciente& listaPacientes) {
			return listaPacientes.getIdPaciente() == idp;
		});
	if (buscarPaciente == listaPacientes.end()) {
		cout << "ID de paciente no valido.\n";
		return;
	}
	auto buscarMedico = find_if(listaMedicos.begin(), listaMedicos.end(),
		[idm](const medico& listaMedicos) {
			return listaMedicos.getIdMedico() == idm;
		});
	if (buscarMedico == listaMedicos.end()) {
		cout << "ID de medico no valido.\n";
		return;
	}
	if (!buscarMedico->estaDisponible()) {
		cout << "Este medico no esta disponible. \n";
		return;
	}
	if (!validarFecha(fecha) || !validarHora(fecha, hora)) {
		cout << "Fecha u hora invalidas. Intenta de nuevo.\n";
		return;
	}
	listaCitas.push_back(cita(id, fecha, hora, idp, idm, urgente));
	guardarCita();
	cout << "Cita registrada correctamente.\n";
	for (auto& paciente : listaPacientes) {
		if (paciente.getIdPaciente() == idp) {
			paciente.setFechaIngreso(fecha);
			break;
		}
	}
}

void hospital::cancelarCita(int idCita) {
	auto buscarCita = find_if(listaCitas.begin(), listaCitas.end(),
		[idCita](const cita& listaCitas) {
			return listaCitas.getIdCita() == idCita;
		});
	if (buscarCita != listaCitas.end()) {
		listaCitas.erase(buscarCita);
		cout << "Cita " << idCita << "Eliminada correctamente.\n";
	}
	else {
		cout << "Cita no enccontrada.\n";
	}
}
void hospital::modificarCita(int idCita, string nuevaFechaCita, string nuevaHoraCita) {
	if (!validarFecha(nuevaFechaCita) || !validarHora(nuevaFechaCita, nuevaHoraCita)) {
		cout << "Fecha u hora invalidas. Intenta de nuevo.\n";
		return;
	}
	auto buscarCita = find_if(listaCitas.begin(), listaCitas.end(),
		[idCita](const cita& listaCitas) {
			return listaCitas.getIdCita() == idCita;
		});
	if (buscarCita != listaCitas.end()) {
		buscarCita->setFechaCita(nuevaFechaCita);
		buscarCita->setHoraCita(nuevaHoraCita);
		cout << "Cita " << idCita << " modificada correctamente\n";
		for (auto& paciente : listaPacientes) {
			if (paciente.getIdPaciente() == buscarCita->getIdPaciente()) {
				paciente.setFechaIngreso(nuevaFechaCita);
				break;
			}
		}
	}
	else {
		cout << "Cita no encontrada.\n";
	}
}

void hospital::listadoCitas() const {
	vector<cita> citas = listaCitas;
	sort(citas.begin(), citas.end(), [](const cita& primero, const cita& ultimo) {
		return primero.getIdCita() < ultimo.getIdCita();
		});
	cout << "Lista de citas: \n";
	for (auto& cita : listaCitas) {
		cita.datosCitas();
	}
}

void hospital::listaCitasUrgencia() const {
	cout << "Lista de citas urgentes: \n";

	vector<cita> citas = listaCitas;
	sort(citas.begin(), citas.end(), [](const cita& urgenciaMayor, const cita& urganciaMenor) {
		return urgenciaMayor.getUrgencia() > urganciaMenor.getUrgencia();
		});
	for (const auto& cita : citas) {
		cita.datosPorUrgencia();
	}
}

void hospital::listaCitasFecha() const {
	cout << "Lista de citas por fecha: \n";

	vector <cita> citas = listaCitas;
	sort(citas.begin(), citas.end(), [](const cita& fechaCercana, const cita& fechaLejana) {
		return fechaCercana.getFechaCita() > fechaLejana.getFechaCita();
		});
	for (const auto& cita : citas) {
		cita.datosPorFecha();
	}
}

//Guardar datos en los archivos

void hospital::guardarPaciente(){
	ofstream archivo(archivoPacientes);
	archivo << "ID, Nombre, Fecha de ingreso \n";

	for (auto& paciente : listaPacientes) {
		archivo << paciente.getIdPaciente() << "," << paciente.getNombrePaciente() << "," << paciente.getFechaIngreso() << "\n";
	}
	archivo.close();
}

void hospital::guardarMedico(){
	ofstream archivo(archivoMedicos);
	archivo << "ID, Nombre, Especialidad, Disponibilidad \n";

	for (const auto& medico : listaMedicos) {
		archivo << medico.getIdMedico() << "," << medico.getNombreMedico() << "," << medico.getEspecialidad() << "," << (medico.estaDisponible() ? "1" : "0") << "\n";
	}
	archivo.close();
}

void hospital::guardarCita() {
	ofstream archivo(archivoCitas);
	archivo << "ID, Fecha, Hora, ID del paciente, ID del medico, Urgencia \n";

	for (const auto& cita : listaCitas) {
		archivo << cita.getIdCita() << "," << cita.getFechaCita() << "," << cita.getHoraCita()<< "," << cita.getIdPaciente() << "," << cita.getIdMedico() << "," << cita.getUrgencia() << "\n";
	}
	archivo.close();
}

//Cargar datos del archivo

void hospital::cargarPaciente() {
	ifstream archivo(archivoPacientes);
	if (!archivo) {
		cout << "No se pudo abrir el archivo. \n";
		return;
	}
	string linea;
	while (getline(archivo, linea)) {
		stringstream leerLinea(linea);
		int id;
		string nombre, fechaIngreso;

		leerLinea >> id;
		getline(leerLinea, nombre, ',');
		getline(leerLinea, fechaIngreso, ',');

		listaPacientes.push_back(paciente(id, nombre, fechaIngreso));
	}
	archivo.close();
	cout << "Pacientes cargados correctamente. \n";
}

void hospital::cargarMedico() {
	ifstream archivo(archivoMedicos);
	if (!archivo) {
		cout << "No se pudo abrir el archivo. \n";
		return;
	}
	string linea;
	while (getline(archivo, linea)) {
		stringstream leerLinea(linea);
		int id;
		string nombre, especialidad, disponible;
		bool disponibilidad;

		leerLinea >> id;
		getline(leerLinea, nombre, ',');
		getline(leerLinea, especialidad, ',');
		getline(leerLinea, disponible, ',');

		disponibilidad = (disponible == "Disponible");


		listaMedicos.push_back(medico(id, nombre, especialidad, disponibilidad));
	}
	archivo.close();
	cout << "Medicos cargados correctamente. \n";
}
void hospital::cargarCita() {
	ifstream archivo(archivoCitas);
	if (!archivo) {
		cout << "No se pudo abrir el archivo. \n";
		return;
	}

	string linea;
	while (getline(archivo, linea)) {
		stringstream leerLinea(linea);
		int id, idp, idm, urgente;
		string fecha, hora;

		leerLinea >> id;
		getline(leerLinea, fecha, ',');
		getline(leerLinea, hora, ',');
		leerLinea >> idp;
		leerLinea >> idm;
		leerLinea >> urgente;

		listaCitas.push_back(cita(id, fecha, hora, idp, idm, urgente));
	}
	archivo.close();
	cout << "Citas cargadas correctamente. \n";
}