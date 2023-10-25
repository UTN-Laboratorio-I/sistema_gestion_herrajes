#pragma once
#include <iostream>
#include "Sistema.h"

class AdminCliente
{
private:
	Sistema* _sistema;
	string _nombreModulo;
	const char* _nombreArchivo;
public:
	AdminCliente(Sistema* sistema);
	~AdminCliente();

	bool moduloClienteActivo();
	void moduloClienteSalir();

	void administrarModuloCliente();

	void listarClientes();
	void creacionNuevoCliente();
	void modificarcliente();
	void eliminarCliente();
};

