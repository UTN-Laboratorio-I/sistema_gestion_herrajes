#include "Cliente.h"
#include "Archivo.h"
#include "TablaDto.h"
#include "vector"
#include "conio.h"

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

void Cliente::mostarCliente()
{
	vector <Cliente> vectorClientes;
	Archivo <Cliente> archivoCliente("clientes.dat");
	vectorClientes = archivoCliente.listarRegistroArchivo();

	TablaDto <Cliente> tablaClientes("clientes", vectorClientes, true, false);
	tablaClientes.generarTablaClientes(vectorClientes);

	cout << endl;

	cout << "Seleccione una tecla para volver al menu anterior..." << endl;
	getch();

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

Response<Cliente> Cliente::modificarOdarBajaCliente(bool modificar)
{
	vector <Cliente> vectorClientes;
	Archivo <Cliente> archivoCliente("clientes.dat");
	vectorClientes = archivoCliente.listarRegistroArchivo();
	
	TablaDto <Cliente> tablaClientes("clientes", vectorClientes, true, false);
	tablaClientes.generarTablaClientes(vectorClientes);
	
	int id = vectorClientes.back().getId();

	Response <Cliente> responseCliente;

	Helper helper;

	bool continuar = false;
	int idCliente;
	int opc;
	Cliente cliente;

	while (!continuar)

	{
		//En caso de que modificar sea false
		if (!modificar)
		{
			cliente.darBajaCliente(id);
			continuar = false;
			break;
		}

		cout << endl <<"Ingrese ID de cliente que desea modificar: ";
		cin >> idCliente;

		if (idCliente < 1 || idCliente > id)
		{
			cout << endl << "El numero de ID seleccionado no existe, seleccione un ID valido..." << endl;
			_sleep(2000);
			continue;
		}
		
		int posicion = archivoCliente.buscarPosRegistro(cliente, idCliente);

		responseCliente = archivoCliente.listarUnRegistro(posicion, cliente);

		cout << endl;

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
			archivoCliente.modificarRegistroObajaRegistro(cliente, posicion);

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
	cout << "El cliente seleccionado es: " << responseCliente.getData().getNombre() << " " << responseCliente.getData().getApellido() << " - CUIT: " << responseCliente.getData().getCuit() << endl;
}

Cliente Cliente::cargarClienteAmodificar()
{
	Cliente cliente;
	long long cuit;
	char razonSocial[50];
	long primerosDosDigitosCuit;
	long ultimoDigitoCuit;
	Helper helper;


	cout << endl << endl <<"------- CARGA DE NUEVOS DATOS DE CLIENTE -------" << endl << endl;

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

Cliente Cliente::darBajaCliente(int id)
{
	
	vector <Cliente> vectorClientes;
	Archivo <Cliente> archivoCliente("clientes.dat");
	vectorClientes = archivoCliente.listarRegistroArchivo();

	Response <Cliente> responseCliente;

	Helper helper;

	bool continuar = false;
	int idCliente;
	int opc;
	Cliente cliente;
	
	while (!continuar)
	{

		cout << endl << "Ingrese ID de cliente que desea eliminar: ";
		cin >> idCliente;

		if (idCliente < 1 || idCliente > id)
		{
			cout << endl << "El numero de ID seleccionado no existe, seleccione un ID valido..." << endl;
			_sleep(2000);
			continue;
		}

		int posicion = archivoCliente.buscarPosRegistro(cliente, idCliente);

		responseCliente = archivoCliente.listarUnRegistro(posicion, cliente);

		cout << endl;

		verClienteAmodificar(responseCliente);

		cout << endl << "Es el que desea eliminar?" << endl;

		cout << "1) Si - 2) No - 0) Atras" << endl;
		cin >> opc;

		if (opc != 1)
		{
			responseCliente.setFailure("No se a eliminado ningun cliente, volviendo al menu anterior...");
			continuar = true;
			break;
		}

		cout << "Esta seguro que desea eliminar el cliente: " << responseCliente.getData().getNombre() << " " << responseCliente.getData().getApellido() << " - CUIT: " << responseCliente.getData().getCuit() << endl;;
		cout << "1) Si - 2) No - 0) Atras" << endl;
		
		cin >> opc;

		if (opc == 1)
		{
			cliente = responseCliente.getData();
			cliente.setEstado(false);

			archivoCliente.modificarRegistroObajaRegistro(cliente, posicion, true);

			responseCliente.setSuccess("Cliente eliminado correctamente", cliente);
			continuar = true;
			break;
		}
		else if (opc != 1)
		{
			responseCliente.setFailure("No se a eliminado ningun cliente, volviendo al menu anterior...");
			continuar = true;
			break;
		}

	}
		cout << endl << responseCliente.getMessage();

		_sleep(4000);

		return cliente;
	
}