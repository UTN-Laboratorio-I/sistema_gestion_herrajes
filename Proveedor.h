#pragma once
#include "Persona.h"
#include <iostream>
#include <cstdio>
#include "Archivo.h"
#include "Helper.h"
#include "InterfazUI.h"

class Proveedor : public Persona
{
public:
	const char* getRazonsocial() { return _razonSocial; }
	const char* getCuit() { return _cuit; }
	int getId();
	void setId(int id);
	void setRazonSocial(string razonSocial) { strcpy_s(_razonSocial, razonSocial.c_str()); }
	void setCuit(string cuit) { strcpy_s(_cuit, cuit.c_str()); }

	Response <Proveedor> cargarProveedor();
	Response <Proveedor> buscarProveedor();
	
	void ver_ProveedorEncontrado(Response <Proveedor> proveedor);
	
	Proveedor darBajaProveedor(int id);
	Response<Proveedor> modificarOdarBajaProveedor(bool modificar = true);
	void verProveedorAmodificar(Response <Proveedor> responseProveedor);
	Proveedor cargarProveedorAmodificar();

	void mostarProveedor();
	void MostarProveedor();

	Response <Proveedor> opcionModificar(Response <Proveedor> &response);
	Response <Proveedor> modificarCampos(Response <Proveedor> &response);
	void headerProductoAmodificar(Response <Proveedor> response);


private:

	int _idProveedor;
	char _razonSocial[30];
	char _cuit[30];
	bool modificar = false;
};

