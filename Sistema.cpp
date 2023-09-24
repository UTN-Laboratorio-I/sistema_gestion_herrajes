#include <iostream>
#include "Sistema.h"
#include "Producto.h"
#include "Archivo.h"
#include "Archivo.cpp"
#include "InterfazUI.h"

#pragma region Setters/Getters
void Sistema::setEncendido(bool set) { this->_encendido = set; }
bool Sistema::getEncendido() { return this->_encendido; }

void Sistema::setUsuarioLogged(std::string nombre) { this->_usuarioLogged = nombre; }
std::string Sistema::getUsuarioLogged() { return this->_usuarioLogged; }

void Sistema::setPantalla(int opc) { this->_pantalla = opc; }
int Sistema::getPantalla() { return this->_pantalla; }

#pragma endregion

//void Sistema::login() {
//	std::string usuario;
//	cout << "Ingrese su nombre: ";
//	cin >> usuario;
//	
//	setUsuarioLogged(usuario);
//
//	system("cls");
//	cout << "Bienvenido " << usuario << endl;
//}

void Sistema::administrarPrograma() {
	InterfazUI UI;
	
	while (_encendido) {
		switch (_pantalla) {
		case 0: //Login
			UI.vistaLogin();
			break;
		case 1: //Men� principal:
			UI.menuPrincipal();
			break;
		case 2: //Submen� Compras/stock:
			break;
		case 3: //Submen� Ventas:
			break;
		case 4: //Submen� ABM:
			break;
		case 5: //Submen� Reportes:
			break;
		case 6: //Submen� Configuraci�n:
			break;
		case 999: //Salir

			break;
		}

	}
	
	cout << "Cerrando sesion...";
}