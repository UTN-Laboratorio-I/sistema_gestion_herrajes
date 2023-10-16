#pragma once
#include "Producto.h"

class ArchivoProducto
{
private:
	char _nombre[30];
public:
	ArchivoProducto(const char* nombre);

	bool grabarRegistro(Producto prod);
	bool listarRegistros();
	Producto leerRegistro(int pos);
	int contarRegistros();
	//bool modificarRegistro(int pos);
};