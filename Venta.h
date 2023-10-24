#pragma once
#include "Transaccion.h"
class Venta :
	public Transaccion
{
private:
	int _id;
	int _clienteId;
	char _tipo;
	Producto _producto;

public:
	Venta();

	void setId(int id);
	int getId();
	void setClienteId(int clienteId);
	int getClienteId();
	void setTipoTransaccion(char tipoTransaccion);
	char getTipoTransaccion();

	void setProducto(Producto producto);
	Producto getProducto();

	void agregarADetalleVenta(Producto producto, int cantidad);

	void agregarProducto(Producto producto);
	
	Response<Venta> crearNuevaVenta(Sistema* sistema);//Le paso el parametro sistema para poder utilizar la UI (Sobre todo el limpiarConsola y headerDinamico)
};

