#pragma once

#include <string>
#include <cstring>
#include "Archivo.h"
#pragma warning(disable: 4996)

class Producto
{
public:

    Producto();
    int getIdProducto();
    float getPrecioCosto();
    float getPrecioVenta();
    int getCantidad();
    std::string getNombreProducto();
    std::string getDescripcionProducto();

    void setIdProducto(int id);
    void setPrecioCosto(float pCosto);
    void setPrecioVenta(float pVenta);
    void setCantidad(int cantidad);
    void setNombreProducto(std::string nombre);
    void setDescripcionProducto(std::string descripcion);

    void cargarProductos();
    void mostrarProductos();

private:
    int _idProducto;
    float _precioCosto, _precioVenta;
    int _cantidad;
    char _nombreProducto[30], _descripcionProducto[45];
    //Categoria::_idCategoria;
};

