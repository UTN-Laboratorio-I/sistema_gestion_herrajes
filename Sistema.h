#pragma once
#include <iostream>
using namespace std;
class Sistema
{
protected:
	bool _encendido;
	int _pantalla;
	std::string _usuarioLogged;

	//Handler de errores:
	struct _error {
		bool _err;
		std::string _mensajeError;
	};

public:
	Sistema() {
		_encendido = true;
		_pantalla = 0;
		_usuarioLogged = "";
	}
	void setEncendido(bool set);
	bool getEncendido();

	void setUsuarioLogged(std::string nombre);
	std::string getUsuarioLogged();

	void setPantalla(int opc);
	int getPantalla();

	void login();
	void administrarPrograma();

	void guardarProducto();
};

