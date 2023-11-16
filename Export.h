#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Usuario.h"
#include "Producto.h"
#include "Usuario.h"
#include "Proveedor.h"
#include "Transaccion.h"
#include "Cliente.h"
#pragma once
class Export
{
private:
	 const char* _nombreArchivo;

public:
	Export(const char* nombreArchivo);

	void crearHeadersTablaExport(ofstream& archivo, const vector<string>& headers);

	void exportUsuarioCsv(vector<Usuario> lista, vector<string> headers);
	void exportProductoCsv(vector<Producto> lista, vector<string> headers);
	void exportClienteCsv(vector<Cliente> lista, vector<string> headers);
	void exportProveedorCsv(vector<Proveedor> lista, vector<string> headers);
	void exportTransaccionCsv(vector<Transaccion> lista, vector<string> headers);
};

