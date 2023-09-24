#include <iostream>
#include "InterfazUI.h"

using namespace std;

#pragma region HelpersInterfaz
void header(string usuario = "") {
	cout << "Sistema de Gestion" << endl;
	cout << "------------------" << usuario << endl << endl;
}
#pragma endregion


void InterfazUI::vistaLogin() {
	header();
	std::string usuario;
	cout << "Ingrese su nombre: ";
	cin >> usuario;

	setUsuarioLogged(usuario);

	system("cls");
	cout << "Bienvenido " << usuario << endl;
}

void InterfazUI::menuPrincipal() {
	string usuario = getUsuarioLogged();
	int opc;
	header(usuario);
	cout << "1) Compras - Stock" << endl;
	cout << "2) Ventas" << endl;
	cout << "3) ABM" << endl;
	cout << "4) Reportes" << endl;
	cout << "5) Configuracion" << endl;
	cout << "0) Salir" << endl;
	cin >> opc;
	//Añadir validación opciones pantalla.
	setPantalla(opc);
}

void InterfazUI::subMenuCompras() {

}

void InterfazUI::subMenuVentas() {

}

void InterfazUI::subMenuAbm() {

}

void InterfazUI::subMenuReportes() {

}