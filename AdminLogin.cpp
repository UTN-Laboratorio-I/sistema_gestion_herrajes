#include "AdminLogin.h"
#include "InterfazUI.h"
#include "Helper.h"

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
		_sistema->setModuloPantalla("Principal",888);
		_sistema->limpiarError();
		return true;
	}
	else {
		_sistema->setError("User o Password incorrectos.");
		return false;
	}
	//Retorno true hasta añadir lógica de login
}

void AdminLogin::cerrarSesion() {
	_sistema->limpiarUsuario();
}

bool AdminLogin::login() {
	//Validar usuarios y contraseñas
	if(_usuario == "admin" && _password == "admin")
	{
		_sistema->setUsuarioLogged("admin", "admin","admin",true);
		return true;
	}
	else
		return false;
}