#include "Transaccion.h"

Transaccion::Transaccion() {}

Transaccion::Transaccion(int id, float monto, int productoId, int clienteId, Fecha fecha, Usuario usuario, char tipo) {
		_id = id;
	_monto = monto;
	_productoId = productoId;
	_clienteId = clienteId;
	_fecha = fecha;
	_usuario = usuario;
	_tipoTransaccion = tipo;

}

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

void Transaccion::setClienteId(int clienteId) {
	_clienteId = clienteId;
}
int Transaccion::getClienteId() {
	return _clienteId;
}

void Transaccion::setFecha(Fecha fecha) {
	_fecha = fecha;
}
Fecha Transaccion::getFecha() {
	return _fecha;
}

void Transaccion::setUsuario(Usuario usuario) {
	_usuario = usuario;
}
Usuario Transaccion::getUsuario() {
	return _usuario;
}

void Transaccion::setTipo(char tipo) {
		_tipoTransaccion = tipo;

}
char Transaccion::getTipo() {
	return _tipoTransaccion;
}

Response<Transaccion> Transaccion::crearNuevaTransaccion(float monto, char tipo, const char* usuario){
	Response<Transaccion> response;

	return response;
}