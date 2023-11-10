#pragma once
#include "Fecha.h"

class TransaccionDto
{
private:
	int _id;
	float _monto;
	Fecha _fecha;
	char _usuario[30];
	char _tipoTransaccion;
	int _cantidadTotal;
public:
	TransaccionDto();
	TransaccionDto(float monto, Fecha fecha, char tipo, int cantidad,  char* usuario);

	int getId();
	float getMonto();
	Fecha getFecha();
	char* getUsuario();
	char getTipoTransaccion();
	void setId(int id);
	void setMonto(float monto);
	void setFecha(Fecha fecha);
	void setUsuario(char* usuario);
	void setTipoTransaccion(char tipoTransaccion);
};

