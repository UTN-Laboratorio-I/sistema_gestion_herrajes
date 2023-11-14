#include <iostream>
#include <vector>
#include <iomanip>
#include "Helper.h"
#include "Usuario.h"
#include "Producto.h"
#include "Cliente.h"
#include "DetalleDto.h"
#include "Transaccion.h"

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
    string _tipo;
    bool _limpiarPantalla;
    int _anchoTotalTabla;
    int _conversion_tipo;


public:
    TablaDto() {}

    /// <summary>
    /// Constructor que recibe el tipo de tabla y los datos a mostrar
    /// </summary>
    /// <param name="tipo"></param>
    /// <param name="datos"></param>
    TablaDto(string tipo, vector<T> datos, bool limpiarPantalla=true) {
        _datos = datos;
        _conversion_tipo = helper.conversorNombreTablaSwitch(tipo);
        _columnas = getColumnas();
        _anchoTotalTabla = 0;
        _limpiarPantalla = limpiarPantalla;
    }

    int getAnchoTotalTabla() { return _anchoTotalTabla; }
    vector<int> getAnchoColumnas() { return _anchoColumnas; }

    /// <summary>
    /// Muestra tanto el header como el contenido de la tabla:
    /// </summary>
    void mostrarHeaderTabla() {
        if (_limpiarPantalla) helper.limpiarConsola();
        for (columnas col : _columnas) {
            cout << setw(col.ancho) << col.header;
            _anchoTotalTabla += col.ancho;

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
			break;
        case 3: //Carrito
            columnasResult.push_back({ "Item nro", 10 });
			columnasResult.push_back({ "Nombre Producto", 20 });
			columnasResult.push_back({ "Precio Unitario", 20 });
			columnasResult.push_back({ "Cantidad", 10 });
            columnasResult.push_back({ "Subtotal", 15 });
			break;
        default:
            break;
        }

        for (columnas col : columnasResult) {
			_anchoColumnas.push_back(col.ancho);
		}
        return columnasResult;
    }

#pragma region contenido
    /// <summary>
	/// Acá se setea manualmente el contenido de cada tabla:
    /// </summary>
    void generarTablaUsuarios(vector<Usuario> lista) {
        mostrarHeaderTabla();
     	for (Usuario datos : lista) {
     		cout << setw(_columnas[0].ancho) << datos.getId();
     		cout << setw(_columnas[1].ancho) << datos.getUsuario();
     		cout << setw(_columnas[2].ancho) << datos.getNombre();
     		cout << setw(_columnas[3].ancho) << datos.getRol();
     		cout << endl;
     	}
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
    }
    void generarTablaProductos(vector<Producto> lista) {
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
	}
    void generarTablaClientes(vector<Cliente> lista) {

		mostrarHeaderTabla();
        for (Cliente datos : lista) {
            cout << setw(_columnas[0].ancho) << datos.getIdCliente();
            cout << setw(_columnas[1].ancho) << datos.getNombre();
            cout << setw(_columnas[2].ancho) << datos.getApellido();
            cout << setw(_columnas[3].ancho) << datos.getRazonSocial();
            cout << setw(_columnas[4].ancho) << datos.getCuit();
            cout << endl;
        }
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
    }

    void generarCarritoProductos(vector<DetalleDto> carrito) {
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
    }
#pragma endregion contenido
    

};
