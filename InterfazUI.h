#pragma once
#include "Sistema.h"
class InterfazUI
{
private:
	Sistema* _sistema;
public:
	//InterfazUI();
	InterfazUI(Sistema* sistema);
	void vistaLogin();

	void menuPrincipal();

	void subMenuCompras();

	void subMenuVentas();

	void subMenuAbm();

	void subMenuReportes();

};

