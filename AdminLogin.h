#pragma once
#include "Sistema.h"

class AdminLogin
{
private:
	//Declaramos la variable _sistema, que es un puntero a la instancia
	Sistema* _sistema;
public:
	AdminLogin(Sistema* sistema);
	//m�todos para manejar login.
	bool verificarLogin();
	bool cerrarSesion();
};

