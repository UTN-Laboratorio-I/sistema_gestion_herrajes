#pragma once
#include <iostream>
#include "Sistema.h"
class AdminUsuario
{
private:
	Sistema* _sistema;
	string _nombreModulo;
	const char* _nombreArchivo;
public:
	AdminUsuario(Sistema* sistema);
	~AdminUsuario();

	bool moduloUsuarioActivo();
	void moduloUsuarioSalir();

	void administrarModuloUsuario();

	void listarUsuarios();
	void creacionNuevoUsuario();
	void modificarUsuario();
	void eliminarUsuario();

};

