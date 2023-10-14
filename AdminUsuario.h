#pragma once
#include <iostream>
#include "Sistema.h"
class AdminUsuario
{
private:
	Sistema* _sistema;
	string _nombreModulo;
public:
	AdminUsuario(Sistema* sistema);
	~AdminUsuario();

	bool moduloUsuarioActivo();
	void moduloUsuarioSalir();

	void administrarModuloUsuario();

	bool crearNuevoUsuario();
	bool modificarUsuario();
	bool eliminarUsuario();

};

