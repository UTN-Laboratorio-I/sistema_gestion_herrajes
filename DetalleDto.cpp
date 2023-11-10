#include "DetalleDto.h"
#include "Detalle.h"
#include "Producto.h"

DetalleDto::DetalleDto() {

}

DetalleDto::DetalleDto(Detalle detalle, int idTransaccion)
{
	Producto producto = detalle.getProducto();

	_id = 0;
	_idTransaccion = idTransaccion;
	_idProducto = producto.getId();
	_precioUnitario = producto.getPrecioCosto();
	_cantidad = detalle.getCantidad();
}

int DetalleDto::getId()
{
	return _id;
}

void DetalleDto::setId(int id)
{
	_id = id;
}

int DetalleDto::getIdTransaccion()
{
	return _idTransaccion;
}

int DetalleDto::getIdProducto()
{
	return _idProducto;
}

float DetalleDto::getPrecioUnitario()
{
	return _precioUnitario;
}

int DetalleDto::getCantidad()
{
	return _cantidad;
}

void DetalleDto::setIdTransaccion(int idTransaccion)
{
	_idTransaccion = idTransaccion;
}

void DetalleDto::setIdProducto(int idProducto)
{
	_idProducto = idProducto;
}

void DetalleDto::setPrecioUnitario(float precioUnitario)
{
	_precioUnitario = precioUnitario;
}

void DetalleDto::setCantidad(int cantidad)
{
	_cantidad = cantidad;
}

