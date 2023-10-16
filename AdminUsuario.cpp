#include "AdminUsuario.h"
#include "InterfazUI.h"
#include "Archivo.h"

AdminUsuario::AdminUsuario(Sistema* sistema) {
	_sistema = sistema;
	_nombreModulo = "Usuarios";
	_nombreArchivo = "usuarios.dat";
}

AdminUsuario::~AdminUsuario() {}

bool AdminUsuario::moduloUsuarioActivo() {
	return _sistema->getModulo() == _nombreModulo;
}

void AdminUsuario::moduloUsuarioSalir() {
	_sistema->setModuloPantalla("Principal", 888);
}

void AdminUsuario::administrarModuloUsuario() {
	InterfazUI user_UI(_sistema);
	int opc = 0;
	while (moduloUsuarioActivo()) {
		user_UI.ver_MenuUsuario();
		opc = _sistema->getPantalla();
		switch (opc) {
		case 1:
			listarUsuarios();
			break;
		case 2:
			creacionNuevoUsuario();
			break;
		case 3:
			//eliminarUsuario();
			break;
		case 0:
			moduloUsuarioSalir();
			break;
		default:
			_sistema->setError("Opción inválida.");
			break;
		}
	}
}


void AdminUsuario::listarUsuarios() {
	InterfazUI user_UI(_sistema);
	Archivo<Usuario> archivo(_nombreArchivo);
	Usuario usuario;
	vector<Usuario> usuarios;

	usuarios = usuario.listarUsuarios();

	for (Usuario user : usuarios) {
		cout << user.getUsuario() << endl;
		cout << user.getPassword() << endl;
		cout << user.getNombre() << endl;
		cout << user.getRol() << endl;
		cout << user.getIsAdmin() << endl;
		cout << "------------------------" << endl<<endl;
	}
	system("pause");
}

void AdminUsuario::creacionNuevoUsuario() {
	InterfazUI user_UI(_sistema);
	bool continuar = false;
	while (!continuar) {
		Usuario nuevoUser;
		//Utilizo el método de usuario para crearlo:
		//Response es un tipo de dato que contiene success y mensaje, y permite
		//saber si la operación fue exitosa o no, y en caso de no serlo, manejar el error.

		//Toda la creación de usuario y su guardado en el archivo se encarga el método de Usuario (crearNuevoUsuario())

		//AdminUsuario::creacionNuevoUsuario solo se encarga de 'gestionar' la creación y devolver
		//si fue exitoso o no, no le importa que pasa dentro de nuevoUser.crearNuevoUsuario(), solo su respuesta.
		Response res = nuevoUser.crearNuevoUsuario();

		//En caso de que la respuesta sea exitosa, permito la salida del bucle while:
		if (res.getSuccess()) {
			continuar = true;
		}
		else {
		//Caso contrario, no permito la salida del bucle while hasta que se cree el usuario correctamente
			_sistema->setError(res.getMessage());

			continuar = user_UI.mensajeCancelarEjecucion("creacion de usuario");

		}
		_sistema->limpiarError();
	}
	//Si salgo del bucle while, es porque se creó el usuario correctamente o cancelé la carga por lo que limpio los errores:
	_sistema->limpiarError();
}

