#include <iostream>
#include <functional>
#pragma once
using namespace std;

class Usuario
{
private:
	string _usuario;
	string _password;
	string _nombre;
	string _rol;
	bool _isAdmin;
public:
	Usuario();
	Usuario(string usuario, string nombre, string rol, bool isAdmin, string password);
	~Usuario();

	void setUsuario(string usuario);
	string getUsuario();

	void setPassword(string password);
	string getPassword();
	
	void setNombre(string nombre);
	string getNombre();
	
	void setIsAdmin(bool isAdmin);
	bool getIsAdmin();

	void setRol(string rol);
	string getRol();

	void setDatosUsuario(string usuario, string nombre, string rol, bool isAdmin, string password);
	Usuario getDatosUsuario();

	bool crearNuevoUsuario();
	Usuario obtenerDatosUsuario();
};

