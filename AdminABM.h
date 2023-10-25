#pragma once
#include "Sistema.h"
class AdminABM
{
private:
	string _nombreModulo;
	Sistema* _sistema;
	string _nombreSubModuloCliente;
	string _nombreSubModuloProveedor;
	string _nombreSubModuloProducto;

public:
	//Constructor:
	AdminABM(Sistema* sistema);

	//Getters/Setters:
	string getNombreModulo();

	//Administradores de m�dulo y subm�dulos:
	void administrarModuloABM();
	void administrarSubModuloABMCliente();
	void administrarSubModuloABMProveedor();
	void administrarSubModuloABMProducto();

	//Verificadores de estado del m�dulo:
	bool moduloABMActivo();
	bool subModuloABMActivo(string subModulo);
	
	//Salir de m�dulo y subm�dulos:
	void moduloABMSalir();
	void subModuloABMSalir();

	//L�gica del subm�dulos:
	void pantallaABMClientes();
	void pantallaABMProveedores();
	void pantallaABMProductos();

	// Administrador de ABM clientes
	void crearCliente();
	void listarClientes();

};

