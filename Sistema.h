#pragma once
#include <iostream>
#include "ErrorDto.h"
#include "Usuario.h"
#include "Configuracion.h"
using namespace std;

class Sistema
{
protected:
	bool _encendido;
	int _pantalla;
	string _modulo;
	string _subModulo;
	Usuario _usuario;
	ErrorDto _error;
	Configuracion _config;
public:
#pragma region Constructor
	Sistema();
#pragma endregion

#pragma region Setters/Getters
	void setEncendido(bool set);
	bool getEncendido();

	void setUsuarioLogged(const char* usuario, const char* nombre, const char* rol, bool isAdmin);
	string getUsuarioLogged();
	string getNombreUsuarioLogged();
	string getRolUsuarioLogged();
	bool getIsAdminUsuarioLogged();

	void limpiarUsuario();

	void setIsAdmin(bool set);
	bool getIsAdmin();

	void setPantalla(int opc);
	int getPantalla();

	void setModulo(std::string modulo);
	string getModulo();

	void setSubModulo(std::string subModulo);
	string getSubModulo();
	void limpiarSubModulo();

	void setError(std::string mensaje);
	std::string getError();
	bool hasError();
	void limpiarError();

	void setMargenUtilidad(float m);
	float getMargenUtilidad();

	void setFormatoFecha(int f);
	int getFormatoFecha();

	const char* getCarpetaBackUp();
	void setCarpetaBackUp(const char* carpeta);

	/*void setFormatoMoneda(int f);
	int getFormatoMoneda();*/

#pragma endregion

#pragma region Métodos
	void administrarPrograma();

	//Administra modulo y pantalla:
	void setModuloPantalla(string modulo, int pantalla);

	void apagarOCerrarSesion();
#pragma endregion

};

