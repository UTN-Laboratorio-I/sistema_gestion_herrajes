#include "Venta.h"
#include "InterfazUI.h"
#include "Cliente.h"
#include "Caja.h"
#include "ResponseDto.h"

Venta::Venta() {};

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
