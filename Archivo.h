#pragma once

#include "Producto.h"

class Archivo
{
public:
	Archivo();
	
	bool listarRegistroProducto(Producto prod);
	bool grabarRegistroProducto(Producto prod);

private:

};

Archivo::Archivo()
{
}

Archivo::~Archivo()
{
}