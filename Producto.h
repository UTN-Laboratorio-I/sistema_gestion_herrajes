#pragma once

#include <string>
#include <cstring>
#include "Archivo.h"

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
    bool getEstado();

    void setIdProducto(int id);
    void setPrecioCosto(float pCosto);
    void setPrecioVenta(float pVenta);
    void setCantidad(int cantidad);
    void setNombreProducto(std::string nombre);
    void setDescripcionProducto(std::string descripcion);
    void setEstado(bool estado);

    void cargarProductos();
    void mostrarProductos();


private:

    int _idProducto;
    float _precioCosto, _precioVenta;
    int _cantidad;
    char _nombreProducto[30], _descripcionProducto[45];
    bool _estado;
    //Categoria::_idCategoria;
};

