#include "Cliente.h"
#include "Archivo.h"

using namespace std;

Response<Cliente> Cliente::cargarCliente()
{
	Archivo<Cliente> archivoCliente("clientes.dat");
	Response<Cliente> response;
	Cliente cliente;
	long long cuit;
	char razonSocial[50]; 
	long primerosDosDigitosCuit;
	long ultimoDigitoCuit;
	cliente.cargar();

	cout << "Ingrese primeros 2 digitos del cuit: xx-"<<cliente.getDNI()<<"-x : ";
	cin >> primerosDosDigitosCuit;
	cout << "Ingrese ultimo digito del cuit: " << primerosDosDigitosCuit<<cliente.getDNI()<<"-x : ";
	cin >> ultimoDigitoCuit;

	//Combinamos los digitos del cuit:
	long numeros_dni = static_cast<long>(log10(cliente.getDNI())) + 1;
	long long numero = (long long)primerosDosDigitosCuit * pow(10, numeros_dni + 1);
	long long resultado = numero + cliente._dni * 10 + ultimoDigitoCuit;


	cout << "Ingrese la razón social: ";
	cin.ignore();
	cin.getline(razonSocial, 50);

	cliente.setRazonSocial(razonSocial);
	cliente.setCuit(resultado);

	Response<Cliente> registro = archivoCliente.grabarRegistroArchivo(cliente);
	if (registro.getSuccess()) {
		response.setSuccess("Se creo el cliente correctamente", registro.getData());
	}
	else {
		response.setFailure("No se pudo crear el cliente");
	}
	return response;
}

void Cliente::MostarCliente()
{
	mostrar();

	cout << "ID CLIENTE: " << getIdCliente() << endl;
	cout << "CUIT: " << getCuit() << endl;
	cout << "RAZON SOCIAL: " << getRazonSocial() << endl;

}

int Cliente::getIdCliente() {return _idCliente; }
char* Cliente::getRazonSocial(){return _razonSocial;}
long long Cliente::getCuit(){return _cuit;}

void Cliente::setId(int id){_idCliente = id;}
void Cliente::setCuit(long long cuit){_cuit = cuit;}
void Cliente::setRazonSocial(const char* razonSocial){strcpy_s(_razonSocial, razonSocial);}

Cliente Cliente::listarYSeleccionarClienteExistente() {
	Archivo<Cliente> archivoCliente("clientes.dat");
	vector<Cliente> clientes = archivoCliente.listarRegistroArchivo();

	if(clientes.size() == 0) {
		cout << "No hay clientes cargados" << endl;
		return Cliente();
	};

	for(Cliente cliente : clientes) {
		cout << "ID: " << cliente.getIdCliente() << " - " << cliente.getRazonSocial() << endl;
	};

	int idCliente;
	cout << "Seleccione el cliente: ";
	cin >> idCliente;

	for (Cliente cliente : clientes) {
		if (cliente.getIdCliente() == idCliente) {
			return cliente;
		}
	};

}