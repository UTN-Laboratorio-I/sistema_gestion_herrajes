#include <vector>
#include "Reporte.h"
#include "TablaDto.h"
#include "Proveedor.h"

Reporte::Reporte(){}
Reporte::Reporte(const char* nombreArchivo, string nombreModulo) {
	_nombreArchivo = nombreArchivo;
	_nombreModulo = nombreModulo;
}

char Reporte::opcionesMenuReporte() {
	char opc;
	cout << "Seleccione una opcion: " << endl;
	cout << setw(20) << "1) Aplicar filtros";
	cout << setw(20) << "0) Cerrar reporte";
	cout << setw(30) << "8) Enviar por mail";
	cout << setw(15) << "9) Imprimir";
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

void Reporte::generarReporteProveedores() {
	vector<Proveedor> listaProveedor;
	Archivo<Proveedor> archivo(_nombreArchivo);
	listaProveedor = archivo.listarRegistroArchivo();

	TablaDto<Proveedor> tabla(_nombreModulo, listaProveedor, true, true);
	tabla.generarReporteProveedores(listaProveedor);
	char opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 8:
		cout << "Enviar por mail";
		break;
	case 9:
		cout << "Imprimir";
		break;
	case 0:
		break;
	}
}

void Reporte::generarReporteProductos() {
	vector<Producto> listaProducto;
	Archivo<Producto> archivo(_nombreArchivo);
	listaProducto = archivo.listarRegistroArchivo();

	TablaDto<Producto> tabla(_nombreModulo, listaProducto, true, true);
	tabla.generarReporteProductos(listaProducto);
	char opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 8:
		cout << "Enviar por mail";
		break;
	case 9:
		cout << "Imprimir";
		break;
	case 0:
		break;
	}
}

void Reporte::generarReporteUsuarios(){
	vector<Usuario> listaUsuario;
	Archivo<Usuario> archivo(_nombreArchivo);
	listaUsuario = archivo.listarRegistroArchivo();

	TablaDto<Usuario> tabla(_nombreModulo, listaUsuario, true, true);
	tabla.generarReporteUsuarios(listaUsuario);
	char opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 8:
		cout << "Enviar por mail";
		break;
	case 9:
		cout << "Imprimir";
		break;
	case 0:
		break;
	}
}