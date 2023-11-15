#include "Cliente.h"
#include "Archivo.h"
#include "TablaDto.h"
#include "vector"

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
	Helper helper;


	cout << "------- CARGA DE CLIENTE -------" << endl << endl;

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

	cout << "ID CLIENTE: " << getId() << endl;
	cout << "CUIT: " << getCuit() << endl;
	cout << "RAZON SOCIAL: " << getRazonSocial() << endl;

}

int Cliente::getId() {return _idCliente; }
char* Cliente::getRazonSocial(){return _razonSocial;}
long long Cliente::getCuit(){return _cuit;}

void Cliente::setId(int id){_idCliente = id;}
void Cliente::setCuit(long long cuit){_cuit = cuit;}
void Cliente::setRazonSocial(const char* razonSocial){strcpy_s(_razonSocial, razonSocial);}

Cliente Cliente::listarYSeleccionarClienteExistente() {
	Archivo<Cliente> archivoCliente("clientes.dat");
	vector<Cliente> clientes = archivoCliente.listarRegistroArchivo();
	TablaDto<Cliente> tabla("clientes", clientes, false);

	if(clientes.size() == 0) {
		cout << "No hay clientes cargados" << endl;
		return Cliente();
	};

	tabla.generarTablaClientes(clientes);

	int idCliente;
	cout << "Seleccione el cliente: ";
	cin >> idCliente;
	
	for (Cliente cliente : clientes) {
		if (cliente.getId() == idCliente) {
			return cliente;
		}
	};
}

Response<Cliente> Cliente::modificarCliente()
{
	vector <Cliente> vectorClientes;
	Archivo <Cliente> archivoCliente("clientes.dat");
	vectorClientes = archivoCliente.listarRegistroArchivo();
	
	TablaDto <Cliente> tablaClientes("clientes", vectorClientes, true, false);
	tablaClientes.generarTablaClientes(vectorClientes);


	Response <Cliente> responseCliente;

	Helper helper;

	bool continuar = false;
	int idCliente;
	int opc;
	Cliente cliente;

	while (!continuar)

	{
		cout << endl <<"Ingrese ID de cliente que desea modificar: ";
		cin >> idCliente;
		
		int posicion = archivoCliente.buscarPosRegistro(cliente, idCliente);

		responseCliente = archivoCliente.listarUnRegistro(posicion, cliente);


		verClienteAmodificar(responseCliente);

		cout << endl <<"Es el que desea modificar?" << endl;

		cout << "1) Si - 2) No - 0) Atras" << endl;
		cin >> opc;

		if (opc == 1)
		{
			helper.limpiarConsola();
			
			//tablaClientes.generarTablaClientes(vectorClientes);

			cout << endl;

			verClienteAmodificar(responseCliente);
			
			cliente = cliente.cargarClienteAmodificar();
			cout << endl;
			responseCliente.setSuccess("Cliente modificado correctamente!", cliente);
			archivoCliente.modificarRegistro(cliente, posicion);

			cout << responseCliente.getMessage();
			_sleep(2000);
			continuar = true;
		}
		else if (opc == 0)
		{
			responseCliente.setFailure("No se ha modificado ningun cliente, volviendo al menu anterior...");
			cout << responseCliente.getMessage();
			_sleep(2000);
			return responseCliente;
			break;
		}

	}
	



}

void Cliente::verClienteAmodificar(Response <Cliente> responseCliente)
{
	cout << "El cliente " << responseCliente.getData().getNombre() << " " << responseCliente.getData().getApellido() << " " << responseCliente.getData().getCuit() << endl << endl;
}

Cliente Cliente::cargarClienteAmodificar()
{
	Cliente cliente;
	long long cuit;
	char razonSocial[50];
	long primerosDosDigitosCuit;
	long ultimoDigitoCuit;
	Helper helper;


	cout << "------- CARGA DE NUEVOS DATOS DE CLIENTE -------" << endl << endl;

	cliente.cargar();

	cout << "Ingrese primeros 2 digitos del cuit: xx-" << cliente.getDNI() << "-x : ";
	cin >> primerosDosDigitosCuit;
	cout << "Ingrese ultimo digito del cuit: " << primerosDosDigitosCuit << cliente.getDNI() << "-x : ";
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

	return cliente;
}