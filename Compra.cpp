#include "Compra.h"
#include "Archivo.h"
#include "DetalleDto.h"
#include "StockDto.h"
#include "TransaccionDto.h"
#include "Fecha.h"
#include "cstring"
#include "Caja.h"
#include "TablaDto.h"


//CONSTRUCTOR

Compra::Compra()
{
	_idProveedor = 0;
	_tipo = 'c';
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


void Compra::carritoDeCompra(bool compraRealizada, Producto &producto){
	vector<DetalleDto> carrito;
	for (Detalle detalle : _detalle) {
		//Obtenemos el id del registro y cada detalle de la lista:
		int id = _id;
		DetalleDto detalleDto(detalle, id, _tipo);
		carrito.push_back(detalleDto);
	}

	if (!_detalle.empty()) {
		if (compraRealizada) {
			cout << "Compra realizada con exito!" << endl;
		}
		else {
			cout << "Carrito de compra: " << endl;
		}
		TablaDto<DetalleDto> tabla("carrito compras", carrito, false);
		_listaTemporalCarrito.push_back(producto.getNombreProducto());
		tabla.generarCarritoProductosCompras(carrito, producto, _listaTemporalCarrito);

	}

	if (compraRealizada)
	cout << endl << endl;
}

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

	bool elijeProductoExistente;

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
			elijeProductoExistente = productoExistente();
			responseProveedor = proveedor.buscarProveedor();
			if (!responseProveedor.getSuccess()) { break; }
			subCompras_UI.headerDinamico();
			//proveedor = proveedorExistente.getData();
			registrarNuevaCompra(sistema, subCompras_UI, responseProveedor, elijeProductoExistente);
			break;
		case 2:
			subCompras_UI.headerDinamico();
			elijeProductoExistente = productoExistente();
			responseProveedor = proveedor.cargarProveedor();
			//proveedor = responseNuevoProveedor.getData();
			//responseNuevoProveedor.setData(proveedor);
			registrarNuevaCompra(sistema, subCompras_UI, responseProveedor, elijeProductoExistente);
			//proveedor = responseNuevoProveedor.getData();
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

Response <TransaccionDto> Compra::registrarNuevaCompra(Sistema *sistema, InterfazUI interfaz, Response <Proveedor> prov, bool productoExistente)
{
	Archivo<TransaccionDto> archivoTransaccion("transacciones.dat");
	Archivo<DetalleDto> archivoDetalle("detalles.dat");
	Archivo <Producto> archivoProducto("productos.dat");
	
	vector <Producto> vectorProducto;

	vectorProducto = archivoProducto.listarRegistroArchivo();

	TablaDto <Producto> tablaProductos("productos", vectorProducto, true, false);
	


	Response<TransaccionDto> response;
	Response <Producto> responseProducto;

	Producto productoAcargar;
	Helper helper;
	Proveedor proveedor;
	Fecha fecha;
	vector <DetalleDto>detalle;
	Stock stock;
	Caja caja;
	Compra compra;

	float margenUtilidad = sistema->getMargenUtilidad() * 1.0;



	bool continuarCompra = true;
	bool cancelarCompra = false;
	int opc;
	int contador = 1;
	int cantidadDetalleProducto=0;


	while (continuarCompra)
	{
		interfaz.headerDinamico();

		interfaz.ver_CarritoCompras(detalle);

		if (contador > 1)
		{
			compra.carritoDeCompra(false,productoAcargar);
		}
		
		proveedor.ver_ProveedorEncontrado(prov);

		cout << endl << "----------- COMPRA DE PRODUCTOS -----------" << endl << endl;

		cout << "ITEM N: " << contador << endl << endl;
		/*
		if (productoExistente == false)
		{
			productoAcargar = productoAcargar.cargarProductos();
			compra.agregarADetalleCompra(productoAcargar, productoAcargar.getCantidad());
		}
		else
		{	//Compra de producto existente
			productoAcargar = productoAcargar.listarYSeleccionarProductoCompra();
			cantidadDetalleProducto = seleccionarCantidad();
			productoAcargar = ingresarPrecioCosto(productoAcargar);
			compra.agregarADetalleCompra(productoAcargar, cantidadDetalleProducto);
		}
		*/
		productoAcargar = productoAcargar.listarYSeleccionarProductoCompra();

		switch (productoAcargar.getId()) {
		case 0:
			productoAcargar = productoAcargar.cargarProductos();
			compra.agregarADetalleCompra(productoAcargar, productoAcargar.getCantidad());
			break;
		case -1:
			response.setFailure("Compra cancelada");
			return response;
			break;
			default:
			cantidadDetalleProducto = seleccionarCantidad();
			productoAcargar = ingresarPrecioCosto(productoAcargar);
			compra.agregarADetalleCompra(productoAcargar, cantidadDetalleProducto);
		}

		cout << endl << "Desea continuar la compra ?" << endl <<"1) SI // 2): NO" << endl << endl;

		
		cin >> opc;

		helper.limpiarConsola();
		interfaz.headerDinamico();
		
		
		contador++;

		if (opc != 1)
		{
			compra.carritoDeCompra(true, productoAcargar);
			cout << endl << "Compra finalizada!" << endl;
			_sleep(4000);
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


	//Guardamos el usuario que registró la venta:
	string user = sistema->getUsuarioLogged();
	compra.setUsuario(user.c_str());

	//Guardamos la fecha de la venta
	compra.setFecha(fecha.now());

	//Guardamos el tamaño total de la venta en cuanto a cantidad:
	compra.setCantidad(cantidadProductos);

	//Seteamos tipo de transaccion (Compra, 'C')
	compra.setTipoTransaccion(_tipo);

	//Setamos ID proveedor
	compra.setIdProveedor(prov.getData().getId());

	TransaccionDto transaccion(compra._monto, compra._fecha, compra._tipo, compra._cantidadProductos, compra._usuario);
	Response <TransaccionDto> registro = archivoTransaccion.grabarRegistroArchivo(transaccion);

	bool registroCorrecto = true;
	for (Detalle detalle : compra._detalle) {
		//Obtenemos el id del registro y cada detalle de la lista:
		int id = registro.getData().getId();

		if (!productoExistente)
		{
			Archivo <Producto> archivoProducto("productos.dat");
			responseProducto = archivoProducto.grabarRegistroArchivo(detalle.getProducto());

			detalle.setIdProducto(responseProducto.getData().getId());
		}

		Producto produ = detalle.getProducto();

		//Que mierda hace esto:
		if (productoExistente)
		{	
			Response <Producto> existente = archivoProducto.buscarUnRegistro(produ.getId());

			if (existente.getData().getId() == produ.getId())
			{
				existente.setData(produ);
				Producto productoAgrabar = existente.getData();

				archivoProducto.modificarRegistroObajaRegistro(productoAgrabar, produ.getId() - 1);
			}
			
		}

		DetalleDto detalleDto(detalle, id, _tipo);

		Response<DetalleDto> registroDetalle = archivoDetalle.grabarRegistroArchivo(detalleDto);

		//Modificamos el stock del producto:
		stock.gestionarStock(detalle.getCantidad(), detalle.getProducto().getId(), _tipo);


		//Si algún registro falla, devolvemos false:
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

	vector <TransaccionDto> vecTransaccion;

	Response <TransaccionDto> responseTransaccion;

	Response <Compra> responseCompra;

	vecTransaccion = archivoTransacciones.listarRegistroArchivo();
	
	for (TransaccionDto a : vecTransaccion)
	{	
		if (a.getTipoTransaccion() == 'c')
		{
			cout << a.getId() << endl;
			cout << a.getMonto() << endl;
			cout << a.getUsuario() << endl;
		}
	}

	system("pause");
}

void Compra::mostrarProductosComprados()
{
	Stock stock;
	vector <Stock> vectorStock;
	Archivo <Stock> archivoStock("stock.dat");

	vectorStock = archivoStock.listarRegistroArchivo();
	
	for (Stock s : vectorStock)
	{
		s.mostrarStock();
	}

	system("pause");
}

bool Compra::productoExistente()
{
	int opc;

	cout << "Desea comprar un producto existente?" <<" 1) SI // 2): NO" << endl << endl;

	cin >> opc;

	if (opc == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Compra::seleccionarCantidad()
{
	int cant;

	cout << "Seleccione cantidad que desea comprar: ";

	cin >> cant;

	return cant;
}

Producto Compra::ingresarPrecioCosto(Producto &producto)
{
	float precioCosto = producto.getPrecioCosto();
	
	if (precioCosto == 0)
	{
		cout << "Ingresar precio de costo: ";

		cin >> precioCosto;
	}
	
	producto.setPrecioCosto(precioCosto);
	
	return producto;
}