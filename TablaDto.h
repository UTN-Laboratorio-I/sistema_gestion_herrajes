#include <iostream>
#include <vector>
#include <iomanip>
#include "Helper.h"
#include "Usuario.h"
#include "Producto.h"
#include "Cliente.h"
#include "DetalleDto.h"
#include "Transaccion.h"
#include "Proveedor.h"
#include "TransaccionDto.h"

using namespace std;
#pragma once

template <class T>
class TablaDto {
private:
    //Inyección de dependencias:
    Helper helper;

private:
    struct columnas {
        string header;
        int ancho;
    };
    struct responseTabla {
		vector<int> anchoColumnas;
		int anchoTotalTabla;
	};

    vector<T> _datos;
    vector<columnas> _columnas;
    vector<int> _anchoColumnas; //para el contenido de la tabla.
    vector<string> _headers; //para los exports
    string _tipo;
    bool _limpiarPantalla;
    int _anchoTotalTabla;
    int _conversion_tipo;
    bool _isReporte;


public:
    TablaDto() {}

    /// <summary>
    /// Constructor que recibe el tipo de tabla y los datos a mostrar
    /// </summary>
    /// <param name="tipo"></param>
    /// <param name="datos"></param>
    TablaDto(string tipo, vector<T> datos, bool limpiarPantalla=true, bool isReporte=false) {
        _datos = datos;
        _conversion_tipo = helper.conversorNombreTablaSwitch(tipo);
        _columnas = getColumnas();
        _anchoTotalTabla = 0;
        _limpiarPantalla = limpiarPantalla;
        _isReporte = isReporte;
        _tipo = tipo;
    }

    int getAnchoTotalTabla() { return _anchoTotalTabla; }
    vector<int> getAnchoColumnas() { return _anchoColumnas; }

    /// <summary>
    /// Muestra tanto el header como el contenido de la tabla:
    /// </summary>
    void mostrarHeaderTabla() {
        if (_limpiarPantalla) helper.limpiarConsola();

        for (columnas col : _columnas) {
			_anchoTotalTabla += col.ancho;
        }

        if (_isReporte) {
        cout <<_tipo << endl;
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl << endl;
        }

        for (columnas col : _columnas) {
            cout << setw(col.ancho) << col.header;
        }
        cout << endl;
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
    }

