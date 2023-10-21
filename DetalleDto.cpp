#include "DetalleDto.h"

DetalleDto::DetalleDto()
{
}

DetalleDto::DetalleDto(int idTransaccion, int idProducto, float precioUnitario, int cantidad)
{
	_idTransaccion = idTransaccion;
	_idProducto = idProducto;
	_precioUnitario = precioUnitario;
	_cantidad = cantidad;
}

DetalleDto::~DetalleDto()
{
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

