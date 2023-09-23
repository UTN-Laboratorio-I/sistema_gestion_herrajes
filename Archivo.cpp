#include <iostream>
#pragma warning (disable : 4996)
#include "Archivo.h"

template <class T>
bool Archivo<T>::grabarRegistroProducto(const T& objeto, const char* archivo) {

	FILE *p;
	p = fopen(archivo, "ab");

	if (p == NULL) {
		return false;
	}

	bool escribio = fwrite(&objeto, sizeof(objeto), 1, p);

	return escribio;

}

template <class T>
bool Archivo<T>::listarRegistroProducto(const T& objeto, const char* archivo) {

	FILE* p;
	p = fopen(archivo, "rb");

	if (p == NULL) {
		return false;
	}
	T reg;

	bool pudoLeer = fread(&reg, sizeof(objeto), 1, p);
	
	return pudoLeer;
}