#include "Proveedor.h"

void Proveedor::cargarProveedor()
{

	cargar();
	

	cout << endl;


}

void Proveedor::MostarProveedor()
{
	cout << "ID PROVEEDOR: " << getIdProveedor() << endl;
	mostrar();

}

int Proveedor::getIdProveedor(){return _idProveedor;}
void Proveedor::setId(int id){_idProveedor = id;}
