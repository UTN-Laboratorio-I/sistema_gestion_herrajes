#include <iostream>
#include <vector>
using namespace std;

#pragma once

template <class T>
class TablaDto {
private:
    struct columnas {
        string header;
        int ancho;
    };

    vector<columnas> _columnas;
    vector<T> _datos;

public:
    TablaDto() {}
    TablaDto(int tipo, vector<T> datos) {
        _datos = datos;
        _columnas = getColumnas(tipo);
    }

    void mostrarNuevaTabla() {
        for (columnas col : _columnas) {
            cout << col.header << " | ";
        }
        cout << endl;
    }

    vector<columnas> getColumnas(int tipo) {
        vector<columnas> columnasResult;

        switch (tipo) {
        case 0: //Carritoventa
            columnasResult.push_back({ "Id", 5 });
            columnasResult.push_back({ "Nombre", 20 });
            columnasResult.push_back({ "Precio", 10 });
            columnasResult.push_back({ "Cantidad", 10 });
            columnasResult.push_back({ "Subtotal", 10 });
            break;
        default:
            break;
        }

        return columnasResult;
    }
};
