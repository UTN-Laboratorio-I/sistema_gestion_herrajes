#include "Compra.h"
#include "Archivo.h"

//SETTERS---------

void Compra::setId(int id) { _id = id; }
void Compra::setIdCompra(int idCompra) { _idCompra = idCompra; }

//GETTERS---------

int Compra::getId() { return _id; }
int Compra::getIdCompra() { return _idCompra; }

//METODOS---------

bool Compra::registrarNuevaCompra()
{
	Archivo <Compra> Archivo("Compras.dat");
	Response <Proveedor> nuevaCompra;
	Compra compra;


	Archivo.grabarRegistroArchivo(compra);

	return true;
}

