#include <vector>
#include "Reporte.h"
#include "TablaDto.h"

Reporte::Reporte(){}
Reporte::Reporte(const char* nombreArchivo, string nombreModulo) {
	_nombreArchivo = nombreArchivo;
	_nombreModulo = nombreModulo;
}

void Reporte::generarReporteClientes() {
	vector<Cliente> listaCliente;
	Archivo<Cliente> archivo(_nombreArchivo);
	listaCliente = archivo.listarRegistroArchivo();
	
	TablaDto<Cliente> tabla(_nombreModulo, listaCliente);
	tabla.generarReporteClientes(listaCliente);
}