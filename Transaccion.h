#pragma once
#include "Fecha.h"
#include "Usuario.h"
#include "Sistema.h"


class Transaccion
{
protected:
	int _id;
	float _monto;
	int _productoId;
	int _clienteId;
	Fecha _fecha;
	Usuario _usuario;
	char _tipoTransaccion;

public:
	Transaccion();

	void setId(int id);
	int getId();

	void setMonto(float monto);
	float getMonto();

	void setProductoId(int productoId);
	int getProductoId();

	void setClienteId(int clienteId);
	int getClienteId();

	void setFecha(Fecha fecha);
	Fecha getFecha();

	void setUsuario(Usuario usuario);
	Usuario getUsuario();

	void setTipo(char tipo);
	char getTipo();

	//Response<Transaccion> crearNuevaTransaccion(float monto, char tipo, const char* usuario);

};

