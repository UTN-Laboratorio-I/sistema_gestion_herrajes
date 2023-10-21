#pragma once
#include <iostream>
#include "Fecha.h"
#include <cstdio>
#include <iomanip>
using namespace std;

class Persona
{

public:

	Persona();

	void setDni(int d);
	void setId(int id);
	void setNombre(const char* nombre);
	void setApellido(const char* apellido);
	void setDomicilio(const char* domicilio);
	void setEmail(const char* email);
	void setFechaAlta();
	void setFechaNacimiento(Fecha fechaNacimiento);
	void setEstado(bool estado);

	int getDNI();
	int getId();
	char* getNombre();
	char* getApellido();
	char* getDomicilio();
	char* getEmail();
	Fecha getFechaNacimiento();
	Fecha getFechaAlta();

	void cargar();
	void mostrar();

	void mostrarEncabezado();
	void mostrarContenido();

protected:
	int _dni, _id;
	char _nombre[40], _apellido[40];
	char _direccion[100], _email[50];
	Fecha _fechaNacimiento, _fechaAlta;
	bool _estado;
};