#include "TransaccionDto.h"
#include "Venta.h"


//Constructor vacío
TransaccionDto::TransaccionDto(){}

TransaccionDto::TransaccionDto(float monto, Fecha fecha, char tipo,int cantidad,  char* usuario) {
	_id = 0;
	_monto =monto;
	_fecha = fecha;
	_tipoTransaccion = tipo;
	_cantidadTotal =cantidad;
	setUsuario(usuario);
}

int TransaccionDto::getId() {
	return _id;
}

float TransaccionDto::getMonto() {
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

void TransaccionDto::setMonto(float monto) {
	_monto = monto;
}

void TransaccionDto::setFecha(Fecha fecha) {
	_fecha = fecha;
}

void TransaccionDto::setUsuario(char* usuario) {
	std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
}

void TransaccionDto::setTipoTransaccion(char tipoTransaccion) {
	_tipoTransaccion = tipoTransaccion;
}