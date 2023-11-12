#include "Compra.h"
#include "Archivo.h"
#include "DetalleDto.h"
#include "StockDto.h"
#include "TransaccionDto.h"
#include "Fecha.h"
#include "cstring"
#include "Caja.h"


//CONSTRUCTOR

Compra::Compra()
{
	int _idProveedor = 0;
	char _tipo = 'c';
};



//SETTERS---------

void Compra::setId(int id) { _id = id; }
void Compra::setIdProveedor(int idProv) { _idProveedor = idProv; }

void Compra::setTipoTransaccion(char tipoTransaccion) { _tipo = tipoTransaccion; }

//GETTERS---------

int Compra::getId() { return _id; }
int Compra::getIdProveedor() { return _idProveedor; }
char Compra::getTipoTransaccion() { return _tipo; }

//DESARROLLO DE METODOS------------

void Compra::agregarADetalleCompra(Producto producto, int cantidad) {
	Detalle detalle(producto, cantidad);
	_detalle.push_back(detalle);
}


bool Compra::realizarCompra(Sistema* sistema)
{
	Archivo <Producto> archivoProd("productos.dat");
	Archivo <Compra> archivoComp("compras.dat");
	
	Response <Producto> responseProducto;
	Response <Proveedor> responseProveedor;
	Response <TransaccionDto> responseCompra;
	
	Producto producto;
	Compra compra;
	
	Proveedor proveedor;
	Helper header;
	Fecha fecha;
	InterfazUI subCompras_UI(sistema);


	bool continuar = true;

	while (continuar)
	{
		subCompras_UI.headerDinamico();
		subCompras_UI.ver_SubMenuCrearCompraProducto();
		int opc = sistema->getPantalla();
		switch (opc)
		{
		case 1:
			subCompras_UI.headerDinamico();
			responseProveedor = proveedor.buscarProveedor();
			if (!responseProveedor.getSuccess()) { break; }
			header.limpiarConsola();
			subCompras_UI.headerDinamico();
			//proveedor = proveedorExistente.getData();
			registrarNuevaCompra(compra, sistema, subCompras_UI, responseProveedor);
			break;
		case 2:
			subCompras_UI.headerDinamico();
			responseProveedor = proveedor.cargarProveedor();
			//proveedor = responseNuevoProveedor.getData();
			//responseNuevoProveedor.setData(proveedor);
			registrarNuevaCompra(compra, sistema, subCompras_UI, responseProveedor);
			//proveedor = responseNuevoProveedor.getData();
			break;
		case 3:
			compra.mostrarCompras();
			break;
		case 0:
			sistema->setModuloPantalla("Compras", 0);
			continuar = false;
			break;
		default:
			break;
		}
	}
	sistema->limpiarSubModulo();



	return true;
}

Response <TransaccionDto> Compra::registrarNuevaCompra(Compra compra, Sistema *sistema, InterfazUI interfaz, Response <Proveedor> prov)
{
	Archivo<TransaccionDto> archivoTransaccion("transacciones.dat");
	Archivo<DetalleDto> archivoDetalle("detalles.dat");
	
	vector <Producto> producto;

	Response<TransaccionDto> response;

	Producto productoAcargar;
	Helper helper;
	Proveedor proveedor;
	Fecha fecha;
	Detalle detalle;
	Stock stock;
	Caja caja;



	bool continuarCompra = true;
	int opc;
	int contador = 1;


	while (continuarCompra)
	{
		proveedor.ver_ProveedorEncontrado(prov);

		cout << "----------- COMPRA DE PRODUCTOS -----------" << endl << endl;

		cout << "ITEM N: " << contador << endl;
		
		productoAcargar.cargarProductos();

		this->agregarADetalleCompra(productoAcargar, productoAcargar.getCantidad());

		cout << endl << "Desea continuar la compra ?" << endl <<"1) SI // 2): NO" << endl << endl;

		cin >> opc;

		helper.limpiarConsola();
		interfaz.headerDinamico();
		
		
		contador++;

		if (opc != 1)
		{
			cout << "Compra finalizada!" << endl;
			_sleep(2000);
			continuarCompra = false;
		}

	}

	float acumuladorTotal = 0;
	int cantidadProductos = 0;
	for (Detalle detalle : compra._detalle) {
		Producto prod = detalle.getProducto();
		acumuladorTotal += detalle.getCantidad() * prod.getPrecioCosto();
		cantidadProductos += detalle.getCantidad();
	}
	compra.setMonto(acumuladorTotal);


	//Guardamos el usuario que registr� la venta:
	string user = sistema->getUsuarioLogged();
	compra.setUsuario(user.c_str());

	//Guardamos la fecha de la venta
	compra.setFecha(fecha.now());

	//Guardamos el tama�o total de la venta en cuanto a cantidad:
	compra.setCantidad(cantidadProductos);

	//Seteamos tipo de transaccion (Compra, 'C')
	compra.setTipoTransaccion(_tipo);

	TransaccionDto transaccion(_monto, _fecha, _tipo, _cantidadProductos, _usuario);
	Response <TransaccionDto> registro = archivoTransaccion.grabarRegistroArchivo(transaccion);

	bool registroCorrecto = true;
	for (Detalle detalle : compra._detalle) {
		//Obtenemos el id del registro y cada detalle de la lista:
		int id = registro.getData().getId();
		DetalleDto detalleDto(detalle, id);

		Response<DetalleDto> registroDetalle = archivoDetalle.grabarRegistroArchivo(detalleDto);

		//Modificamos el stock del producto:
		//stock.gestionarStock(detalle.getProducto().getId(), detalle.getCantidad(), _tipo);


		//Si alg�n registro falla, devolvemos false:
		if (registroDetalle.getSuccess() == false) {
			registroCorrecto = false;
		}
	}

	//Si se registraron correctamente tanto detalles como transaccion, se avanza OK:
	if (registro.getSuccess() && registroCorrecto) {
		//caja.gestionarCaja(_monto, _tipo);
		response.setSuccess("Se registro la compra correctamente", registro.getData());
	}
	else {
		response.setFailure("No se pudo registrar la compra");
	}
	
	cout << response.getMessage();
	_sleep(3000);
	cout << endl;

	return response;


}



void Compra::mostrarCompras()
{
	Archivo <TransaccionDto> archivoTransacciones("transacciones.dat");
	Archivo <Detalle> arhivoDetalle("detalle.dat");

	vector <Detalle> vecDetalle;
	vector <TransaccionDto> vecTransaccion;

	Response <Transaccion> responseTransaccion;

	Response <Compra> responseCompra;
	Compra compra;
	Detalle detalle;
	TransaccionDto transaccion;

	vecTransaccion = archivoTransacciones.listarRegistroArchivo();


	for (TransaccionDto t : vecTransaccion)
	{	
		if (transaccion.getTipoTransaccion() == 'c')
		{
			cout << transaccion.getId() << endl;
			cout << transaccion.getMonto() << endl;
			cout << transaccion.getUsuario() << endl;
		}
	}

	system("pause");
}