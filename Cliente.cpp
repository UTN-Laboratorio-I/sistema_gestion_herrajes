#include "Cliente.h"
#include "Archivo.h"
#include "TablaDto.h"
#include "vector"
#include "conio.h"

using namespace std;


int Cliente::getId() { return _idCliente; }
char* Cliente::getRazonSocial() { return _razonSocial; }
long long Cliente::getCuit() { return _cuit; }

void Cliente::setId(int id) { _idCliente = id; }
void Cliente::setCuit(long long cuit) { _cuit = cuit; }
void Cliente::setRazonSocial(const char* razonSocial) { strcpy_s(_razonSocial, razonSocial); }


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

	cout << endl <<response.getMessage();
	
	_sleep(3000);
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
			
			responseCliente = opcionModificar(responseCliente);

			cliente = responseCliente.getData();

			///

			archivoCliente.modificarRegistroObajaRegistro(cliente, posicion);

			cout << responseCliente.getMessage();
			_sleep(4000);
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
	bool modificar = false;

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

//////


Response <Cliente> Cliente::opcionModificar(Response <Cliente> &response)
{
	Cliente cliente;
	Archivo <Cliente> archivoCliente("clientes.dat");
	Response <Cliente> responseCliente;

	int opc;
	bool continuar = false;


	while (!continuar)
	{
		cout << endl << "Desea modificar el registro completo o algun campo determinado?" << endl << endl;

		cout << "1) Campo determinado - 2) Todo el registro - 0) Atras" << endl << endl;


		cin >> opc;


		switch (opc)
		{
		case 1:
			system("cls");
			response = modificarCampos(response);
			continuar = true;
			break;
		case 2:
			system("cls");
			cliente = cargarClienteAmodificar();
			response.setData(cliente);
			response.setSuccess("Cliente modificado correctamente, volviendo al menu anterior...", cliente);
			continuar = true;
			break;
		case 0:
			response.setFailure("No se ha modificado ningun campo, volviendo al menu anterior...");
			continuar = true;
			break;
		default:
			break;
		}

	}

	return response;

}

Response <Cliente> Cliente::modificarCampos(Response <Cliente> &response)
{
	Cliente cliente;
	cliente = response.getData();

	bool continuar = false;
	int campo;
	int opc = 99;
	int contador = 0;

	string nombre, apellido, direccion;
	char razonSocial[50], email [50];
	long long cuit;

	while (!continuar)
	{
		headerProductoAmodificar(response);

		cout << "Selecciones campo que desea modificar: " << endl;

		cout << "1) Nombre Cliente - 2) Apellido del Cliente - 3) CUIT - 4) Razon Social - 5) Domicilio 6) Email - 0) Atras" << endl;

		cin.ignore();
		cin >> campo;
		system("cls");

		switch (campo)
		{
		case 1:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese el nuevo nombre del Cliente: ";
			cin.ignore();
			getline(cin, nombre);
			cliente.setNombre(nombre);
			response.setData(cliente);
			contador++;
			response.setSuccess("Cliente modificado correctamente", cliente);
			break;
		case 2:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nuevo apellido del Cliente: ";
			cin.ignore();
			getline(cin, apellido);
			cliente.setApellido(apellido);
			response.setData(cliente);
			contador++;
			response.setSuccess("Cliente modificado correctamente", cliente);
			break;
		case 3:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nuevo CUIT del Cliente: ";
			cin.ignore();
			cin >> cuit;
			cliente.setCuit(cuit);
			response.setData(cliente);
			contador++;
			response.setSuccess("Cliente modificado correctamente", cliente);
			break;
		case 4:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nueva razon social del Cliente: ";
			cin.ignore();
			cin.getline(razonSocial, sizeof(razonSocial));
			cliente.setRazonSocial(razonSocial);
			response.setData(cliente);
			contador++;
			response.setSuccess("Cliente modificado correctamente", cliente);
			break;
		case 5:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nuevo domicilio del Cliente: ";
			cin.ignore();
			getline(cin, direccion);
			cliente.setDomicilio(direccion);
			response.setData(cliente);
			contador++;
			response.setSuccess("Cliente modificado correctamente", cliente);
			break;
		case 6:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nuevo email del Cliente: ";
			cin.ignore();
			cin.getline(email, sizeof(email));
			cliente.setEmail(email);
			response.setData(cliente);
			contador++;
			response.setSuccess("Cliente modificado correctamente", cliente);
			break;
		case 0:
			continuar = true;
			break;
		default:
			break;
		}

		system("cls");

		if (contador > 0)
		{

			headerProductoAmodificar(response);
			cout << "Desea modificar algun campo mas?" << endl;

			cout << "1) Si - 2) No, Guardar y salir" << endl;

			cin >> opc;

			if (opc == 2)
			{
				continuar = true;
			}

		}


		if (opc == 99 || campo == 0)
		{
			if (contador == 0)
			{
				headerProductoAmodificar(response);
				response.setFailure("No se ha modificado ningun campo, volviendo al menu anterior...");
			}
			continuar = true;
		}
	}

	return response;

}

void Cliente::headerProductoAmodificar(Response <Cliente> response)
{
	system("cls");
	cout << "----------------------------------------------" << endl << endl;
	cout << "------------ CLIENTE A MODFICAR ------------" << endl << endl;
	cout << "ID Cliente:\t\t\t   N# " << response.getData().getId() << endl;
	cout << "Nombre del Cliente: \t \t" << "1) " << response.getData().getNombre() << endl;
	cout << "Apellido del Cliente: \t\t" << "2) " << response.getData().getApellido() << endl;
	cout << "CUIT del Cliente: \t\t" << "3) " << response.getData().getCuit() << endl;
	cout << "Razon Social del Cliente: \t" << "4) " << response.getData().getRazonSocial() << endl;
	cout << "Domicilio del Cliente: \t\t" << "5) " << response.getData().getDomicilio() << endl;
	cout << "Email del Cliente: \t\t" << "6) " << response.getData().getEmail() << endl << endl;
	cout << "----------------------------------------------" << endl << endl;
}