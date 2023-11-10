#include "Proveedor.h"


Response <Proveedor> Proveedor::cargarProveedor()
{
	Response <Proveedor> response;
	Archivo <Proveedor> archivo("proveedores.dat");
	Proveedor proveedor;
	string razonSocial, cuit, direccion, email;

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
	cout << proveedor.getData().getRazonsocial() << " - " << proveedor.getData().getCuit() << endl << endl;
}

int Proveedor::getId(){return _idProveedor;}
void Proveedor::setId(int id){_idProveedor = id;}
 
Response <Proveedor> Proveedor::buscarProveedor()
{
	Archivo <Proveedor> archivoProv("proveedores.dat");
	Proveedor proveedor;
	Response <Proveedor> responseProveedor;
	Helper helper;

	int idProv;
	bool continuar = true;
	int opc;
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

			cout << "¿EL PROVEEDOR SELECCIONADO ES EL CORRECTO? (1) SI - 2) NO - 0) ATRAS)" << endl;
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
		else
		{
			if (opc == 0)
			{
				responseProveedor.setFailure("Volviendo al menu anterior...");
				continuar = false;
			}
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