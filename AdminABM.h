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
	AdminABM(Sistema* sistema);

	//Getters/Setters:
	string getNombreModulo();

	bool moduloABMActivo();
	bool subModuloABMActivo(string subModulo);
	
	void moduloABMSalir();
	void subModuloABMSalir();

	void administrarModuloABM();
	void administrarSubModuloABMCliente();
	void administrarSubModuloABMProveedor();
	void administrarSubModuloABMProducto();

	void pantallaABMClientes();
	void pantallaABMProveedores();
	void pantallaABMProductos();

};

