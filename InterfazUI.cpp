#include <iostream>
#include "InterfazUI.h"
#include <string>
#include "Fecha.h"
#include "Helper.h"
#pragma warning (disable : 4996)

using namespace std;

//Constructores:
InterfazUI::InterfazUI(Sistema* sistema) : _sistema(sistema) {}

/// <summary>
/// Header utilizado en todas las vistas.
/// El mismo muestra info del usuario, hora y errores.
/// </summary>
void InterfazUI::headerDinamico()
{
	Helper helper;
	Fecha fecha;
	string ahora = fecha.hoy();

	helper.limpiarConsola();
	string usuario = _sistema->getUsuarioLogged();
	bool error = _sistema->hasError();
	cout << "Sistema de Gestion" << " - " << ahora << endl;
	if (usuario != "") {
		cout << "User: " << usuario << endl;
	}
	cout << "MENU " <<_sistema->getModulo() << endl;

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

bool InterfazUI::mensajeCancelarEjecucion(string ejecucion) {
	headerDinamico();
	int opc;
	bool verificado = false;

	while (verificado) {
	cout << "Desea salir de " << ejecucion << "?" << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl << endl;
	cin >> opc;
	verificado = opcionesValidasMenu(1, 2, opc, false, false);
	}

	if (opc == 1) {
		return true;
	}
	else {
		return false;
	}
}

#pragma region Login/Sesion
/// <summary>
/// Vista de login principal.
/// </summary>
void InterfazUI::vistaLogin() {
	headerDinamico();
	std::string usuario;
	cout << "Ingrese User/Password " << endl<<endl;
}

int InterfazUI::apagarOCerrarSesion() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Apagar" << endl;
		cout << "2) Cerrar sesion" << endl << endl;
		cout << "0) <- Cancelar" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 2, opc);
	}
	return opc;
}

void InterfazUI::mensajeCierrePrograma() {
	Helper helper;
	helper.limpiarConsola();
	cout << "Cerrando programa..." << endl;
}
#pragma endregion Login/Sesion

#pragma region UI_Principal
void InterfazUI::ver_MenuPrincipal() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado=false;
	string user = _sistema->getUsuarioLogged();
	bool isAdmin = _sistema->getIsAdminUsuarioLogged();
	int opcMax; //Si el usuario es admin, se muestra la opcion de usuario, sino se oculta.a
	opcMax = isAdmin? 6 : 5;

	while (!verificado) {
	headerDinamico();
	cout << "1) Compras - Stock" << endl;
	cout << "2) Ventas" << endl;
	cout << "3) ABM" << endl;
	cout << "4) Reportes" << endl;
	cout << "5) Configuracion" << endl;
	if(isAdmin){ cout << "6) USUARIO" << endl << endl; }
	cout << "0) Salir" << endl;
	cin >> opc;
	verificado = opcionesValidasMenu(1, opcMax, opc);
	}
	_sistema->setPantalla(opc);
}
#pragma endregion UI_Principal

#pragma region UI_Compras

/// <summary>
/// 
/// </summary>
/// <returns></returns>
void InterfazUI::ver_MenuCompras() {
	Helper helper;
	helper.limpiarConsola();
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
	_sistema->setModuloPantalla("Compras", opc);
}

void InterfazUI::ver_MenuCrearCompraProducto() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;
	
	while (!verificado) {
		headerDinamico();
		cout << "Mostrar opciones para comprar productos" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 1, opc);
	}
	_sistema->setModuloPantalla("Compras", opc);
}

#pragma endregion UI_Compras

#pragma region UI_Ventas
void InterfazUI::ver_MenuVentas() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Registrar venta" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 1, opc);
	}
	_sistema->setPantalla(opc);
}


#pragma endregion UI_Ventas

#pragma region UI_ABM


