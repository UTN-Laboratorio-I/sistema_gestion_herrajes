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

	//Administradores de módulo y submódulos:
	void administrarModuloABM();
	void administrarSubModuloABMCliente();
	void administrarSubModuloABMProveedor();
	void administrarSubModuloABMProducto();

	//Verificadores de estado del módulo:
	bool moduloABMActivo();
	bool subModuloABMActivo(string subModulo);
	
	//Salir de módulo y submódulos:
	void moduloABMSalir();
	void subModuloABMSalir();

	//Lógica del submódulos:
	void pantallaABMClientes();
	void pantallaABMProveedores();
	void pantallaABMProductos();

	// Administrador de ABM clientes
	void crearCliente();
	void listarClientes();

};

