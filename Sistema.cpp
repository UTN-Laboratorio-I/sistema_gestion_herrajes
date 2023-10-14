#include <iostream>
#include "Sistema.h"
#include "Producto.h"
#include "InterfazUI.h"
#include "AdminLogin.h"
#include "AdminCompra.h"
#include "AdminVenta.h"
#include "AdminABM.h"
#include "AdminReporte.h"
#include "AdminUsuario.h"
#include "AdminConfig.h"

#pragma region Setters/Getters
Sistema::Sistema() {
	_encendido = true;
	_pantalla = 0;
	_usuarioLogged = "";
	_isAdmin = false;
	_modulo = "Login";
}

void Sistema::setEncendido(bool set) { _encendido = set; }
bool Sistema::getEncendido() { return _encendido; }

void Sistema::setUsuarioLogged(std::string nombre) { _usuarioLogged = nombre; }
std::string Sistema::getUsuarioLogged() { return _usuarioLogged; }

void Sistema::setIsAdmin(bool set) { _isAdmin = set; }
bool Sistema::getIsAdmin() { return _isAdmin; }

void Sistema::setPantalla(int opc) { _pantalla = opc; }
int Sistema::getPantalla() { return _pantalla; }

void Sistema::setModulo(std::string modulo) { _modulo = modulo; }
string Sistema::getModulo() { return _modulo; }

void Sistema::setError(std::string mensaje) { _error.setError(true, mensaje); }
std::string Sistema::getError() { return _error.getErrorMensaje(); }
bool Sistema::hasError() { return _error.hasError(); }
void Sistema::limpiarError() { _error.limpiarErrores(); }

#pragma endregion

void Sistema::administrarPrograma() {
	//En todos los casos, pasamos como parametro esta misma instancia de Sistema
	//Para poder hacer uso de sus métodos y atributos
	InterfazUI UI(this);
	AdminLogin adm_login(this); 
	AdminCompra adm_compras(this);
	AdminVenta adm_ventas(this);
	AdminABM adm_abm(this);
	AdminReporte adm_reporte(this);
	AdminUsuario adm_usuario(this);
	AdminConfig adm_config(this);

	bool logged = false;

	while (_encendido) {
		logged = adm_login.verificarLogin();
		if(logged)
			while (_modulo == "Principal") {
				switch (_pantalla) {
				case 888: //Menú principal:
					UI.ver_MenuPrincipal();
					break;
				case 1: //Submenú Compras/stock:
					setModulo("Compras");
					adm_compras.administrarModuloCompra();
					break;
				case 2: //Submenú Ventas:
					setModulo("Ventas");
					adm_ventas.administrarModuloVenta();
					break;
				case 3: //Submenú ABM:
					setModulo("ABM");
					adm_abm.administrarModuloABM();
					break;
				case 4: //Submenú Reportes:
					setModulo("Reportes");
					adm_reporte.administrarModuloReporte();
					break;
				case 5: //Submenú Configuración:
					setModulo("Configuracion");
					adm_config.administrarModuloConfig();
					break;
				case 6: //Submenú Configuración:
					setModulo("Usuarios");
					adm_usuario.administrarModuloUsuario();
					break;
				case 0: //Apagar o cerrar sesión:
					apagarOCerrarSesion();
					break;
				}
			}
	}
}

void Sistema::setModuloPantalla(string modulo, int pantalla) {
	setModulo(modulo);
	setPantalla(pantalla);
}

void Sistema::apagarOCerrarSesion() {
	InterfazUI UI(this);
		int opc = UI.apagarOCerrarSesion();
		switch (opc) {
		case 0:
			//Cancelar:
			setModuloPantalla("Principal", 888);
			break;
		case 1:
			//Apagar:
			setModulo("end");
			setEncendido(false);
			UI.mensajeCierrePrograma();
			break;
		case 2:
			//Re-loguear:
			AdminLogin login(this);
			login.cerrarSesion();
			setModulo("Login");
		}
}


