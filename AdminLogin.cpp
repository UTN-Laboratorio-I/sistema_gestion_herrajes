#include "AdminLogin.h"
#include "InterfazUI.h"

//Utilizamos el puntero de la instancia de Sistema para acceder a ella.
AdminLogin::AdminLogin(Sistema* sistema) : _sistema(sistema) {}

bool AdminLogin::verificarLogin() {
	InterfazUI UI_login(_sistema);
	UI_login.vistaLogin();
	//Retorno true hasta añadir lógica de login
	_sistema->setModuloPantalla("principal",888);
	return true;
}