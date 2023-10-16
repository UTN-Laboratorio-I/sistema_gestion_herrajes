#pragma once
#include "Sistema.h"

class AdminLogin
{
private:
	//Declaramos la variable _sistema, que es un puntero a la instancia
	Sistema* _sistema;
	char _usuario[20];
	char _password[20];
public:
	AdminLogin(Sistema* sistema);

	//métodos para manejar login.
	bool verificarLogin();
	void cerrarSesion();

	//función utilizada para buscar usuarios en archivo, y validar password.
	Usuario buscarUsuario();
	bool validar(Usuario user);
private:
	bool login();

};

