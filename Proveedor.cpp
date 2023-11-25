#include "Proveedor.h"
#include "TablaDto.h"
#include "conio.h"


Response <Proveedor> Proveedor::cargarProveedor()
{
	Response <Proveedor> response;
	Archivo <Proveedor> archivo("proveedores.dat");
	Proveedor proveedor;
	string razonSocial, cuit, direccion, email, nombre, apellido;

	system("cls");

	cout << "------- CARGA DE PROVEEDOR -------" << endl << endl;
	
	cout << "Ingrese Nombre: " << endl;
	cin.ignore();
	getline(cin, nombre);

	cout << "Ingrese Apellido: " << endl;
	getline(cin, apellido);
	
	cout << "Ingrese numero de CUIT: " << endl;
	getline(cin, cuit);

	cout << "Ingrese razon social: " << endl;
	getline(cin, razonSocial);

	cout << "Ingrese direccion: " << endl;
	getline(cin, direccion);

	cout << "Ingrese email: " << endl;
	getline(cin, email);

	proveedor.setCuit(cuit);
	proveedor.setRazonSocial(razonSocial);
	proveedor.setDomicilio(direccion);
	proveedor.setEmail(email);
	proveedor.setFechaAlta();
	proveedor.setNombre(nombre);
	proveedor.setApellido(apellido);
	cout << endl;

	Response <Proveedor> registro = archivo.grabarRegistroArchivo(proveedor);

	if (registro.getSuccess())
	{
		response.setSuccess("Proveedor guardado correctamente", registro.getData());
		
	}
	else
	{
		response.setFailure("No se puedo guardar el proveedor");
	}

	cout << response.getMessage() << endl;
	cout << "----------------------" << endl << endl;

	_sleep(2000);

	return response;
}


void Proveedor::MostarProveedor()
{
	cout << "ID PROVEEDOR: " << getId() << endl;
	cout << "RAZON SOCIAL: " << getRazonsocial() << endl;
	cout << "CUIT: " << getCuit() << endl;
	cout << "DIRECCION: " << getDomicilio() << endl;
	cout << "EMAIL: " << getEmail() << endl;
	cout << "FECHA DE ALTA: " << getFechaAlta().toString() << endl;
}

void Proveedor::ver_ProveedorEncontrado(Response <Proveedor> proveedor)
{
	cout << "PROVEEDOR SELECCIONADO: " << endl;
	cout << proveedor.getData().getRazonsocial() << " - CUIT: " << proveedor.getData().getCuit() << endl << endl;
}

int Proveedor::getId(){return _idProveedor;}
void Proveedor::setId(int id){_idProveedor = id;}
 
Response <Proveedor> Proveedor::buscarProveedor()
{
	Archivo <Proveedor> archivoProv("proveedores.dat");
	Proveedor proveedor;
	Response <Proveedor> responseProveedor;
	Helper helper;

	vector <Proveedor> vectorProveedores;

	vectorProveedores = archivoProv.listarRegistroArchivo();
	TablaDto <Proveedor> tablaProveedores("reporte proveedores", vectorProveedores, true, false);
	tablaProveedores.generarReporteProveedores(vectorProveedores);


	int idProv;
	bool continuar = true;
	int opc = {};
	int posicion;


	while (continuar)
	{		
		cout << "INGRESE ID DE PROVEEDOR: " << endl;
		
		cin >> idProv;

		posicion = archivoProv.buscarPosRegistro(proveedor, idProv);

		responseProveedor = archivoProv.listarUnRegistro(posicion, proveedor);

		if (responseProveedor.getSuccess())
		{
			responseProveedor.getData().MostarProveedor();
			cout << endl;

			cout << endl << " EL PROVEEDOR SELECCIONADO ES EL CORRECTO? " << endl <<" 1) SI - 2) NO - 0) ATRAS)" << endl;
			cin >> opc;
		}
		else {
			cout << responseProveedor.getMessage() << endl << endl;
			_sleep(2000);
		}

		if (opc == 1)
		{
			continuar = false;
		}
		else if(opc == 0)
		{
			responseProveedor.setFailure("Volviendo al menu anterior...");
			continuar = false;
		}

	}

	//proveedor = arch.buscarProvID(idProv);
	if (!responseProveedor.getSuccess())
	{
		cout << endl << responseProveedor.getMessage() << endl << endl;
		_sleep(2000);
		return responseProveedor;
	}
	else {
		return responseProveedor;
	}

	
}

