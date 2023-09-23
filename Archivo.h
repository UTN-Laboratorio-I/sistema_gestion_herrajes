#pragma once
#include "Producto.h"

template <class T>
class Archivo
{
public:
	Archivo() = default;
	
	bool listarRegistroProducto(const T& objeto, const char* archivo);
	bool grabarRegistroProducto(const T& objeto, const char* archivo);

private:

};

//Archivo::Archivo()
//{
//}
//
//Archivo::~Archivo()
//{
//}