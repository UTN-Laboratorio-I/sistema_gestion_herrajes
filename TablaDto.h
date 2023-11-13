#include <iostream>
#include <vector>
#include <iomanip>
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

    vector<columnas> _columnas;
    string _tipo;
    vector<T> _datos;
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
        _columnas = getColumnas();
        _conversion_tipo = helper.conversorNombreTablaSwitch(tipo);
        _anchoTotalTabla = 0;
        _limpiarPantalla = limpiarPantalla;
    }
    /// <summary>
    /// Muestra tanto el header como el contenido de la tabla:
    /// </summary>
    void mostrarNuevaTabla() {
        if (_limpiarPantalla) helper.limpiarConsola();
        for (columnas col : _columnas) {
            cout << setw(col.ancho) << col.header;
            _anchoTotalTabla += col.ancho;

        }
        cout << endl;
        cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;

        mostrarContenidoSegunEntidad();
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
        case 1: //Compras
            columnasResult.push_back({ "Id", 5 });
            columnasResult.push_back({ "Nombre", 30 });
            columnasResult.push_back({ "Precio", 15 });
            columnasResult.push_back({ "Cantidad", 15 });
            columnasResult.push_back({ "Subtotal", 20 });
            break;
        case 2: //Ventas
			columnasResult.push_back({ "Id", 5 });
			columnasResult.push_back({ "Nombre", 30 });
			columnasResult.push_back({ "Precio", 15 });
			columnasResult.push_back({ "Cantidad", 15 });
			columnasResult.push_back({ "Subtotal", 20 });
			break;
        default:
            break;
        }

        return columnasResult;
    }

    /// <summary>
    /// Acá se setea manualmente los datos que se mostrarán por cada registro
    /// </summary>
    void mostrarContenidoSegunEntidad() {
        int conversion_tipo = helper.conversorNombreTablaSwitch(_tipo);

        switch (_conversion_tipo) {
        case 0: //Usuarios
            vector<Usuario> listaUsuarios = _datos;
            for (Usuario datos : listaUsuarios) {
                cout << setw(_columnas[0].ancho) << datos.getId();
                cout << setw(_columnas[1].ancho) << datos.getUsuario();
                cout << setw(_columnas[2].ancho) << datos.getNombre();
                cout << setw(_columnas[3].ancho) << datos.getRol();
                cout << endl;
            }
            cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
            break;
   //     case 1: //Compras
   //         vector<Compra>
   //         for (T datos : _datos) {
   //             cout << setw(_columnas[0].ancho) << datos.getId();
			//	cout << setw(_columnas[1].ancho) << datos.getNombreProducto();
			//	cout << setw(_columnas[2].ancho) << datos.getPrecio();
			//	cout << setw(_columnas[3].ancho) << datos.getCantidad();
			//	cout << setw(_columnas[4].ancho) << datos.getSubtotal();
			//	cout << endl;
			//}
   //         break;
   //     case 2: //Ventas
   //         for (T datos : _datos) {
   //             cout << setw(_columnas[0].ancho) << datos.getId();
   //         }
        }
    }


#pragma region contenido

    void mostrarUsuarios(T datos) {

    }

    //void mostrarCompras(T datos){
    //    cout << setw(_columnas[0].ancho) << datos.getNombreProducto();
    //    cout << endl;
    //}
#pragma endregion contenido
    

};
