#include "Persona.h"

void Persona::setDni(int d)
{
	_dni = d;
}
void Persona::setNombre(const char* nombre)
{
	strcpy(_nombre, nombre);
}
void Persona::setApellido(const char* apellido)
{
	strcpy(_apellido, apellido);
}
void Persona::setDomicilio(const char* domicilio)
{
	strcpy(_domicilio, domicilio);
}
void Persona::seteEamil(const char* email)
{
	strcpy(_email, email);
}
void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
	int d, m, a;
	cout << "dia de nacimiento: ";
	cin >> d;
	cout << endl;
	cout << "mes de nacimiento: ";
	cin >> m;
	cout << endl;
	cout << "anio de nacimiento: ";
	cin >> a;
	cout << endl;
	fechaNacimiento.setDia(d);
	fechaNacimiento.setDia(m);
	fechaNacimiento.setDia(a);
}

void Persona::setEstado(bool estado)
{
	if (_dni!=0)
	{
		_estado = 1;
	}
	else
	{
		_estado = 0;
	}
	
}

int Persona::getDNI()
{
	return _dni;
}
char* Persona::getNombre()
{
	return _nombre;
}
char* Persona::getApellido()
{
	return _apellido;
}
char* Persona::getDomicilio()
{
	return _domicilio;
}
char* Persona::geteEamil()
{
	return _email;
}

Fecha Persona::getFechaNacimiento()
{
	return _fechaNacimiento;
}

Persona::Persona()
{
	_dni = 0;
	strcpy(_nombre, "");
	strcpy(_apellido, "");
	strcpy(_domicilio, "");
	strcpy(_email, "");
	_fechaNacimiento = Fecha(0, 0, 0);
	_estado = 0;
}

