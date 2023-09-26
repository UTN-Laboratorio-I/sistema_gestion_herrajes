#include <iostream>
#include "Sistema.h"
#include "Producto.h"
#include "Archivo.h"
#include "Archivo.cpp"
#include "InterfazUI.h"
#include "AdminLogin.h"
#include "AdminCompra.h"
#include "AdminVenta.h"
#include "AdminABM.h"

#pragma region Setters/Getters
Sistema::Sistema() {
	_encendido = true;
	_pantalla = 0;
	_usuarioLogged = "";
}

void Sistema::setEncendido(bool set) { _encendido = set; }
bool Sistema::getEncendido() { return _encendido; }

void Sistema::setUsuarioLogged(std::string nombre) { _usuarioLogged = nombre; }
std::string Sistema::getUsuarioLogged() { return _usuarioLogged; }

void Sistema::setPantalla(int opc) { _pantalla = opc; }
int Sistema::getPantalla() { return _pantalla; }

#pragma endregion

void Sistema::administrarPrograma() {
	InterfazUI UI(this);
	AdminLogin adm_login(this); //Facilitamos un puntero a la instancia de sistema para acceder a sus métodos.  
	AdminCompras adm_compras;
	AdminVentas adm_ventas;
	AdminABM adm_ABM;

	while (_encendido) {
		switch (_pantalla) {
		case 0: //Login
			adm_login.verificarLogin();
			break;
		case 1: //Menú principal:
			UI.menuPrincipal();

			break;
		case 2: //Submenú Compras/stock:
			//adm_compras.;
			break;
		case 3: //Submenú Ventas:
			cout << "Ventas";

			break;
		case 4: //Submenú ABM:
			cout << "ABM";

			break;
		case 5: //Submenú Reportes:
			cout << "Reportes";

			break;
		case 6: //Submenú Configuración:
			cout << "Config";

			break;
		case 7: //Submenú Configuración:
			cout << "USUARIOS";

			break;
		case 999: //Salir
			cout << "Salir";

			break;
		}
	}
	
}