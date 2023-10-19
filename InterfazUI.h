#pragma once
#include "Sistema.h"
class InterfazUI
{
private:
	Sistema* _sistema;
public:
	//InterfazUI();
	InterfazUI();

	InterfazUI(Sistema* sistema);

	void headerDinamico();
	bool opcionesValidasMenu(int inicio, int fin, int seleccion, bool imprimir = false, bool admiteAtras = true);
	bool mensajeCancelarEjecucion(string ejecucion);

	void vistaLogin();
	int apagarOCerrarSesion();
	void mensajeCierrePrograma();

	void ver_MenuPrincipal();

	void ver_MenuCompras();
	void ver_MenuCrearCompraProducto();

	void ver_MenuABM();
	void ver_SubMenuABMCliente();
	void ver_SubMenuABMProveedor();
	void ver_SubMenuABMProducto();

	void ver_MenuReportes();
	void ver_SubMenuReportesCliente();
	void ver_SubMenuReportesProveedor();
	void ver_SubMenuReportesProducto();
	void ver_SubMenuReportesCaja();

	void ver_MenuConfig();

	void ver_MenuUsuario();

	void ver_MenuVentas();
	int ver_VentasClienteExistente();
};