void InterfazUI::ver_MenuABM() {
	Helper helper;
	helper.limpiarConsola();
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

void InterfazUI::ver_SubMenuABMCliente() {
	Helper helper;
	helper.limpiarConsola();
	bool verificado = false;
	int opc;
	while (!verificado) {
		headerDinamico();
			cout << "1) Crear Cliente" << endl;
			cout << "2) Modificar Cliente" << endl;
			cout << "3) Eliminar Cliente" << endl;
			cout << "4) Listar Clientes" << endl;
			cout << "5) Buscar Cliente" << endl << endl;
			cout << "0) <- Atras" << endl;

		/*	break;
		case 2:
			cout << "1) Crear Proveedor" << endl;
			cout << "2) Modificar Proveedor" << endl;
			cout << "3) Eliminar Proveedor" << endl;
			cout << "4) Listar Proveedores" << endl;
			cout << "5) Buscar Proveedor" << endl << endl;
			cout << "0) <- Atras" << endl;

			_sistema->setModuloPantalla("ABM Proveedor", opc);

			break;
		case 3:
			cout << "1) Crear Producto" << endl;
			cout << "2) Modificar Producto" << endl;
			cout << "3) Eliminar Producto" << endl;
			cout << "4) Listar Productos" << endl;
			cout << "5) Buscar Producto" << endl << endl;
			cout << "0) <- Atras" << endl;

			_sistema->setModuloPantalla("ABM Producto", opc);

			break;
		}*/
		cin >> opc;
		verificado = opcionesValidasMenu(1, 5, opc);
	}
	_sistema->setModuloPantalla("ABM Clientes", opc);

}
	void InterfazUI::ver_SubMenuABMProveedor() {
		Helper helper;
		helper.limpiarConsola();
		int opc;
		bool verificado = false;

		while (!verificado) {
			headerDinamico();
			cout << "1) Crear Proveedor" << endl;
			cout << "2) Modificar Proveedor" << endl;
			cout << "3) Eliminar Proveedor" << endl;
			cout << "4) Listar Proveedores" << endl;
			cout << "5) Buscar Proveedor" << endl << endl;
			cout << "0) <- Atras" << endl;
			cin >> opc;
			verificado = opcionesValidasMenu(1, 5, opc);
		}
		_sistema->setModuloPantalla("ABM Proveedor", opc);
	}

	void InterfazUI::ver_SubMenuABMProducto() {
		Helper helper;
		helper.limpiarConsola();
		int opc;
		bool verificado = false;

		while (!verificado) {
			headerDinamico();
			cout << "1) Crear Producto" << endl;
			cout << "2) Modificar Producto" << endl;
			cout << "3) Eliminar Producto" << endl;
			cout << "4) Listar Productos" << endl;
			cout << "5) Buscar Producto" << endl << endl;
			cout << "0) <- Atras" << endl;
			cin >> opc;
			verificado = opcionesValidasMenu(1, 5, opc);
		}
		_sistema->setModuloPantalla("ABM Producto", opc);
	}


#pragma endregion UI_ABM

#pragma region UI_Reportes
void InterfazUI::ver_MenuReportes() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Reporte Clientes" << endl;
		cout << "2) Reporte Proveedores" << endl;
		cout << "3) Reporte Productos" << endl;
		cout << "4) Reporte Caja" << endl;
		cout << "4) Reporte Usuarios" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 4, opc);
	}
	_sistema->setModuloPantalla("Reporte", opc);
}

void InterfazUI::ver_SubMenuReportesCliente() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Listar Clientes" << endl;
		cout << "2) Buscar Cliente" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 2, opc);
	}
	_sistema->setModuloPantalla("Reporte Clientes", opc);
}

void InterfazUI::ver_SubMenuReportesProveedor() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Listar Proveedores" << endl;
		cout << "2) Buscar Proveedor" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 2, opc);
	}
	_sistema->setModuloPantalla("Reporte Proveedores", opc);
}

void InterfazUI::ver_SubMenuReportesProducto() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Listar Productos" << endl;
		cout << "2) Buscar Producto" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 2, opc);
	}
	_sistema->setModuloPantalla("Reporte Productos", opc);
}

void InterfazUI::ver_SubMenuReportesCaja() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Listar Ventas" << endl;
		cout << "2) Buscar Venta" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 2, opc);
	}
	_sistema->setModuloPantalla("Reporte Ventas", opc);
}


#pragma endregion UI_Reportes

#pragma region UI_Usuario
void InterfazUI::ver_MenuUsuario() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Listar usuarios" << endl;
		cout << "2) Crear nuevo usuario" << endl;
		cout << "3) Modificar usuario" << endl;
		cout << "4) Eliminar usuario" << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 3, opc);
	}
	_sistema->setModuloPantalla("Usuarios", opc);
}
#pragma endregion UI_Usuario

#pragma region UI_Configuracion
void InterfazUI::ver_MenuConfig() {
	Helper helper;
	helper.limpiarConsola();
	int opc;
	bool verificado = false;

	while (!verificado) {
		headerDinamico();
		cout << "1) Configurar fecha/hora" << endl;
		cout << "2) Configurar margen de utilidad " << endl;
		cout << "3) Configurar ruta archivo" << endl << endl;
		cout << "0) <- Atras" << endl;
		cin >> opc;
		verificado = opcionesValidasMenu(1, 4, opc);
	}
	_sistema->setModuloPantalla("Configuracion", opc);
}
#pragma endregion UI_Configuracion