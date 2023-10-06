#pragma once
#include "Producto.h"

template <class T>
class Archivo
{
public:
	Archivo() = default;
	
	bool listarRegistroArchivo(const T& objeto, const char* archivo);
	bool grabarRegistroArchivo(const T& objeto, const char* archivo);

private:

};

//Archivo::Archivo()
//{
//}
//
//Archivo::~Archivo()
//{
//}
