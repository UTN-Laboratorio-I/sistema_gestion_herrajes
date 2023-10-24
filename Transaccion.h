#pragma once
#include "Fecha.h"
#include "Usuario.h"
#include "Sistema.h"
#include "Detalle.h"


class Transaccion
{
protected:
	int _id;
	float _monto;
	Fecha _fecha;
	char _usuario[30];
	char _tipoTransaccion;
	int _cantidad; //Cantidad total de productos
	vector<Detalle> _detalle;

public:
	Transaccion();
	Transaccion(float monto,
		const char* usuario,
		char tipo,
		int cantidad
	);

	void setId(int id);
	int getId();

	void setMonto(float monto);
	float getMonto();

	void setProductoId(int productoId);
	int getProductoId();

	void setFecha(Fecha fecha);
	Fecha getFecha();

	void setUsuario(char* usuario);
	const char* getUsuario();

	void setTipo(char tipo);
	char getTipo();

	vector<Detalle> getDetalle();

	Response<Transaccion> crearNuevaTransaccion(
		float monto, 
		const char* usuario, 
		char tipo, 
		int productoId, 
		int cantidad
	);
};

