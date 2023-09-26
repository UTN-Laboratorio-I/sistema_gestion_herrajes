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
#pragma region Constructor
	Sistema();
#pragma endregion

#pragma region Setters/Getters
	void setEncendido(bool set);
	bool getEncendido();

	void setUsuarioLogged(std::string nombre);
	std::string getUsuarioLogged();

	void setPantalla(int opc);
	int getPantalla();
#pragma endregion

#pragma region Métodos
	void administrarPrograma();
#pragma endregion

};

