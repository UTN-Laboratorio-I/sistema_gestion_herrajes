#include "AdminUsuario.h"
#include "InterfazUI.h"

AdminUsuario::AdminUsuario(Sistema* sistema) {
	_sistema = sistema;
	_nombreModulo = "Usuarios";
}

AdminUsuario::~AdminUsuario() {}

bool AdminUsuario::moduloUsuarioActivo() {
	return _sistema->getModulo() == _nombreModulo;
}

void AdminUsuario::moduloUsuarioSalir() {
	_sistema->setModuloPantalla("Principal", 888);
}

void AdminUsuario::administrarModuloUsuario() {
	InterfazUI user_UI(_sistema);
	int opc = 0;
	while (moduloUsuarioActivo()) {
		user_UI.ver_MenuUsuario();
		opc = _sistema->getPantalla();
		switch (opc) {
		case 1:
			//crearNuevoUsuario();
			break;
		case 2:
			//modificarUsuario();
			break;
		case 3:
			//eliminarUsuario();
			break;
		case 0:
			moduloUsuarioSalir();
			break;
		default:
			_sistema->setError("Opción inválida.");
			break;
		}
	}
}

