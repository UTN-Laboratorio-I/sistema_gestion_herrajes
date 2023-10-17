#include "Persona.h"

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


void Persona::setDni(int d){ _dni = d;}
void Persona::setId(int id){ _idPersona = id; }
void Persona::setNombre(const char* nombre){strcpy_s(_nombre, nombre);}
void Persona::setApellido(const char* apellido){strcpy_s(_apellido, apellido);}
void Persona::setDomicilio(const char* domicilio){strcpy_s(_direccion, domicilio);}
void Persona::setEmail(const char* email){strcpy_s(_email, email);}

void Persona::setFechaAlta()
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
	_fechaAlta.setDia(d);
	_fechaAlta.setMes(m);
	_fechaAlta.setAnio(a);

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
	if (_dni != 0) {_estado = 1;}
	else{_estado = 0;}
}

int Persona::getDNI(){return _dni;}
int Persona::getId(){return _idPersona;}
char* Persona::getNombre(){return _nombre;}
char* Persona::getApellido(){return _apellido;}
char* Persona::getDomicilio(){return _direccion;}
char* Persona::getEmail(){return _email;}
Fecha Persona::getFechaNacimiento() { return _fechaNacimiento; }
Fecha Persona::getFechaAlta(){return _fechaAlta;}

void Persona::cargar()
{
	int dni, idPersona;
	char nombre[40], apellido[40], direccion[100], email[50];
	Fecha fechaAlta;
	
	cout << "INGRESE ID: ";
	cin >> idPersona;
	cout << endl;
	cout << "DNI: ";
	cin >> dni;
	cout << endl;
	cout << "NOMBRE: ";
	cin >> nombre;
	cout << endl;
	cout << "APELLIDO: ";
	cin >> apellido;
	cout << endl;
	cout << "EMAIL: ";
	cin >> email;
	cout << endl;
	cout << "DOMICILIO: ";
	cin >> direccion;
	cout << endl;
	setFechaAlta();
	cout << endl;

	setId(idPersona);
	setDni(dni);
	setNombre(nombre);
	setApellido(apellido);
	setEmail(email);
	setDomicilio(direccion);
}

void Persona::mostrar()
{
	cout << "INGRESE ID: " << getId() << endl;
	cout << "DNI: " << getDNI() << endl;
	cout << "NOMBRE: " << getNombre() << endl;
	cout << "APELLIDO: " << getApellido() << endl;
	cout << "EMAIL: " << getEmail() << endl;
	cout << "DOMICILIO: " << getDomicilio() << endl;
	cout << "FECHA DE ALTA: " << getFechaAlta().toString() << endl;

	/*int i;
	mostrarEncabezado();
	for (int i = 0; i < 1; i++) {
		mostrarContenido();
	}*/
}

void Persona::mostrarEncabezado()
{
	cout << left;
	cout << setw(10) << "ID";
	cout << setw(15) << "DNI";
	cout << setw(20) << "NOMBRES";
	cout << setw(20) << "APELLIDOS";
	cout << setw(20) << "EMAIL";
	cout << setw(20) << "DOMICILIO";
	cout << setw(15) << "FECHA DE ALTA" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
}

void Persona::mostrarContenido()
{
	cout << left;
	cout << setw(10) << getId();
	cout << setw(10) << getDNI();
	cout << setw(10) << getNombre();
	cout << setw(10) << getApellido();
	cout << setw(10) << getEmail();
	cout << setw(10) << getDomicilio();
	cout << setw(10) << getFechaAlta().toString();
}




