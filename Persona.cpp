#include "Persona.h"
#include "Archivo.h"

Persona::Persona()
{
	_dni = 0;
	strcpy_s(_nombre, "");
	strcpy_s(_apellido, "");
	strcpy_s(_direccion, "");
	strcpy_s(_email, "");
	_estado = true;
}


void Persona::setDni(int d){ _dni = d;}
void Persona::setNombre(const char* nombre){strcpy_s(_nombre, nombre);}
void Persona::setApellido(const char* apellido){strcpy_s(_apellido, apellido);}
void Persona::setDomicilio(const char* domicilio){strcpy_s(_direccion, domicilio);}
void Persona::setEmail(const char* email){strcpy_s(_email, email);}

void Persona::setFechaAlta()
{
	Fecha fecha;
	
	_fechaAlta = fecha.now();

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
char* Persona::getNombre(){return _nombre;}
char* Persona::getApellido(){return _apellido;}
char* Persona::getDomicilio(){return _direccion;}
char* Persona::getEmail(){return _email;}
Fecha Persona::getFechaNacimiento() { return _fechaNacimiento; }
Fecha Persona::getFechaAlta(){return _fechaAlta;}

void Persona::cargar(){
	int dni;
	char nombre[50];
	char apellido[50];
	char domicilio[50];
	char email[50];
	bool estado;

	std::cout << "Ingrese DNI: ";
	std::cin >> dni;
	std::cin.ignore();  // Limpiar el buffer del teclado

	std::cout << "Ingrese nombre: ";
	std::cin.getline(nombre, 50);

	std::cout << "Ingrese apellido: ";
	std::cin.getline(apellido, 50);

	std::cout << "Ingrese domicilio: ";
	std::cin.getline(domicilio, 50);

	std::cout << "Ingrese email: ";
	std::cin.getline(email, 50);


	setDni(dni);
	setNombre(nombre);
	setApellido(apellido);
	setDomicilio(domicilio);
	setEmail(email);
	setFechaAlta();

}

void Persona::mostrar()
{
	//cout << "ID PERSONA: " << getId() << endl;
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
	cout << endl;
}

void Persona::mostrarEncabezado()
{
	cout << left;
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
	cout << setw(10) << getDNI();
	cout << setw(10) << getNombre();
	cout << setw(10) << getApellido();
	cout << setw(10) << getEmail();
	cout << setw(10) << getDomicilio();
	cout << setw(10) << getFechaAlta().toString();
}