Proveedor Proveedor::cargarProveedorAmodificar()
{
	Archivo <Proveedor> archivo("proveedores.dat");
	Proveedor proveedor;
	string razonSocial, cuit, direccion, email, nombre, apellido;

	system("cls");

	cout << "------- CARGA DE NUEVOS DATOS DE PROVEEDOR -------" << endl << endl;


	cout << "Ingrese numero de CUIT: " << endl;
	cin.ignore();
	getline(cin, cuit);

	cout << "Ingrese razon social: " << endl;
	//cin.ignore();
	getline(cin, razonSocial);

	cout << "Ingrese direccion: " << endl;
	//cin.ignore();
	getline(cin, direccion);

	cout << "Ingrese email: " << endl;
	//cin.ignore();
	getline(cin, email);

	proveedor.setCuit(cuit);
	proveedor.setRazonSocial(razonSocial);
	proveedor.setDomicilio(direccion);
	proveedor.setEmail(email);
	proveedor.setFechaAlta();
	proveedor.setNombre(nombre);
	proveedor.setApellido(apellido);
	cout << endl;

	return proveedor;
}



Response<Proveedor> Proveedor::modificarOdarBajaProveedor(bool modificar)
{
	vector <Proveedor> vectorProveedor;
	Archivo <Proveedor> archivoProveedor("proveedores.dat");
	vectorProveedor = archivoProveedor.listarRegistroArchivo();

	TablaDto <Proveedor> tablaProveedores("reporte proveedores", vectorProveedor, true, false);
	tablaProveedores.generarReporteProveedores(vectorProveedor);

	int id = vectorProveedor.back().getId();

	Response <Proveedor> responseProveedor;

	Helper helper;

	bool continuar = false;
	int idProveedor;
	int opc;
	Proveedor proveedor;

	while (!continuar)

	{
		//En caso de que modificar sea false
		if (!modificar)
		{
			proveedor.darBajaProveedor(id);
			continuar = false;
			break;
		}

		cout << endl << "Ingrese ID de proveedor que desea modificar: ";
		cin >> idProveedor;

		if (idProveedor < 1 || idProveedor > id)
		{
			cout << endl << "El numero de ID seleccionado no existe, seleccione un ID valido..." << endl;
			_sleep(2000);
			continue;
		}

		int posicion = archivoProveedor.buscarPosRegistro(proveedor, idProveedor);

		responseProveedor = archivoProveedor.listarUnRegistro(posicion, proveedor);

		cout << endl;

		verProveedorAmodificar(responseProveedor);

		cout << endl << "Es el que desea modificar?" << endl;

		cout << "1) Si - 2) No - 0) Atras" << endl;
		cin >> opc;

		if (opc == 1)
		{
			helper.limpiarConsola();

			cout << endl << endl;

			helper.limpiarConsola();
			verProveedorAmodificar(responseProveedor);
			
			responseProveedor = opcionModificar(responseProveedor);

			proveedor = responseProveedor.getData();

			//responseProveedor.setSuccess("Proveedor modificado correctamente!", proveedor);
			archivoProveedor.modificarRegistroObajaRegistro(proveedor, posicion);

			cout << responseProveedor.getMessage();
			_sleep(4000);
			continuar = true;
		}
		else if (opc == 0)
		{
			responseProveedor.setFailure("No se ha modificado ningun proveedor, volviendo al menu anterior...");
			cout << responseProveedor.getMessage();
			_sleep(2000);
			return responseProveedor;
			break;
		}

	}

}

void Proveedor::verProveedorAmodificar(Response <Proveedor> responseProveedor)
{
	cout << "El proveedor seleccionado es: " << responseProveedor.getData().getNombre() << " " << responseProveedor.getData().getApellido() << " - CUIT: " << responseProveedor.getData().getCuit() << endl;
}




Proveedor Proveedor::darBajaProveedor(int id)
{
	vector <Proveedor> vectorProveedor;
	Archivo <Proveedor> archivoProveedor("proveedores.dat");
	vectorProveedor = archivoProveedor.listarRegistroArchivo();

	TablaDto <Proveedor> tablaProveedores("reporte proveedores", vectorProveedor, true, false);
	tablaProveedores.generarReporteProveedores(vectorProveedor);

	id = vectorProveedor.back().getId();

	Response <Proveedor> responseProveedor;

	Helper helper;

	bool continuar = false;
	int idProveedor;
	int opc;
	Proveedor proveedor;

	while (!continuar)
	{

		cout << endl << "Ingrese ID de proveedor que desea eliminar: ";
		cin >> idProveedor;

		if (idProveedor < 1 || idProveedor > id)
		{
			cout << endl << "El numero de ID seleccionado no existe, seleccione un ID valido..." << endl;
			_sleep(2000);
			continue;
		}

		int posicion = archivoProveedor.buscarPosRegistro(proveedor, idProveedor);

		responseProveedor = archivoProveedor.listarUnRegistro(posicion, proveedor);

		cout << endl;

		verProveedorAmodificar(responseProveedor);

		cout << endl << "Es el que desea eliminar?" << endl;

		cout << "1) Si - 2) No - 0) Atras" << endl;
		cin >> opc;

		if (opc != 1)
		{
			responseProveedor.setFailure("No se a eliminado ningun proveedor, volviendo al menu anterior...");
			continuar = true;
			break;
		}

		cout << "Esta seguro que desea eliminar el proveedor?: " << responseProveedor.getData().getNombre() << " " << responseProveedor.getData().getApellido() << " - CUIT: " << responseProveedor.getData().getCuit() << endl;
		cout << "1) Si - 2) No - 0) Atras" << endl;

		cin >> opc;

		if (opc == 1)
		{
			proveedor = responseProveedor.getData();
			proveedor.setEstado(false);

			archivoProveedor.modificarRegistroObajaRegistro(proveedor, posicion, true);

			responseProveedor.setSuccess("Proveedor eliminado correctamente", proveedor);
			continuar = true;
			break;
		}
		else if (opc != 1)
		{
			responseProveedor.setFailure("No se a eliminado ningun proveedor, volviendo al menu anterior...");
			continuar = true;
			break;
		}

	}
	cout << endl << responseProveedor.getMessage();

	_sleep(4000);

	return proveedor;
}

