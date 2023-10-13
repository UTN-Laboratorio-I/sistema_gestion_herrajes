#include <iostream>
#include "Sistema.h"
#include "Producto.h"
#include "InterfazUI.h"
#include "AdminLogin.h"
#include "AdminCompra.h"
#include "AdminVenta.h"
#include "AdminABM.h"
#include "AdminReporte.h"

#pragma region Setters/Getters
Sistema::Sistema() {
	_encendido = true;
	_pantalla = 0;
	_usuarioLogged = "";
	_isAdmin = false;
	_modulo = "login";
	_subModulo = "";
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

void Sistema::setSubModulo(std::string modulo) {};
string Sistema::getSubModulo() { return _subModulo; };

void Sistema::setError(std::string mensaje) { _error.setError(true, mensaje); }
std::string Sistema::getError() { return _error.getErrorMensaje(); }
bool Sistema::hasError() { return _error.hasError(); }
void Sistema::limpiarError() { _error.limpiarErrores(); }

#pragma endregion

void Sistema::administrarPrograma() {
	InterfazUI UI(this);
	AdminLogin adm_login(this); //Facilitamos un puntero a la instancia de sistema para acceder a sus m�todos.  
	AdminCompra adm_compras(this);
	AdminVenta adm_ventas(this);
	AdminABM adm_abm(this);
	AdminReporte adm_reporte(this);
	bool logged = false;

	while (_encendido) {
		logged = adm_login.verificarLogin();
		if(logged)
			while (_modulo == "principal") {
				switch (_pantalla) {
				case 888: //Men� principal:
					UI.ver_MenuPrincipal();
					break;
				case 1: //Submen� Compras/stock:
					setModuloPantalla("compras", -1);
					adm_compras.administrarModuloCompra();
					break;
				case 2: //Submen� Ventas:
					setModuloPantalla("ventas", -1);
					adm_ventas.administrarModuloVenta();
					break;
				case 3: //Submen� ABM:
					setModuloPantalla("ABM", -1);
					adm_abm.administrarModuloABM();
					break;
				case 4: //Submen� Reportes:
					setModuloPantalla("Reportes", -1);
					adm_reporte.administrarModuloReporte();
					break;
				case 5: //Submen� Configuraci�n:
					cout << "Config";

					break;
				case 6: //Submen� Configuraci�n:
					cout << "USUARIOS";
					break;
				case 0: //Apagar o cerrar sesi�n:
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
			setModuloPantalla("principal", 888);
			break;
		case 1:
			//Apagar:
			setModulo("end");
			setEncendido(false);
			UI.mensajeCierrePrograma();
			break;
		case 2:
			//Re-loguear:
			setModulo("login");
		}
}


