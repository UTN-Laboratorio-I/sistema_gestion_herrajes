#include "AdminConfig.h"
#include "InterfazUI.h"

AdminConfig::AdminConfig(Sistema* sistema):_sistema(sistema) {
	_sistema = sistema;
	_nombreModulo = "Configuracion";
}

AdminConfig::~AdminConfig() {}

bool AdminConfig::moduloConfigActivo() {
	return _sistema->getModulo() == _nombreModulo;
}

void AdminConfig::moduloConfigSalir() {
	_sistema->setModuloPantalla("Principal", 888);
}

void AdminConfig::administrarModuloConfig() {
	InterfazUI config_UI(_sistema);
	int opc = 0;
	while (moduloConfigActivo()) {
		config_UI.ver_MenuConfig();
		opc = _sistema->getPantalla();
		switch (opc) {
		case 1:
			//
			break;
		case 0:
			moduloConfigSalir();
			break;
		default:
			_sistema->setError("Opción inválida.");
			break;
		}
	}
}