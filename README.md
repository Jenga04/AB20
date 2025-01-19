# Proyecto de Sistema de Gestión Hospitalaria

Este proyecto es una aplicación en C++ diseñada para gestionar pacientes, medicos y citas en un hospital. El sistema permite registrar, modificar, listar y eliminar datos relacionados con estos elementos, ademas de validar entradas como fechas y horas.

## Funcionalidades Principales

### Gestión de Pacientes
- Registrar paciente: Permite añadir un nuevo paciente al sistema, asignandole un ID y un nombre. La fecha de ingreso se actualiza automaticamente al crear una cita.
- Modificar paciente: Actualiza la informacion de un paciente existente.
- Listar pacientes: Muestra una lista ordenada de pacientes según su ID, fecha de ingreso o su nombre, segun la eleccion.
- Eliminar paciente: Elimina un paciente del sistema.

### Gestión de Medicos
- Registrar medico: Agrega un nuevo medico, incluyendo su ID, nombre, especialidad y disponibilidad.
- Modificar medico: Cambia los datos de un medico existente.
- Listar medicos: Presenta la lista de medicos segun su ID, especialidad o disponibilidad, segun la eleccion.
- Eliminar medico: Remueve un medico del sistema.

### Gestión de Citas
- Registrar cita: Asocia un medico y un paciente a una cita con validaciones para fechas, horas y disponibilidad del medico.
- Modificar cita: Cambia la fecha y hora de una cita existente. Si se modifica la fecha, tambien se actualiza la fecha de ingreso del paciente.
- Listar citas: Muestra todas las citas registradas segun su ID, las fechas y el nivel de urgencia.
- Cancelar cita: Elimina una cita especifica.

## Validaciones

### Fechas
- Formato: Las fechas deben estar en el formato DD/MM/AAAA.
- Rango: Las fechas deben ser validas (ejemplo: no permitir 32/01/2025) y no pueden ser anteriores al dia actual.

### Horas
- Formato: Las horas deben estar en el formato HH:MM en un rango de 24 horas.

### ID
- Los ID deben ser numericos. Si el usuario ingresa letras, entra en bucle infinito.

## Estructura de Archivos

### Archivos CSV
El sistema utiliza archivos csv para guardar y cargar datos de pacientes, medicos y citas:
- pacientes.csv
- medicos.csv
- citas.csv

Cada archivo sigue un formato especifico que es manejado por las funciones guardar y cargar implementadas en el codigo.

### Ejemplo de Formato (pacientes.csv):

ID,Nombre,Fecha de Ingreso,Historial
1,Jeremy Atkinson,20/01/2025
2,Adrian Pliego ,21/01/2025,


## Requisitos del Sistema
- Compilador C++.
- Librerías estandar: iostream, vector, string, fstream, sstream, algorithm.

## Ejecucion
1. Compile y ejecute el programa.
2. Siga las instrucciones del menu principal para navegar entre las opciones.

## Mejoras Futuras
- Implementar un sistema de roles para usuarios (administrador, médico, recepcionista).
- Agregar una interfaz grafica.
- Soporte para multiples idiomas.
- Generacion de reportes.

## Autor
Desarrollado por Jeremy James Atkinson Newnham

