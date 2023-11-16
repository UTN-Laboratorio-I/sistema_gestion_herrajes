#include <iostream>
#include "Export.h"
#include "Reporte.h"



using namespace std;

Export::Export(const char* nombreArchivo){
	_nombreArchivo = nombreArchivo;
}

void Export::crearHeadersTablaExport(ofstream& archivo, const vector<string>& headers){
    for (size_t i = 0; i < headers.size(); ++i) {
        archivo << headers[i];

        if (i < headers.size() - 1) {
            archivo << ",";
        }
    }
    archivo << std::endl;
}

void Export::exportUsuarioCsv(vector<Usuario> lista, vector<string> headers ) {
   /* columnasResult.push_back({ "Id", 5 });
    columnasResult.push_back({ "Usuario", 30 });
    columnasResult.push_back({ "Nombre", 30 });
    columnasResult.push_back({ "Rol", 20 });
    columnasResult.push_back({ "Admin", 10 });*/
    std::ofstream archivo(_nombreArchivo);

    crearHeadersTablaExport(archivo, headers);


    for (Usuario& u : lista) {
        archivo << u.getId() << ",";
        archivo << u.getUsuario() << ",";
        archivo << u.getNombre() << ",";
        archivo << u.getRol() << ",";
        archivo << (u.getIsAdmin() ? "SI" : "NO") << std::endl;
    }

    archivo.close();

    system("start usuarios.csv");
}

void Export::exportProductoCsv(vector<Producto> lista, vector<string> headers) {
    std::ofstream archivo(_nombreArchivo);

    crearHeadersTablaExport(archivo, headers);

    for (Producto& prod : lista) {
        archivo << prod.getId() << ",";
		archivo << prod.getNombreProducto() << ",";
		archivo << prod.getDescripcionProducto() << ",";
		archivo << prod.getPrecioCosto() << ",";
		archivo << prod.getPrecioVenta() << ",";
		archivo << prod.getCantidad() << std::endl;
    }

    archivo.close();

    system("start productos.csv");
}

void Export::exportClienteCsv(vector<Cliente> lista, vector<string> headers) {
	std::ofstream archivo(_nombreArchivo);

	crearHeadersTablaExport(archivo, headers);

    for (Cliente& c : lista) {
		archivo << c.getId() << ",";
		archivo << c.getNombre() << ",";
		archivo << c.getApellido() << ",";
		archivo << c.getRazonSocial() << ",";
		archivo << c.getCuit() << ",";
        archivo << c.getFechaAlta().toString() << ",";
		archivo << c.getEmail() << ",";
		archivo << (c.getEstado() ?"SI":"NO") << std::endl;
	}

	archivo.close();

	system("start clientes.csv");
}

void Export::exportProveedorCsv(vector<Proveedor> lista, vector<string> headers) {
	std::ofstream archivo(_nombreArchivo);

	crearHeadersTablaExport(archivo, headers);

    for (Proveedor& p : lista) {
		archivo << p.getId() << ",";
		archivo << p.getNombre() << ",";
		archivo << p.getApellido() << ",";
		archivo << p.getRazonsocial() << ",";
		archivo << p.getCuit() << ",";
		archivo << p.getFechaAlta().toString() << ",";
		archivo << p.getEmail() << std::endl;
	}

	archivo.close();

	system("start proveedores.csv");
}

void Export::exportTransaccionCsv(vector<Transaccion> lista, vector<string> headers) {
	std::ofstream archivo(_nombreArchivo);

	crearHeadersTablaExport(archivo, headers);

    for (Transaccion& t : lista) {
		for (Detalle d : t.getDetalle()) {
		archivo << t.getId() << ",";
		archivo << t.getTipo() << ",";
		archivo << t.getFecha().toString() << ",";
		archivo << t.getId() << ",";
		archivo << t.getUsuario() << ",";
		archivo << d.getProducto().getNombreProducto() << ",";
		archivo << d.getCantidad() << ",";
		archivo << d.getSubTotal() << ",";
		archivo << t.getMonto() << endl;


		//archivo << t.getUsuarioId() << std::endl;
		}
	}

	archivo.close();

	system("start transacciones.csv");
}