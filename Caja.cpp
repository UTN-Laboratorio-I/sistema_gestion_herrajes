#include "Caja.h"
#include "Archivo.h"
#include "ResponseDto.h"

//Response<Caja> Caja::gestionarCaja(float monto, char tipoTransaccion) {
//	Response<Caja> response;
//	Archivo<Caja> archivoCaja("caja.dat");
//	Caja caja;
//
//	switch (tipoTransaccion) {
//	case 'v':
//		caja.setDineroTotal(caja.getDineroTotal() + monto);
//		break;
//	case 'c':
//		caja.setDineroTotal(caja.getDineroTotal() - monto);
//		break;
//	default:
//		break;
//	}
//
//	//response = archivoCaja.grabarOModificarRegistro(caja, 1);
//
//	if (!response.getSuccess()) {
//		response.setFailure("No se ha podido registrar el cambio de caja");
//	}
//	return response;
//
//}

Caja Caja::getEstadoCaja() {
	Archivo<Caja> archivoCaja("caja.dat");
	vector<Caja> caja;
	caja = archivoCaja.listarRegistroArchivo();
	return caja[0];
}