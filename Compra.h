#pragma once

#include "Transaccion.h"
#include "TransaccionDto.h"
#include "ResponseDto.h"
#include "Proveedor.h"
#include <vector>;
#include "Producto.h"

class Compra : public Transaccion 
{
private:
	int _id;
	int _idProveedor;
	char _tipo;


public:
	Compra();
	
	void setId(int id);
	void setIdProveedor(int idProv);
	void setTipoTransaccion(char tipoTransaccion);

	int getId();
	int getIdProveedor();
	char getTipoTransaccion();


	void agregarADetalleCompra(Producto producto, int cantidad);

	void mostrarCompras();

	bool realizarCompra(Sistema* sistema);

	Response <TransaccionDto> registrarNuevaCompra (Sistema *sistema, InterfazUI interfaz, Response <Proveedor> prov);

};

