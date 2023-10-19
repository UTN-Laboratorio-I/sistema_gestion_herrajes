#include "Compra.h"
#include "Archivo.h"

Compra::Compra(){
}

void Compra::setId(int id) { _id = id; }
void Compra::setIdCompra(int idCompra) { _idCompra = idCompra; }

int Compra::getId() { return _id; }
int Compra::getIdCompra() { return _idCompra; }


bool Compra::crearNuevaCompra()
{
	Archivo <Compra> Archivo("Compras.dat");
	Compra compra;
	Response <Proveedor> nuevaCompra;


	Archivo.grabarRegistroArchivo(compra);

	return true;
}

