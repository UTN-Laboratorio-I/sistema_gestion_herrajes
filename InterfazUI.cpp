#include <iostream>
#include "InterfazUI.h"
#include <string>
#include "Fecha.h"
#pragma warning (disable : 4996)

using namespace std;

#pragma region HelpersInterfaz
/// <summary>
/// Limpia la consola entre pantalla y pantalla.
/// </summary>
void limpiarConsola() {
	system("cls");
}
#pragma endregion

//Constructores:
InterfazUI::InterfazUI(Sistema* sistema) : _sistema(sistema) {}

/// <summary>
/// Header utilizado en todas las vistas.
/// El mismo muestra info del usuario, hora y errores.
/// </summary>
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
		cout << "---------------------------------" << endl;
		cout << "Error: " << error << endl;
	}
	cout << "---------------------------------" << endl << endl;
}
/// <summary>
/// Controla que la opción seleccionada por el menú sea válida.
/// </summary>
bool InterfazUI::opcionesValidasMenu(int inicio, int fin, int seleccion, bool imprimir, bool admiteAtras)
{
	//Considerar un typeof para evitar otros tipos de caracteres.
	bool error = _sistema->hasError();
	if ((seleccion < inicio && !admiteAtras) || (seleccion > fin && !imprimir)) {
		std::string mensaje = "Seleccione una opcion entre "+std::to_string(inicio)+" y "+std::to_string(fin);
			_sistema->setError(mensaje);
			return false;
	}
	if(error) _sistema->limpiarError();
	return true;
}

/// <summary>
/// Vista de login principal.
/// </summary>
void InterfazUI::vistaLogin() {
	headerDinamico();
	std::string usuario;
	cout << "Ingrese su nombre: ";
	cin >> usuario;

	_sistema->setUsuarioLogged(usuario);

	system("cls");
}

void InterfazUI::ver_MenuPrincipal() {
	limpiarConsola();
	int opc;
	bool verificado=false;

	while (!verificado) {
	headerDinamico();
	cout << "1) Compras - Stock" << endl;
	cout << "2) Ventas" << endl;
	cout << "3) ABM" << endl;
	cout << "4) Reportes" << endl;
	cout << "5) Configuracion" << endl;
	cout << "6) USUARIO" << endl;
	cout << "0) Salir" << endl;
	cin >> opc;
	verificado = opcionesValidasMenu(1, 6, opc);
	}
	_sistema->setPantalla(opc);
}

#pragma region UI_Compras

/// <summary>
/// 
/// </summary>
/// <returns></returns>
void InterfazUI::ver_MenuCompras() {
	limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
	headerDinamico();
	cout << "1) Compra Productos" << endl;
	cout << "2) Listar Productos" << endl;
	cout << "3) Buscar Producto" << endl << endl;
	cout << "0) <- Atras" << endl;
	cin >> opc;
	verificado = opcionesValidasMenu(1, 3, opc);
	}
	_sistema->setModuloPantalla("compras", opc);
}

void InterfazUI::ver_MenuCrearCompraProducto() {
	limpiarConsola();
	int opc;
	bool verificado = false;
	
	while (!verificado) {
		headerDinamico();
		cout << "Mostrar opciones para comprar productos" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 1, opc);
	}
	_sistema->setModuloPantalla("compras", opc);
}

#pragma endregion UI_Compras

#pragma region UI_Ventas
void InterfazUI::ver_MenuVentas() {
	limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Registrar venta" << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 1, opc);
	}
	_sistema->setPantalla(opc);
}


#pragma endregion UI_Ventas

void InterfazUI::ver_MenuABM() {
	limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) ABM Clientes" << endl;
		cout << "2) ABM Proveedores" << endl;
		cout << "3) ABM Productos" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 3, opc);
	}
	_sistema->setPantalla(opc);
}

void InterfazUI::ver_MenuReportes() {
	limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Reporte Clientes" << endl;
		cout << "2) Reporte Proveedores" << endl;
		cout << "3) Reporte Productos" << endl;
		cout << "4) Reporte Ventas" << endl;
		cout << "4) Reporte Usuarios" << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 4, opc);
	}
	_sistema->setModuloPantalla("compras", opc);
}

void InterfazUI::ver_MenuUsuario() {
	limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Reporte Clientes" << endl;
		cout << "2) Reporte Proveedores" << endl;
		cout << "3) Reporte Productos" << endl;
		cout << "4) Reporte Ventas" << endl;
		cout << "4) Reporte Usuarios" << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 4, opc);
	}
	_sistema->setModuloPantalla("compras", opc);
}