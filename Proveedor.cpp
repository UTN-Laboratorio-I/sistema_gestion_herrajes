#include "Proveedor.h"

void Proveedor::cargarProveedor()
{
	int idProveedor;

	cargar();
	cout << "INGRESE ID PROVEEDOR: ";
	cin >> idProveedor;
	cout << endl;

	setIdProveedor(idProveedor);
}

void Proveedor::MostarProveedor()
{
	mostrar();
	cout << "ID CLIENTE: " << getIdProveedor() << endl;
}

int Proveedor::getIdProveedor(){return _idProveedor;}
void Proveedor::setIdProveedor(int id){_idProveedor = id;}
