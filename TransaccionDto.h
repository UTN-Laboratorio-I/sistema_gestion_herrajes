#pragma once
#include "Fecha.h"
class TransaccionDto
{
private:
	int _id;
	int _monto;
	Fecha _fecha;
	char* _usuario;
	char _tipoTransaccion;
public:
	TransaccionDto();
	TransaccionDto(int id, int monto, Fecha fecha, char* usuario, char tipoTransaccion);
	~TransaccionDto();
	int getId();
	int getMonto();
	Fecha getFecha();
	char* getUsuario();
	char getTipoTransaccion();
	void setId(int id);
	void setMonto(int monto);
	void setFecha(Fecha fecha);
	void setUsuario(char* usuario);
	void setTipoTransaccion(char tipoTransaccion);
};

