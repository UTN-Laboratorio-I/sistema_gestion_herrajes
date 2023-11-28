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
	int opc =0;
	while (moduloConfigActivo()) {
		config_UI.ver_MenuConfig();
		opc = _sistema->getPantalla();
		switch (opc) {
		case 1:
			administrarConfiguracionFecha();
			break;
		case 2:
			administrarConfiguracionMargenUtilidad();
			break;
		case 3:
			administrarCarpetaDeBackups();
			break;
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

void AdminConfig::administrarConfiguracionFecha() {
	InterfazUI config_UI(_sistema);
	bool modificar;
	int formatoFecha = 0;

		cout << "Formato de fecha actual: " << _sistema->getFormatoFecha() << endl;

		cout << "Desea modificar el formato de fecha? (1: Si - 0: No): ";
		cin >> modificar;

		if (modificar) {
			config_UI.ver_seleccionFormatoFecha();
		}
}

void AdminConfig::administrarConfiguracionMargenUtilidad() {
	InterfazUI config_UI(_sistema);
	bool modificar;
	float margenUtilidad = 0.0;

		cout << "Margen de utilidad actual: " << _sistema->getMargenUtilidad() << "%" << endl;

		cout << "Desea modificar el margen de utilidad? (1: Si - 0: No): ";
		cin >> modificar;

		if (modificar) {
		cout << "Ingrese margen de utilidad (Numero entero %): ";
		cin >> margenUtilidad;
		_sistema->setMargenUtilidad(margenUtilidad);
		}
}

void AdminConfig::administrarCarpetaDeBackups()
{
	InterfazUI config_UI(_sistema);
	bool modificar;
	string carpetaBackUp;

	cout << "Carpeta de backups actual: " << _sistema->getCarpetaBackUp() << endl;

	cout << "Desea modificar la carpeta de backups? (1: Si - 0: No): ";
	cin >> modificar;

	if (modificar) {
		config_UI.ver_setearCarpetaBackUp();
	}
}

void AdminConfig::realizarCopiaDeSeguridad()
{
	const char* carpetaBackUp = _sistema->getCarpetaBackUp();
	Backup <Producto> backUpProducto("productos.dat","productos.bak", carpetaBackUp);
	Backup <Cliente> backUpcliente("clientes.dat","clientes.bak", carpetaBackUp);
	Backup <Proveedor> backUpProveedor("proveedores.dat","proveedores.bak", carpetaBackUp);

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
			cout << endl << "Iniciando copia de seguridad..."<< endl << endl;
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
