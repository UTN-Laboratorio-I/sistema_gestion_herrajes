#include <vector>
#include "Reporte.h"
#include "TablaDto.h"

Reporte::Reporte(){}
Reporte::Reporte(const char* nombreArchivo, string nombreModulo) {
	_nombreArchivo = nombreArchivo;
	_nombreModulo = nombreModulo;
}

char Reporte::opcionesMenuReporte() {
	char opc;
	cout << "Seleccione una opcion: " << endl;
	cout << setw(20) << "1) Aplicar filtros";
	cout << setw(20) << "9) Imprimir";
	cout << setw(20) << "0) Cerrar reporte";
	cout << endl;
	cin >> opc;
	return opc;
}

void Reporte::generarReporteClientes() {
	vector<Cliente> listaCliente;
	Archivo<Cliente> archivo(_nombreArchivo);
	listaCliente = archivo.listarRegistroArchivo();
	
	TablaDto<Cliente> tabla(_nombreModulo, listaCliente, true, true);
	tabla.generarReporteClientes(listaCliente);
	char opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 2:
	cout << "Imprimir";
		break;
	case 0:
		break;
	}
}