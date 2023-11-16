#include "Transaccion.h"
#include "Caja.h"

Transaccion::Transaccion() {};

Transaccion::Transaccion(bool reporte) {
	if (reporte) {
		_id = 0;
		_monto = 0;
		_fecha = Fecha();
		_tipoTransaccion = ' ';
		_cantidadProductos = 0;
	}
}
Transaccion::Transaccion(
	float monto,
	const char* usuario,
	char tipo,
	int cantidad
) {
	Fecha fecha;
	_monto = monto;
	_tipoTransaccion = tipo;
	std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
	_fecha = fecha.now();
	_cantidadProductos = cantidad;
};


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

void Transaccion::setFecha(Fecha fecha) {
	_fecha = fecha;
}
Fecha Transaccion::getFecha() {
	return _fecha;
}

void Transaccion::setUsuario(const char* usuario) {
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

vector<Detalle> Transaccion::getDetalle() {
	return _detalle;
}

void Transaccion::setDetalle(Detalle detalle) {
	_detalle.push_back(detalle);
}

void Transaccion::setCantidad(int cantidad) {
	_cantidadProductos = cantidad;
}

int Transaccion::getCantidad() {
	return _cantidadProductos;
}

Response<Transaccion> Transaccion::crearNuevaTransaccion(
	float monto, 
	const char* usuario, 
	char tipo, 
	int productoId, 
	int cantidad
	){

	Response<Transaccion> response;
	/*Transaccion transaccion(
		float monto,
		const char* usuario,
		char tipo,
		int productoId,
		int cantidad
	);*/


	return response;
}