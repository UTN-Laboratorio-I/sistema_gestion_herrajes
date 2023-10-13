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
	_modulo = "principal";
	_subModulo = "";
}

void Sistema::setEncendido(bool set) { _encendido = set; }
bool Sistema::getEncendido() { return _encendido; }

void Sistema::setUsuarioLogged(std::string nombre) { _usuarioLogged = nombre; }
std::string Sistema::getUsuarioLogged() { return _usuarioLogged; }

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
	AdminLogin adm_login(this); //Facilitamos un puntero a la instancia de sistema para acceder a sus métodos.  
	AdminCompra adm_compras(this);
	AdminVenta adm_ventas(this);
	AdminABM adm_abm(this);
	AdminReporte adm_reporte(this);

	while (_encendido) {
		while (_modulo == "principal") {
			switch (_pantalla) {
			case 0: //Login
				adm_login.verificarLogin();
				break;
			case 888: //Menú principal:
				UI.ver_MenuPrincipal();
				break;
			case 1: //Submenú Compras/stock:
				setModuloPantalla("compras", -1);
				adm_compras.administrarModuloCompra();
				break;
			case 2: //Submenú Ventas:
				setModuloPantalla("ventas", -1);
				adm_ventas.administrarModuloVenta();
				break;
			case 3: //Submenú ABM:
				setModuloPantalla("ABM", -1);
				adm_abm.administrarModuloABM();
				break;
			case 4: //Submenú Reportes:
				setModuloPantalla("Reportes", -1);
				adm_reporte.administrarModuloReporte();
				break;
			case 5: //Submenú Configuración:
				cout << "Config";

				break;
			case 6: //Submenú Configuración:
				cout << "USUARIOS";

				break;
			case 999: //Salir
				cout << "Salir";
				break;
			}
		}
		//Si el programa sigue encendido, mostramos el menú principal nuevamente:
		if(_encendido ==true) setModuloPantalla("principal",1); 
	}
	

}

void Sistema::setModuloPantalla(string modulo, int pantalla) {
	setModulo(modulo);
	setPantalla(pantalla);
}



