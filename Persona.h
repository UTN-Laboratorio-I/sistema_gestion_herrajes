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
	void setNombre(const char* nombre);
	void setApellido(const char* apellido);
	void setDomicilio(string domicilio);
	void setEmail(string email);
	void setFechaAlta();
	void setFechaNacimiento(Fecha fechaNacimiento);
	void setEstado(bool estado);

	int getDNI();
	char* getNombre();
	char* getApellido();
	char* getDomicilio();
	char* getEmail();
	Fecha getFechaAlta();
	bool getEstado();

	void cargar();
	void mostrar();

	void mostrarEncabezado();
	void mostrarContenido();

protected:
	int _dni;
	char _nombre[40], _apellido[40];
	char _direccion[100], _email[50];
	Fecha _fechaAlta;
	bool _estado;
};