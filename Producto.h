#pragma once

#include <string>
#include <cstring>
#include "Archivo.h"


class Producto
{
public:

    Producto();
    int getId();
    float getPrecioCosto();
    float getPrecioVenta();
    int getCantidad();
    std::string getNombreProducto();
    std::string getDescripcionProducto();
    bool getEstado();

    void setId(int id);
    void setPrecioCosto(float pCosto);
    void setPrecioVenta(float pVenta);
    void setCantidad(int cantidad);
    void setNombreProducto(std::string nombre);
    void setDescripcionProducto(std::string descripcion);
    void setEstado(bool estado);

    void cargarProductos();
    void mostrarProductos();

    Producto listarYSeleccionarProductoVenta();


private:

    int _id;
    float _precioCosto, _precioVenta;
    int _cantidad;
    char _nombreProducto[30], _descripcionProducto[45];
    bool _estado;
    //Categoria::_idCategoria;
};

