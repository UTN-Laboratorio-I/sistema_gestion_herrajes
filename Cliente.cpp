#include "Cliente.h"


//Response<Cliente> Cliente::crearNuevoCliente() {
//	Response<Cliente> response;
//	Archivo<Cliente> archivo("Clientes.dat");
//	Cliente cliente;
//
//	//nombre cliente, dni, etc.
//
//	bool creado = archivo.grabarRegistro(cliente);
//
//	if (creado) {
//		response.setSuccess("Cliente creado correctamente", cliente);
//	}
//	else {
//		response.setFailure("Error al crear el cliente");
//	}
//
//	return response;
//}