#pragma once
#include <iostream>
#include "Fecha.h"
#include <cstdio>
using namespace std;

class Persona
{

public:

	void setDni(int d);
	void setNombre(const char* nombre);
	void setApellido(const char* apellido);
	void setDomicilio(const char* domicilio);
	void seteEamil(const char* email);
	void setFechaNacimiento(Fecha fechaNacimiento);
	void setEstado(bool estado);

	int getDNI();
	char* getNombre();
	char* getApellido();
	char* getDomicilio();
	char* geteEamil();
	Fecha getFechaNacimiento();

	Persona();

protected:
	int _dni;
	char _nombre[40], _apellido[40];
	char _direccion[100], _email[50];
	Fecha _fechaNacimiento;
	bool _estado;


};

