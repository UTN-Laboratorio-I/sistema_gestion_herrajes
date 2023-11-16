#pragma once
#include "Detalle.h"

class DetalleDto
{
private:
	int _id;
	int _idTransaccion;
	int _idProducto;
	float _precioUnitario;
	int _cantidad;
public:
	DetalleDto();
	DetalleDto(Detalle detalle, int idTransaccion);

	int getId();
	void setId(int id);
	int getIdTransaccion();
	int getIdProducto();
	float getPrecioUnitario();
	int getCantidad();
	void setIdTransaccion(int idTransaccion);
	void setIdProducto(int idProducto);
	void setPrecioUnitario(float precioUnitario);
	void setCantidad(int cantidad);
};

