#include "TransaccionDto.h"

TransaccionDto::TransaccionDto() {};

//Constructor vacío
TransaccionDto::TransaccionDto(int id, int monto, Fecha fecha, char* usuario, char tipoTransaccion) {
	_id = id;
	_monto = monto;
	_fecha = fecha;
	_usuario = usuario;
	_tipoTransaccion = tipoTransaccion;
}

TransaccionDto::~TransaccionDto() {};

int TransaccionDto::getId() {
	return _id;
}

int TransaccionDto::getMonto() {
	return _monto;
}

Fecha TransaccionDto::getFecha() {
		return _fecha;
}

char* TransaccionDto::getUsuario() {
	return _usuario;
}

char TransaccionDto::getTipoTransaccion() {
	return _tipoTransaccion;
}

void TransaccionDto::setId(int id) {
	_id = id;

}

void TransaccionDto::setMonto(int monto) {
	_monto = monto;
}

void TransaccionDto::setFecha(Fecha fecha) {
	_fecha = fecha;
}

void TransaccionDto::setUsuario(char* usuario) {
	_usuario = usuario;
}

void TransaccionDto::setTipoTransaccion(char tipoTransaccion) {
	_tipoTransaccion = tipoTransaccion;
}