#include "AdminCliente.h"
#include "InterfazUI.h"
#include "Archivo.h"

AdminCliente::AdminCliente(Sistema* sistema)
{
	_sistema = sistema;
	_nombreModulo = "Clientes";
	_nombreArchivo = "clientes.dat";
}

AdminCliente::~AdminCliente(){}

bool AdminCliente::moduloClienteActivo()
{
	return _sistema->getModulo() == _nombreModulo;
}

void AdminCliente::moduloClienteSalir()
{
	_sistema->setModuloPantalla("Principal", 888);
}

void AdminCliente::administrarModuloCliente()
{
	InterfazUI user_UI(_sistema);
	int opc = 0;
	while (moduloClienteActivo()) {
		user_UI.ver_MenuUsuario();
		opc = _sistema->getPantalla();
		switch (opc) {
		case 1:
			listarClientes();
			break;
		case 2:
			creacionNuevoCliente();
			break;
		case 3:
			//eliminarCliente();
			break;
		case 0:
			moduloClienteSalir();
			break;
		default:
			_sistema->setError("Opción inválida.");
			break;
		}
	}
}





