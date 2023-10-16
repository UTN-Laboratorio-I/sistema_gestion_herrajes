#include "Persona.h"

void Persona::setDni(int d)
{
	_dni = d;
}
void Persona::setId(int id)
{
	_idPersona = id;
}
void Persona::setNombre(const char* nombre)
{
	strcpy_s(_nombre, nombre);
}
void Persona::setApellido(const char* apellido)
{
	strcpy_s(_apellido, apellido);
}
void Persona::setDomicilio(const char* domicilio)
{
	strcpy_s(_direccion, domicilio);
}
void Persona::seteEamil(const char* email)
{
	strcpy_s(_email, email);
}
void Persona::setFechaAlta(Fecha fechaAlta)
{
	int d, m, a;
	cout << "dia de alta: ";
	cin >> d;
	cout << endl;
	cout << "mes de alta: ";
	cin >> m;
	cout << endl;
	cout << "anio de alta: ";
	cin >> a;
	cout << endl;
	fechaAlta.setDia(d);
	fechaAlta.setDia(m);
	fechaAlta.setDia(a);

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
	if (_dni != 0)
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
int Persona::getId()
{
	return _idPersona;
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
	return _direccion;
}
char* Persona::geteEamil()
{
	return _email;
}

Fecha Persona::getFechaNacimiento()
{
	return _fechaNacimiento;
}

Fecha Persona::getFechaAlta()
{
	return _fechaAlta;
}

Persona::Persona()
{
	_dni = 0;
	strcpy_s(_nombre, "");
	strcpy_s(_apellido, "");
	strcpy_s(_direccion, "");
	strcpy_s(_email, "");
	_fechaNacimiento = Fecha(0, 0, 0);
	_estado = 0;
}

