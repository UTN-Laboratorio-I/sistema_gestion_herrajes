#include "ArchivoProducto.h"
#include <cstring>
#include <stdlib.h>
#pragma warning(disable: 4996)


ArchivoProducto::ArchivoProducto(const char* nombre)
{
	strcpy(_nombre, nombre);
}



bool ArchivoProducto::grabarRegistro(Producto prod)
{
	FILE* p = fopen(_nombre, "ab");

	if (p == NULL)
	{
		return false;
	}

	bool pudoEscribir = fwrite(&prod, sizeof(Producto), 1, p);

	fclose(p);

	return pudoEscribir;
}



bool ArchivoProducto::listarRegistros()
{
	Producto reg;

	FILE* p = fopen(_nombre, "rb");

	if (p == NULL)
	{
		return false;
	}

	while (fread(&reg, sizeof(Producto), 1, p) == 1)
	{
		reg.mostrarProductos();
	}

	fclose(p);

	return true;
}

Producto ArchivoProducto::leerRegistro(int pos)
{
	FILE* p = fopen(_nombre, "rb");

	Producto reg;

	if (p == NULL)
	{
		return reg;
	}


	fseek(p, sizeof(Producto)* pos, 0);
	fread(&reg, sizeof(Producto), 1, p);
	reg.mostrarProductos();

	fclose(p);

	return reg;
}


int ArchivoProducto::contarRegistros()
{
	FILE* p = fopen(_nombre, "rb");

	fseek(p, 0, 2);
	int tamanio = ftell(p);
	
	fclose(p);

	return tamanio / sizeof(Producto);
}

//bool ArchivoProducto::modificarRegistro(int pos)
//{
//
//}