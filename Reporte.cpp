#include <vector>
#include "Reporte.h"
#include "TablaDto.h"
#include "Proveedor.h"
#include "Export.h"

Reporte::Reporte(){}
Reporte::Reporte(const char* nombreArchivo, string nombreModulo) {
	_nombreArchivo = nombreArchivo;
	_nombreModulo = nombreModulo;
}

int Reporte::opcionesMenuReporte() {
	int opc;
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
	Export exportArchivo("clientes.csv");
	vector<Cliente> listaCliente;
	Archivo<Cliente> archivo(_nombreArchivo);
	listaCliente = archivo.listarRegistroArchivo();
	TablaDto<Cliente> tabla(_nombreModulo, listaCliente, true, true);
	vector<string> headersTabla = tabla.generarReporteClientes(listaCliente);

	int opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 9:
		exportArchivo.exportClienteCsv(listaCliente, headersTabla);
		break;
	case 0:
		break;
	}
}

void Reporte::generarReporteProveedores() {
	Export exportArchivo("proveedores.csv");
	vector<Proveedor> listaProveedor;
	Archivo<Proveedor> archivo(_nombreArchivo);
	listaProveedor = archivo.listarRegistroArchivo();

	TablaDto<Proveedor> tabla(_nombreModulo, listaProveedor, true, true);
	vector<string> headersTabla = tabla.generarReporteProveedores(listaProveedor);
	int opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 8:
		cout << "Enviar por mail";
		break;
	case 9:
		exportArchivo.exportProveedorCsv(listaProveedor, headersTabla);
		break;
	case 0:
		break;
	}
}

void Reporte::generarReporteProductos() {
	Export exportProductos("productos.csv");
	vector<Producto> listaProducto;
	Archivo<Producto> archivo(_nombreArchivo);
	listaProducto = archivo.listarRegistroArchivo();

	TablaDto<Producto> tabla(_nombreModulo, listaProducto, true, true);
	vector<string> headersTabla = tabla.generarReporteProductos(listaProducto);
	char opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 8:
		cout << "Enviar por mail";
		break;
	case 9:
		exportProductos.exportProductoCsv(listaProducto, headersTabla);
		break;
	case 0:
		break;
	}
}

void Reporte::generarReporteUsuarios(){
	vector<Usuario> listaUsuario;
	Archivo<Usuario> archivo(_nombreArchivo);
	listaUsuario = archivo.listarRegistroArchivo();
	const char* nombreArchivo = "usuarios.csv";
	Export exportArchivo(nombreArchivo);

	TablaDto<Usuario> tabla(_nombreModulo, listaUsuario, true, true);
	vector<string> headers = tabla.generarReporteUsuarios(listaUsuario);
	int opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 8:
		cout << "Enviar por mail";
		break;
	case 9:
		exportArchivo.exportUsuarioCsv(listaUsuario, headers);
		break;
	case 0:
		break;
	}
}

void Reporte::generarReporteTransacciones() {
	Export exportArchivo("transacciones.csv");
	Archivo<TransaccionDto> archivoTransaccion("transacciones.dat");
	Archivo<DetalleDto> archivoDetalle("detalles.dat");
	Archivo<Producto> archivoProducto("productos.dat");
	vector<TransaccionDto> listaTransaccionDto = archivoTransaccion.listarRegistroArchivo();
	vector<DetalleDto> listaDetalleDto = archivoDetalle.listarRegistroArchivo();

	vector<Transaccion> listaTransaccion;

	for (TransaccionDto tran : listaTransaccionDto) {
		Transaccion transaccion;
		Detalle detalle;
		transaccion.setId(tran.getId());
		transaccion.setMonto(tran.getMonto());
		transaccion.setFecha(tran.getFecha());
		transaccion.setUsuario(tran.getUsuario());
		transaccion.setTipo(tran.getTipoTransaccion());
		transaccion.setCantidad(tran.getCantidadTotal());

		int idTransaccion = tran.getId();
		for (DetalleDto det : listaDetalleDto) {
			if (det.getIdTransaccion() == idTransaccion) {
				Response<Producto> res = archivoProducto.buscarUnRegistro(det.getIdProducto());
				detalle.setCantidad(det.getCantidad());
				detalle.setProducto(res.getData());
				transaccion.setDetalle(detalle);
			}
		}
		listaTransaccion.push_back(transaccion);
	}

	TablaDto<Transaccion> tabla(_nombreModulo, listaTransaccion, true);
	vector<string> headersTabla = tabla.generarReporteTransacciones(listaTransaccion);

	int opc = opcionesMenuReporte();

	switch (opc) {
	case 1:
		cout << "Aplicar filtro";
		break;
	case 8:
		cout << "Enviar por mail";
		break;
	case 9:
		exportArchivo.exportTransaccionCsv(listaTransaccion, headersTabla);
		break;
	case 0:
		break;
	}

}