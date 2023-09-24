#include <iostream>

#include "Archivo.h"

Archivo::Archivo(std::string nombre){
	strcrp()
}

bool Archivo::grabarRegistroProducto(nombre) {

	FILE *p;
	p = fopen(nombre, "ab");

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