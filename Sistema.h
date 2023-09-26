#pragma once
#include <iostream>
#include "ErrorDto.h"
using namespace std;

class Sistema
{
protected:
	bool _encendido;
	int _pantalla;
	std::string _usuarioLogged;
	ErrorDto _error;

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

	void setError(std::string mensaje);
	std::string getError();
	bool hasError();
	void limpiarError();

#pragma endregion

#pragma region Métodos
	void administrarPrograma();
#pragma endregion

};

