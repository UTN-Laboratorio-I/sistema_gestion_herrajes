#include <iostream>
#include "InterfazUI.h"
#include <string>
#include "Fecha.h"
#pragma warning (disable : 4996)

using namespace std;

#pragma region HelpersInterfaz
void limpiarConsola() {
	system("cls");
}
#pragma endregion

InterfazUI::InterfazUI(Sistema* sistema) : _sistema(sistema) {}

void InterfazUI::headerDinamico() 
{
	Fecha fecha;
	string ahora = fecha.hoy();

	limpiarConsola();
	string usuario = _sistema->getUsuarioLogged();
	bool error = _sistema->hasError();
	cout << "Sistema de Gestion" << " - " << ahora << endl;
	if (usuario != "") {
		cout << "User: " << usuario << endl;
	}
	if (error) {
		std::string error = _sistema->getError();
		cout << "------------------" << endl;
		cout << "Error: " << error << endl;
	}
	cout << "------------------" << endl << endl;
}
/// <summary>
/// Se controla que la opción seleccionada sea válida.
/// </summary>
bool InterfazUI::opcionesValidasMenu(int inicio, int fin, int seleccion, bool imprimir, bool admiteAtras)
{
	bool error = _sistema->hasError();
	if ((seleccion < inicio && !admiteAtras) || (seleccion > fin && !imprimir)) {
		std::string mensaje = "Seleccione una opcion entre "+std::to_string(inicio)+" y "+std::to_string(fin);
			_sistema->setError(mensaje);
			return false;
	}
	if(error) _sistema->limpiarError();
	return true;
}

//InterfazUI::InterfazUI() {}

void InterfazUI::vistaLogin() {
	limpiarConsola();
	headerDinamico();
	std::string usuario;
	cout << "Ingrese su nombre: ";
	cin >> usuario;

	_sistema->setUsuarioLogged(usuario);

	system("cls");
}

void InterfazUI::menuPrincipal() {
	limpiarConsola();
		string usuario = _sistema->getUsuarioLogged();
	int opc;
	bool verificado=false;

	while (!verificado) {
	headerDinamico();
	cout << "1) Compras - Stock" << endl;
	cout << "2) Ventas" << endl;
	cout << "3) ABM" << endl;
	cout << "4) Reportes" << endl;
	cout << "5) Configuracion" << endl;
	cout << "6) Reporte" << endl;
	cout << "7) USUARIO" << endl;
	cout << "0) Salir" << endl;
	cin >> opc;
	verificado = opcionesValidasMenu(1, 7, opc);
	}
	_sistema->setPantalla(opc);
}

int InterfazUI::subMenuCompras() {
	string usuario = _sistema->getUsuarioLogged();
	int opc;
	bool verificado = false;

	while (!verificado) {
	headerDinamico();
	cout << "1) Compra Productos" << endl;
	cout << "2) Listar Productos" << endl;
	cout << "3) Buscar Producto" << endl << endl;
	cout << "0) <- Atras";
	cin >> opc;
	verificado = opcionesValidasMenu(1, 3, opc);
	}
	return opc;
}

void InterfazUI::subMenuVentas() {

}

void InterfazUI::subMenuAbm() {

}

void InterfazUI::subMenuReportes() {

}