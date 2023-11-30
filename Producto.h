#pragma once

#include <string>
#include <cstring>
#include "Archivo.h"
#include "Stock.h"
#include "ResponseDto.h"


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


    Response <Producto> responseCargarProducto();

    Response<Producto> modificarOdarBajaProducto(bool modificar = true);
    Producto darBajaProducto(int id);

    void verProductoAmodificar(Response <Producto> responseProducto);

    Producto cargarProductoAmodificar(bool inventario = false);

    void mostrarProducto();

    Producto cargarProductos(bool inventario = false);
    void mostrarProductos();

    Producto listarYSeleccionarProductoVenta(float margenUtilidad);

    Producto listarYSeleccionarProductoCompra();

    void tablaProductosContenido(vector<Producto> lista, vector<int> columnas, int anchoTabla);

    /// 23 - 11

    Response <Producto> opcionModificar(Response <Producto> &response);
    Response <Producto> modificarCampos(Response <Producto>& response);
    void headerProductoAmodificar(Response <Producto> response);


private:

    int _id;
    float _precioCosto, _precioVenta;
    int _cantidad;
    char _nombreProducto[30], _descripcionProducto[45];
    bool _estado;
    bool modificar = false;
    bool inventario = false;
};

