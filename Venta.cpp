#include "Venta.h"
#include "InterfazUI.h"
#include "Cliente.h"
#include "Caja.h"
#include "ResponseDto.h"

Venta::Venta() {
	_clienteId = 0;
	_tipo = 'v';
};

void Venta::setId(int id) {
	_id = id;
}
int Venta::getId() {
	return _id;
}
void Venta::setClienteId(int clienteId) {
	_clienteId = clienteId;
}
int Venta::getClienteId() {
	return _clienteId;
}

void Venta::setTipoTransaccion(char tipoTransaccion) { _tipoTransaccion = tipoTransaccion; }
char Venta::getTipoTransaccion() { return _tipoTransaccion; }

Response<Venta> Venta::crearNuevaVenta() {
	Response<Venta> response;

	

	return response;
}