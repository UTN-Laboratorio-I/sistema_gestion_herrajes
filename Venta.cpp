#include <iostream>
#include <vector>
#include "Venta.h"
#include "InterfazUI.h"
#include "Cliente.h"
#include "Caja.h"
#include "DetalleDto.h"
#include "TablaDto.h"

using namespace std;
Venta::Venta() {
	_clienteId = 0;
	_tipo = 'v';
};

void Venta::setId(int id) {
	_id = id;
}
int Venta::getId() {
	return _id;
}
void Venta::setClienteId(int clienteId) {
	_clienteId = clienteId;
}
int Venta::getClienteId() {
	return _clienteId;
}

void Venta::setTipoTransaccion(char tipoTransaccion) { _tipoTransaccion = tipoTransaccion; }
char Venta::getTipoTransaccion() { return _tipoTransaccion; }

void Venta::agregarADetalleVenta(Producto producto, int cantidad) {
	Detalle detalle(producto, cantidad);
	_detalle.push_back(detalle);
}

void Venta::agregarProducto(Producto producto) {
	int cant;
	cout << "¿Cuantas unidades de " << producto.getNombreProducto() << "? ";
	cin >> cant;

	this->agregarADetalleVenta(producto, cant);
}

void Venta::carritoDeVenta(bool ventaRealizada=false) {
	vector<DetalleDto> carrito;
	for (Detalle detalle : _detalle) {
		//Obtenemos el id del registro y cada detalle de la lista:
		int id = _id;
		DetalleDto detalleDto(detalle, id, _tipo);
		carrito.push_back(detalleDto);
	}

	if (!_detalle.empty()) {
		if (ventaRealizada) {
			cout << "Venta realizada con exito!" << endl;
		}
		else {
			cout << "Carrito de venta: " << endl;
		}
	TablaDto<DetalleDto> tabla("carrito", carrito, false);

	tabla.generarCarritoProductos(carrito);

	}

	if (ventaRealizada)
		system("pause");
	cout << endl << endl;
}

Response<TransaccionDto> Venta::crearNuevaVenta(Sistema* sistema) {
	InterfazUI ventas_UI(sistema); //Utilizo ésta instancia para utilizar limpiarConsola y
	//headerDinamico, y así evitar que la consola se ensucie entre pantalla y pantalla.
	Archivo<TransaccionDto> archivoTransaccion("transacciones.dat");
	Archivo<DetalleDto> archivoDetalle("detalles.dat");
	//Archivo <Producto> archivoProducto("productos.dat");
	Response<TransaccionDto> response;
	vector<DetalleDto> detalleVenta;
	Venta venta;
	Fecha fecha;
	Stock stock;
	Caja caja;

	float margenUtilidad = sistema->getMargenUtilidad() * 1.0;
	bool finalizarVenta = false;

	ventas_UI.ver_CarritoVentas(detalleVenta);
	sistema->setSubModulo("Nueva venta");
	while (!finalizarVenta) {
		Producto producto;
		char opc;
		
		ventas_UI.headerDinamico();
		venta.carritoDeVenta();
		//Obtener listado de productos disponibles para venta:
		producto = producto.listarYSeleccionarProductoVenta(margenUtilidad);
		
		if (producto.getNombreProducto() != "") { //En caso de que no retorne un producto vacío, se procede a agregarlo al carrito:

			//Seleccionar cantidad y añadir al carrito:
			venta.agregarProducto(producto);

			//Consultar si desea finalizar la venta:
			cout << "Desea finalizar la venta? (s/n): ";
			cin >> opc;
			if (opc == 's' || opc == 'S') {
				finalizarVenta = !finalizarVenta;
				sistema->setSubModulo("VENTA FINALIZADA");
				ventas_UI.headerDinamico();
			}
		sistema->limpiarError();
		}
		else { //caso contrario, se muestra el error correspondiente:
			sistema->setError("Seleccione un producto valido");
		}
	}
	//Obtenemos el total de la venta y lo guardamos en la transacción:
	float acumuladorTotal = 0;
	int cantidadProductos = 0;
	for(Detalle detalle : venta._detalle){
		Producto prod = detalle.getProducto();
		float precioVenta = prod.getPrecioCosto() * margenUtilidad;
		acumuladorTotal += detalle.getCantidad() * precioVenta; //Modificar por precio venta!!!
		cantidadProductos += detalle.getCantidad();
	}
	venta.setMonto(acumuladorTotal);

	//Guardamos el usuario que registró la venta:
	string user = sistema->getUsuarioLogged();
	venta.setUsuario(user.c_str());

	//Guardamos la fecha de la venta:
	venta.setFecha(fecha.now());

	//Guardamos el tamaño total de la venta en cuanto a cantidad:
	venta.setCantidad(cantidadProductos);

	//Seteamos tipo de transaccion (Venta)
	venta.setTipoTransaccion(_tipo);

	//Guardamos la venta en el archivo:
	TransaccionDto transaccion(venta._monto, venta._fecha, venta._tipo, venta._cantidadProductos, venta._usuario);
	Response<TransaccionDto> registro = archivoTransaccion.grabarRegistroArchivo(transaccion);

	bool registroCorrecto = true;
	for (Detalle detalle : venta._detalle) {
		//Obtenemos el id del registro y cada detalle de la lista:
		int id = registro.getData().getId();
		DetalleDto detalleDto(detalle, id, _tipo);

		Response<DetalleDto> registroDetalle = archivoDetalle.grabarRegistroArchivo(detalleDto);

		//Modificamos el stock del producto:
		stock.gestionarStock(detalle.getCantidad(), detalle.getProducto().getId(), _tipo);
		/*Producto productoAmodificar = detalle.getProducto();
		archivoProducto.modificarRegistroObajaRegistro(productoAmodificar, productoAmodificar.getId());*/
		

				//Si algún registro falla, devolvemos false:
		if (registroDetalle.getSuccess() == false) {
			registroCorrecto = false;
		}
	}

	//Si se registraron correctamente tanto detalles como transaccion, se avanza OK:
	if (registro.getSuccess() && registroCorrecto) {
		//caja.gestionarCaja(_monto, _tipo);
		response.setSuccess("Se registro la venta correctamente", registro.getData());
		venta.carritoDeVenta(true);
	}
	else {
		response.setFailure("No se pudo registrar la venta");
	}
	sistema->limpiarSubModulo();
	return response;
}