#pragma once
#include <iostream>
#include "ErrorDto.h"
#include "Usuario.h"
using namespace std;

class Sistema
{
protected:
	bool _encendido;
	int _pantalla;
	string _modulo;
	std::string _usuarioLogged;
	Usuario _usuario;
	bool _isAdmin;
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

	void setIsAdmin(bool set);
	bool getIsAdmin();

	void setPantalla(int opc);
	int getPantalla();

	void setModulo(std::string modulo);
	string getModulo();

	void setError(std::string mensaje);
	std::string getError();
	bool hasError();
	void limpiarError();

#pragma endregion

#pragma region Métodos
	void administrarPrograma();

	//Administra modulo y pantalla:
	void setModuloPantalla(string modulo, int pantalla);

	void apagarOCerrarSesion();
#pragma endregion

};

