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
	Usuario(string usuario, string password, string nombre, string rol, bool isAdmin);
	~Usuario();

	void setUsuario(string usuario);
	string getUsuario();

	void setPassword(string password);
	string getPassword();
	
	void setNombre(string nombre);
	string getNombre();
	
	void setIsAdmin(bool isAdmin);
	bool getIsAdmin();
	
	bool crearNuevoUsuario();
	Usuario obtenerDatosUsuario();
};

