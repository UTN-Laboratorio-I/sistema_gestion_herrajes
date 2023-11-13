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
    bool _limpiarPantalla = true;
    int _anchoTotalTabla = 0;
    int _conversion_tipo;


public:
    TablaDto() {}
    TablaDto(string tipo, vector<T> datos) {
        _datos = datos;
        _columnas = getColumnas();
        _conversion_tipo = helper.conversorNombreTablaSwitch(tipo);
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
            
            for (T datos : _datos) {
                cout << setw(_columnas[0].ancho) << datos.getId();
                cout << setw(_columnas[1].ancho) << datos.getUsuario();
                cout << setw(_columnas[2].ancho) << datos.getNombre();
                cout << setw(_columnas[3].ancho) << datos.getRol();
                cout << endl;
            }
            cout << setfill('-') << setw(_anchoTotalTabla) << "-" << setfill(' ') << endl;
        case 1: //Compras
            for (T datos : _datos) {
				cout << setw(_columnas[0].ancho) << datos.getId();
				cout << setw(_columnas[1].ancho) << datos.getNombre();
				cout << setw(_columnas[2].ancho) << datos.getPrecio();
				cout << setw(_columnas[3].ancho) << datos.getCantidad();
				cout << setw(_columnas[4].ancho) << datos.getSubtotal();
				cout << endl;
			}

            break;
        }
    }
    

};
