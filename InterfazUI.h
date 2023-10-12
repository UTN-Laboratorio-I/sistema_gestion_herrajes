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

	void vistaLogin();

	void ver_MenuPrincipal();

	void ver_MenuCompras();

	void ver_menuCrearCompraProducto();

	void subMenuVentas();

	void subMenuAbm();

	void subMenuReportes();

};