    /// <summary>
    /// Acá se setea manualmente el contenido del header de cada tabla:
    /// </summary>
    /// <returns></returns>
    vector<columnas> getColumnas() {
        Helper helper;
        vector<columnas> columnasResult;

        switch (_conversion_tipo) {
        case 0: //Usuario
            columnasResult.push_back({ "Id", 5 });
			columnasResult.push_back({ "Usuario", 30 });
			columnasResult.push_back({ "Nombre", 30 });
			columnasResult.push_back({ "Rol", 20 });
            columnasResult.push_back({ "Admin", 10 });
			break;
        case 1: //Productos
            columnasResult.push_back({ "Id", 5 });
            columnasResult.push_back({ "Nombre", 30 });
            columnasResult.push_back({ "Descripción", 30 });
            //columnasResult.push_back({ "Precio Costo", 15 });
            columnasResult.push_back({ "Precio Venta", 15 });
            //columnasResult.push_back({ "Cantidad", 15 });

            break;
        case 2: //Cliente
            columnasResult.push_back({ "Id", 5 });
            columnasResult.push_back({ "Nombre", 30 });
            columnasResult.push_back({ "Apellido", 30 });
            columnasResult.push_back({ "Razon Social", 30 });
            columnasResult.push_back({ "Cuit", 30 });
            columnasResult.push_back({ "Activo", 10 });

			break;
        case 3: //Carrito
            columnasResult.push_back({ "Item nro", 10 });
			columnasResult.push_back({ "Nombre Producto", 20 });
			columnasResult.push_back({ "Precio Unitario", 20 });
			columnasResult.push_back({ "Cantidad", 10 });
            columnasResult.push_back({ "Subtotal", 15 });
			break;
        case 4: //Reporte cliente
            columnasResult.push_back({ "Id", 2 });
			columnasResult.push_back({ "Nombre", 30 });
            columnasResult.push_back({ "Apellido", 30 });
            columnasResult.push_back({ "Razon Social", 30 });
            columnasResult.push_back({ "Cuit", 30 });
            columnasResult.push_back({ "Fecha Alta", 20 });
            columnasResult.push_back({ "E-mail", 30 });
            columnasResult.push_back({ "Activo", 10 });
            break;
        case 5: //Reporte proveedores
            columnasResult.push_back({ "Id", 5 });
			columnasResult.push_back({ "Nombre", 30 });
			columnasResult.push_back({ "Apellido", 30 });
			columnasResult.push_back({ "Razon Social", 30 });
			columnasResult.push_back({ "Cuit", 30 });
			columnasResult.push_back({ "Fecha Alta", 20 });
			columnasResult.push_back({ "E-mail", 30 });
			columnasResult.push_back({ "Activo", 10 });
			break;
        case 6: //Reporte productos
            columnasResult.push_back({ "Id", 5 });
			columnasResult.push_back({ "Nombre", 30 });
            columnasResult.push_back({ "Descripción", 30 });
            columnasResult.push_back({ "Precio Costo", 15 });
            columnasResult.push_back({ "Precio Venta", 15 });
            columnasResult.push_back({ "Stock disponible", 15 });
			break;
        case 7: //Reporte Usuarios
            columnasResult.push_back({ "Id", 5 });
			columnasResult.push_back({ "Usuario", 30 });
            columnasResult.push_back({ "Nombre", 30 });
            columnasResult.push_back({ "Rol", 20 });
            columnasResult.push_back({ "Admin", 10 });
			break;
        case 8: //Reporte ventas
			columnasResult.push_back({ "Id", 5 });
            columnasResult.push_back({ "Fecha", 30 });
            columnasResult.push_back({ "Total", 30 });
            columnasResult.push_back({ "Id Cliente", 30 });
            columnasResult.push_back({ "Id Usuario", 30 });
			break;
        case 9: //Reporte compras
            columnasResult.push_back({ "Id", 5 });
			columnasResult.push_back({ "Fecha", 30 });
			columnasResult.push_back({ "Total", 30 });
			columnasResult.push_back({ "Id Proveedor", 30 });
			columnasResult.push_back({ "Id Usuario", 30 });
        case 10: //Reporte caja
            columnasResult.push_back({ "Saldo Total", 10 });
            break;
        case 11: //Reporte transacciones (Venta/Compra)
            columnasResult.push_back({ "Id", 5 });
			columnasResult.push_back({ "Tipo Transaccion", 20 });
			columnasResult.push_back({ "Fecha", 20 });
			columnasResult.push_back({ "Id Cliente/Proveedor", 20 });
			columnasResult.push_back({ "Usuario", 20 });
            columnasResult.push_back({ "Producto", 20 });
            columnasResult.push_back({ "Cantidad", 10 });
            columnasResult.push_back({ "Monto", 15 });
            columnasResult.push_back({ "Total", 10 });
			break;
        default:
            break;
        }

        for (columnas col : columnasResult) {
			_anchoColumnas.push_back(col.ancho);
            _headers.push_back(col.header);
		}

        return columnasResult;
    }

#pragma region contenido
    /// <summary>
	/// Acá se setea manualmente el contenido de cada tabla:
    /// </summary>
    vector<string> generarTablaUsuarios(vector<Usuario> lista) {
        mostrarHeaderTabla();
     	for (Usuario datos : lista) {
     		cout << setw(_columnas[0].ancho) << datos.getId();
     		cout << setw(_columnas[1].ancho) << datos.getUsuario();
     		cout << setw(_columnas[2].ancho) << datos.getNombre();
     		cout << setw(_columnas[3].ancho) << datos.getRol();
            cout << setw(_columnas[4].ancho) << datos.getIsAdmin();
     		cout << endl;
     	}
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;
    }

    vector<string> generarTablaProductos(vector<Producto> lista) {
        mostrarHeaderTabla();
        for (Producto datos : lista) {
			cout << setw(_columnas[0].ancho) << datos.getId();
			cout << setw(_columnas[1].ancho) << datos.getNombreProducto();
			cout << setw(_columnas[2].ancho) << datos.getDescripcionProducto();
			//cout << setw(_columnas[3].ancho) << datos.getPrecioCosto();
			cout << setw(_columnas[3].ancho) << datos.getPrecioVenta();
			//cout << setw(_columnas[5].ancho) << datos.getCantidad();
			cout << endl;
		}
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;
	}
    vector<string> generarTablaClientes(vector<Cliente> lista) {

		mostrarHeaderTabla();
        for (Cliente datos : lista) {
            if(!_isReporte && !datos.getEstado()) continue;
            cout << setw(_columnas[0].ancho) << datos.getId();
            cout << setw(_columnas[1].ancho) << datos.getNombre();
            cout << setw(_columnas[2].ancho) << datos.getApellido();
            cout << setw(_columnas[3].ancho) << datos.getRazonSocial();
            cout << setw(_columnas[4].ancho) << datos.getCuit();
            cout << setw(_columnas[5].ancho) << datos.getEstado();

            cout << endl;
        }
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;

    }

    vector<string> generarCarritoProductos(vector<DetalleDto> carrito) {
        Producto producto;
        Response<Producto> res;
        Archivo<Producto> archivoProducto("productos.dat");
        int contador = 1;
        mostrarHeaderTabla();
        for (DetalleDto datos : carrito) {
            res = archivoProducto.buscarUnRegistro(datos.getIdProducto());
            int subtotal = datos.getCantidad() * datos.getPrecioUnitario();
            cout << setw(_columnas[0].ancho) << contador;
            cout << setw(_columnas[1].ancho) << res.getData().getNombreProducto();
            cout << setw(_columnas[2].ancho) << datos.getCantidad();
            cout << setw(_columnas[3].ancho) << datos.getPrecioUnitario();
            cout << setw(_columnas[4].ancho) << subtotal;
            cout << endl;
            contador++;
        }
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;

    }