void Proveedor::mostarProveedor()
{
	vector <Proveedor> vectorProveedor;
	Archivo <Proveedor> archivoProveedor("proveedores.dat");
	vectorProveedor = archivoProveedor.listarRegistroArchivo();

	TablaDto <Proveedor> tablaProveedores("reporte proveedores", vectorProveedor, true, false);
	tablaProveedores.generarReporteProveedores(vectorProveedor);

	cout << endl;

	cout << "Seleccione una tecla para volver al menu anterior..." << endl;
	getch();

}

Response <Proveedor> Proveedor::opcionModificar(Response <Proveedor> &response)
{
	Proveedor proveedor;

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
			proveedor = cargarProveedorAmodificar();
			response.setData(proveedor);
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

Response <Proveedor> Proveedor::modificarCampos(Response <Proveedor> &response)
{
	Proveedor proveedor;
	proveedor = response.getData();

	bool continuar = false;
	int campo;
	int opc = 99;
	int contador = 0;

	string nombre, apellido, cuit, razonSocial, direccion;


	while (!continuar)
	{
		headerProductoAmodificar(response);

		cout << "Selecciones campo que desea modificar: " << endl;

		cout << "1) Nombre Proveedor - 2) Apellido del Proveedor - 3) CUIT - 4) Razon Social - 5) Domicilio - 0) Atras" << endl;

		cin.ignore();
		cin >> campo;
		system("cls");

		switch (campo)
		{
		case 1:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese el nuevo nombre del Proveedor: ";
			cin.ignore();
			getline(cin, nombre);
			proveedor.setNombre(nombre);
			response.setData(proveedor);
			contador++;
			response.setSuccess("Proveedor modificado correctamente", proveedor);
			break;
		case 2:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nuevo apellido del Proveedor: ";
			cin.ignore();
			getline(cin, apellido);
			proveedor.setApellido(apellido);
			response.setData(proveedor);
			contador++;
			response.setSuccess("Proveedor modificado correctamente", proveedor);
			break;
		case 3:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nuevo CUIT del Proveedor: ";
			cin.ignore();
			getline(cin, cuit);
			proveedor.setCuit(cuit);
			response.setData(proveedor);
			contador++;
			response.setSuccess("Proveedor modificado correctamente", proveedor);
			break;
		case 4:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nueva razon social del Proveedor: ";
			cin.ignore();
			getline(cin, razonSocial);
			proveedor.setRazonSocial(razonSocial);
			response.setData(proveedor);
			contador++;
			response.setSuccess("Proveedor modificado correctamente", proveedor);
			break;
		case 5:
			headerProductoAmodificar(response);
			cout << endl << "Ingrese nuevo domicilio del Proveedor: ";
			cin.ignore();
			getline(cin, direccion);
			proveedor.setDomicilio(direccion);
			response.setData(proveedor);
			contador++;
			response.setSuccess("Proveedor modificado correctamente", proveedor);
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

void Proveedor::headerProductoAmodificar(Response <Proveedor> response)
{
	system("cls");
	cout << "----------------------------------------------" << endl << endl;
	cout << "------------ PROVEEDOR A MODFICAR ------------" << endl << endl;
	cout << "ID Proveedor:\t\t\t   N# " << response.getData().getId() << endl;
	cout << "Nombre del Proveedor: \t \t" << "1) " << response.getData().getNombre()<< endl;
	cout << "Apellido del Proveedor: \t" << "2) " << response.getData().getApellido()<< endl;
	cout << "CUIT del Proveedor: \t\t" << "3) " << response.getData().getCuit()<< endl;
	cout << "Razon Social del Proveedor: \t" << "4) " << response.getData().getRazonsocial() << endl;
	cout << "Domicilio del Proveedor: \t" << "5) " << response.getData().getDomicilio() << endl << endl;
	cout << "----------------------------------------------" << endl << endl;
}