#include "AdminLogin.h"
#include "InterfazUI.h"
#include "Helper.h"
#include <functional>
using namespace std;

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


bool AdminLogin::validar(Usuario user) {
	if(strcmp(user.getUsuario(), _usuario) == 0 && strcmp(user.getPassword(), _password) == 0)
		return true;
	else
		return false;
}

typedef bool (AdminLogin:: *FuncionValidar)(Usuario); //Esto lo utilizamos para poder hacer referencia
//al puntero de UNA FUNCIÓN X.
Usuario AdminLogin::buscarUsuario() {
	Archivo<Usuario> archivo("usuarios.dat");
	Usuario usuario;
	auto fn = [this](Usuario user) { return this->validar(user); };
	usuario = archivo.buscarRegistroByParametro(fn);
	return usuario;
}

bool AdminLogin::login() {
	//Validar usuarios y contraseñas

	Usuario usuario = buscarUsuario();

	if(strcmp(_usuario, "admin") == 0 && strcmp(_password, "admin") == 0)
	{
		_sistema->setUsuarioLogged("admin", "admin","admin",true);
		return true;
	}else if(usuario.getUsuario()[0] != '\0') { //Chequeamos que el primer valor de la cadena de caracteres no sea el final de la misma. (O sea, Sin contenido)
		_sistema->setUsuarioLogged(usuario.getUsuario(), usuario.getNombre(), usuario.getRol(), usuario.getIsAdmin());
	}
	else
		return false;
}
