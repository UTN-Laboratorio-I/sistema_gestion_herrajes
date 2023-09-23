#include <iostream>

#include "Archivo.h"

Archivo::Archivo() {

}

bool Archivo::grabarRegistroProducto(Producto prod) {

	FILE *p;
	p = fopen("producto.dat", "ab");

	if (p == NULL) {
		return false;
	}

	bool escribio = fwrite(&prod, sizeof(prod), 1, p);

	return escribio;

}

bool Archivo::listarRegistroProducto(Producto prod) {

	FILE* p;
	p = fopen("producto.dat", "rb");

	if (p == NULL) {
		return false;
	}

	bool pudoLeer = fread(&prod, sizeof(prod), 1, p);

	return pudoLeer;
}