    vector<string> generarReporteClientes(vector<Cliente> lista) {

		mostrarHeaderTabla();
		for (Cliente datos : lista) {
			cout << setw(_columnas[0].ancho) << datos.getId();
			cout << setw(_columnas[1].ancho) << datos.getNombre();
			cout << setw(_columnas[2].ancho) << datos.getApellido();
			cout << setw(_columnas[3].ancho) << datos.getRazonSocial();
			cout << setw(_columnas[4].ancho) << datos.getCuit();
			cout << setw(_columnas[5].ancho) << datos.getFechaAlta().toString();
			cout << setw(_columnas[6].ancho) << datos.getEmail();
            cout << std::boolalpha << std::setw(_columnas[7].ancho) << datos.getEstado();
			cout << endl;
		}
		cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;

	}

    vector<string> generarReporteProveedores(vector<Proveedor> lista) {

        mostrarHeaderTabla();
        for (Proveedor datos : lista) {
            cout << setw(_columnas[0].ancho) << datos.getId();
            cout << setw(_columnas[1].ancho) << datos.getNombre();
            cout << setw(_columnas[2].ancho) << datos.getApellido();
            cout << setw(_columnas[3].ancho) << datos.getRazonsocial();
            cout << setw(_columnas[4].ancho) << datos.getCuit();
            cout << setw(_columnas[5].ancho) << datos.getFechaAlta().toString();
            cout << setw(_columnas[6].ancho) << datos.getEmail();
            cout << std::boolalpha << std::setw(_columnas[7].ancho) << datos.getEstado();
            cout << endl;
        }
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;

    }

    vector<string> generarReporteProductos(vector<Producto> lista) {

		mostrarHeaderTabla();
		for (Producto datos : lista) {
			cout << setw(_columnas[0].ancho) << datos.getId();
			cout << setw(_columnas[1].ancho) << datos.getNombreProducto();
			cout << setw(_columnas[2].ancho) << datos.getDescripcionProducto();
			cout << setw(_columnas[3].ancho) << datos.getPrecioCosto();
			cout << setw(_columnas[4].ancho) << datos.getPrecioVenta();
			cout << setw(_columnas[5].ancho) << datos.getCantidad();
			cout << endl;
		}
		cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;

	}

    vector<string> generarReporteUsuarios(vector<Usuario> lista) {
        mostrarHeaderTabla();
        for (Usuario datos : lista) {
            cout << setw(_columnas[0].ancho) << datos.getId();
            cout << setw(_columnas[1].ancho) << datos.getUsuario();
            cout << setw(_columnas[2].ancho) << datos.getNombre();
            cout << setw(_columnas[3].ancho) << datos.getRol();
            cout << std::boolalpha << setw(_columnas[4].ancho) << datos.getIsAdmin();
            cout << endl;
        }
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;

    }

    vector<string> generarReporteTransacciones(vector<Transaccion> lista) {
        Archivo<Cliente> archivoCliente("clientes.dat");
        Archivo<Proveedor> archivoProveedor("proveedores.dat");
        		mostrarHeaderTabla();
            for (Transaccion datos : lista) {
                char tipo = datos.getTipo();
                cout << setw(_columnas[0].ancho) << datos.getId();
                cout << setw(_columnas[1].ancho) << (tipo=='v'?"Venta" : "Compra");
                cout << setw(_columnas[2].ancho) << datos.getFecha().toString();
                cout << setw(_columnas[3].ancho) << datos.getId();
                cout << setw(_columnas[4].ancho) << datos.getUsuario();
                cout << setw(_columnas[5].ancho) << "";
                cout << setw(_columnas[6].ancho) << "";
                cout << setw(_columnas[7].ancho) << "";
                cout << setw(_columnas[8].ancho) << datos.getMonto();
                cout << endl;
                for (Detalle detalle : datos.getDetalle()) {
                    cout << setw(_columnas[0].ancho) << "";
                    cout << setw(_columnas[1].ancho) << "";
                    cout << setw(_columnas[2].ancho) << "";
                    cout << setw(_columnas[3].ancho) << ""; 
                    cout << setw(_columnas[4].ancho) << "";
                    cout << setw(_columnas[5].ancho) << detalle.getProducto().getNombreProducto();
                    cout << setw(_columnas[6].ancho) << detalle.getCantidad();
                    cout << setw(_columnas[7].ancho) << detalle.getSubTotal();
                    cout << endl;
                }
                cout << setfill('.') << setw(_anchoTotalTabla) << "." << setfill(' ') << endl;
		    }

		cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        return _headers;

    }
 
   /* void generarTablaCompras(vector<TransaccionDto> listaTransaccion, vector<Compras> listaCompras) {
        mostrarHeaderTabla();

        for (TransaccionDto transaccion : listaTransaccion) {
            vector<Compras> comprasFiltradas;
            cout << setw(_columnas[0].ancho) << transaccion.getId();

            for(Compras compra : listaCompras) {
				if (compra.getIdTransaccion() == transaccion.getId()) {
                    cout << setw(_columnas[0].ancho) << datos.getRol();
				}
			})
        }
    }*/

	
	

#pragma endregion contenido
    

};
