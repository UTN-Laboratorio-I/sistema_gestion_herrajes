#include "AdminLogin.h"
#include "InterfazUI.h"

//Utilizamos el puntero de la instancia de Sistema para acceder a ella.
AdminLogin::AdminLogin(Sistema* sistema) : _sistema(sistema) {}

bool AdminLogin::verificarLogin() {
	InterfazUI UI;
	UI.vistaLogin();
	//Retorno true hasta añadir lógica de login
	int opc = 1;
	_sistema->setPantalla(opc);
	return true;
}