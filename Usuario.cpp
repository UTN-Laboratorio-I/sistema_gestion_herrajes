#include "Usuario.h"
#include "Archivo.h"

Usuario::Usuario()
{
	_usuario = "";
	_password = "";
	_nombre = "";
	_rol = "";
	_isAdmin = false;
}

Usuario::Usuario(string usuario, string nombre, string rol, bool isAdmin, string password="")
{
	_usuario = usuario;
	_password = password;
	_nombre = nombre;
	_rol = rol;
	_isAdmin = isAdmin;
}

Usuario::~Usuario(){}

void Usuario::setUsuario(string usuario){_usuario = usuario;}
string Usuario::getUsuario(){return _usuario;}

void Usuario::setPassword(string password){_password = password;}
string Usuario::getPassword(){return _password;}

void Usuario::setNombre(string nombre){_nombre = nombre;}
string Usuario::getNombre(){return _nombre;}

void Usuario::setRol(string rol){_rol = rol;}
string Usuario::getRol(){return _rol;}

void Usuario::setIsAdmin(bool isAdmin){_isAdmin = isAdmin;}
bool Usuario::getIsAdmin(){return _isAdmin;}

void Usuario::setDatosUsuario(string usuario, string nombre, string rol, bool isAdmin, string password = "") {
	_usuario = usuario;
	_password = password;
	_nombre = nombre;
	_rol = rol;
	_isAdmin = isAdmin;
}


bool Usuario::crearNuevoUsuario() {
	Archivo<Usuario> archivo("usuarios.dat");
	Usuario nuevoUser;
	cout << "Ingrese nuevo usuario: ";
	cin>>nuevoUser._usuario;
	cout << "Ingrese password: ";
	cin>>nuevoUser._password;
	cout << "Ingrese nombre del Usuario ";
	cin>>nuevoUser._nombre;
	cout << "Ingrese rol del Usuario ";
	cin >> nuevoUser._rol;
	cout << "Ingrese 1 si es admin, 0 si no lo es: ";
	cin>>nuevoUser._isAdmin;

	bool res = archivo.grabarRegistroArchivo(nuevoUser);

	return res;
}

Usuario Usuario::obtenerDatosUsuario() {
	Usuario user;
	return user;
}
