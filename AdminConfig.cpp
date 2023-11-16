#include "AdminConfig.h"
#include "InterfazUI.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Backup.h"

AdminConfig::AdminConfig(Sistema* sistema):_sistema(sistema) {
	_sistema = sistema;
	_nombreModulo = "Configuracion";
}

AdminConfig::~AdminConfig() {}

bool AdminConfig::moduloConfigActivo() {
	return _sistema->getModulo() == _nombreModulo;
}

void AdminConfig::moduloConfigSalir() {
	_sistema->setModuloPantalla("Principal", 888);
}

void AdminConfig::administrarModuloConfig() {
	InterfazUI config_UI(_sistema);
	int opc = 0;
	while (moduloConfigActivo()) {
		config_UI.ver_MenuConfig();
		opc = _sistema->getPantalla();
		switch (opc) {
		case 4:
			realizarCopiaDeSeguridad();
			break;
		case 0:
			moduloConfigSalir();
			break;
		default:
			_sistema->setError("Opción inválida.");
			break;
		}
	}
}

void AdminConfig::realizarCopiaDeSeguridad()
{

	Backup <Producto> backUpProducto("productos.dat","productos.bak");
	Backup <Cliente> backUpcliente("clientes.dat","clientes.bak");
	Backup <Proveedor> backUpProveedor("proveedores.dat","proveedores.bak");

	Helper helper;
	Producto producto;
	Proveedor proveedor;
	Cliente cliente;

	bool continuar = false;
	int opc;

	helper.limpiarConsola();

	cout << "---------------- REALIZAR COPIA DE SEGURIDAD DEL SISTEMA ----------------" << endl << endl;

	while (!continuar)
	{
		cout << "Desea realizar la copia de seguridad de Productos, Clientes y Proveedores?" << endl;
		cout << "1) Si - 2) No " << endl;
		cin >> opc;

		if (opc == 1)
		{
			cout << endl << "Inciando copia de seguridad..."<< endl << endl;
			_sleep(2000);

			backUpProducto.grabarCopiaDeSeguridad(producto);
			cout <<"Productos!" << endl << endl;
			_sleep(1000);
			backUpcliente.grabarCopiaDeSeguridad(cliente);
			cout  << "Clientes!" << endl << endl;
			_sleep(1000);
			backUpProveedor.grabarCopiaDeSeguridad(proveedor);
			cout << "Proveedores!" << endl << endl << endl;
			_sleep(1000);
			cout << "Copia de seguridad realizada correctamente!" << endl;
			cout << "Volviendo al menu anterior..." << endl;
			_sleep(4000);
			continuar = true;
		}
		else
		{
			cout << "No se ha realizado ninguna copia de seguridad" << endl;
			cout << "Volviendo al menu anterior..." << endl;
			_sleep(3000);
			continuar = true;
		}
	}

}
