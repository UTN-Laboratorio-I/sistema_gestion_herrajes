#pragma once
class DetalleDto
{
private:
	int _idTransaccion;
	int _idProducto;
	float _precioUnitario;
	int _cantidad;
public:
	DetalleDto();
	DetalleDto(int idTransaccion, int idProducto, float precioUnitario, int cantidad);
	~DetalleDto();
	int getIdTransaccion();
	int getIdProducto();
	float getPrecioUnitario();
	int getCantidad();
	void setIdTransaccion(int idTransaccion);
	void setIdProducto(int idProducto);
	void setPrecioUnitario(float precioUnitario);
	void setCantidad(int cantidad);
};

