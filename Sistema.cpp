#include "Sistema.h"
#include "Producto.h"
#include "Archivo.h"
#include "Archivo.cpp"


void Sistema::guardarProducto() {
	Producto producto;
	producto.setIdProducto(2);
	producto.setDescripcionProducto("Medida 3plg");
	producto.setCantidad(10);
	producto.setNombreProducto("Tornillo");
	producto.setPrecioVenta(100);
	producto.setPrecioCosto(70);
	
	Archivo<Producto> archivo;
	Producto prod;
	archivo.grabarRegistroProducto(producto, "produc.dat");
	archivo.listarRegistroProducto(prod, "produc.dat");
}

void Sistema::administrarPrograma() {

}