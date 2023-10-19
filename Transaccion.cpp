#include "Transaccion.h"
#include "Caja.h"

Transaccion::Transaccion() {};

void Transaccion::setId(int id) {
	_id = id;
}
int Transaccion::getId() {
	return _id;
}

void Transaccion::setMonto(float monto) {
	_monto = monto;
}
float Transaccion::getMonto() {
	return _monto;
}

void Transaccion::setProductoId(int productoId) {
	_productoId = productoId;
}
int Transaccion::getProductoId() {
	return _productoId;
}

void Transaccion::setFecha(Fecha fecha) {
	_fecha = fecha;
}
Fecha Transaccion::getFecha() {
	return _fecha;
}

void Transaccion::setUsuario(char* usuario) {
	std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
}
const char* Transaccion::getUsuario() {
	return _usuario;
}

void Transaccion::setTipo(char tipo) {
		_tipoTransaccion = tipo;

}
char Transaccion::getTipo() {
	return _tipoTransaccion;
}

Response<Transaccion> Transaccion::crearNuevaTransaccion(float monto, char tipo, const char* usuario, char tipoTransaccion){
	Response<Transaccion> response;
	Fecha fecha;
	_monto = monto;
	_tipoTransaccion = tipoTransaccion;
	std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
	_fecha = fecha.now();

	return response;
}