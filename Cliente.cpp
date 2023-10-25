#include "Cliente.h"


void Cliente::cargarCliente()
{
	int cuit, idCliente;
	char razonSocial[50];

	cargar();

	cout << "INGRESE ID CLIENTE: ";
	cin >> idCliente;
	cout << endl;
	cout << "CUIT: ";
	cin >> cuit;
	cout << endl;
	cout << "RAZON SOCIAL: ";
	cin >> razonSocial;
	cout << endl;

	setIdCliente(idCliente);
	setCuit(cuit);
	setRazonSocial(razonSocial);

}

void Cliente::MostarCliente()
{
	Archivo <Cliente> reg("clientes.dat");
	vector <Cliente> regCliente;
	regCliente = reg.listarRegistroArchivo();

	/*mostrar();

	cout << "ID CLIENTE: " << getIdCliente() << endl;
	cout << "CUIT: " << getCuit() << endl;
	cout << "RAZON SOCIAL: " << getRazonSocial() << endl;*/

	for (Cliente c : regCliente) {
		c.mostrar();
		cout << "ID CLIENTE: " << getIdCliente() << endl;
		cout << "CUIT: " << getCuit() << endl;
		cout << "RAZON SOCIAL: " << getRazonSocial() << endl;
	}
}

int Cliente::getIdCliente() {return _idCliente; }
char* Cliente::getRazonSocial(){return _razonSocial;}
int Cliente::getCuit(){return _cuit;}

void Cliente::setIdCliente(int id){_idCliente = id;}
void Cliente::setCuit(int cuit){cuit = cuit;}
void Cliente::setRazonSocial(const char* razonSocial){strcpy_s(_razonSocial, razonSocial);}

Response<Cliente> Cliente::crearNuevoCliente()
{
    Cliente nuevoCliente;
    Response<Cliente> response;
    const char* nombreArchivo = "clientes.dat";
    Archivo<Cliente> archivo(nombreArchivo);

	nuevoCliente.cargarCliente();
    
    bool registro = archivo.grabarRegistroArchivo(nuevoCliente);

    if (registro) {
        response.setSuccess("cliente cargado con éxito.", nuevoCliente);
    }
    else {
        response.setFailure("Error al cargar nuevo cliente.");
    }

    return response;
}
