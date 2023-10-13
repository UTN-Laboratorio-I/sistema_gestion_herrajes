#include "AdminLogin.h"
#include "InterfazUI.h"

//Utilizamos el puntero de la instancia de Sistema para acceder a ella.
AdminLogin::AdminLogin(Sistema* sistema) : _sistema(sistema) {}

bool AdminLogin::verificarLogin() {
	InterfazUI UI_login(_sistema);
	UI_login.vistaLogin();
	cout << "USER: ";
	cin >> _usuario;
	cout << "PASSWORD: ";
	cin >> _password;

	bool validar_login = login();

	if (validar_login) {
		_sistema->setModuloPantalla("principal",888);
		_sistema->limpiarError();
		return true;
	}
	else {
		_sistema->setError("User o Password incorrectos.");
		return false;
	}
	//Retorno true hasta añadir lógica de login
}

bool AdminLogin::login() {
	//Validar usuarios y contraseñas
	if(_usuario == "admin" && _password == "admin")
	{
		_sistema->setUsuarioLogged(_usuario);
		_sistema->setIsAdmin(true);
		return true;
	}
	else
		return false;
}