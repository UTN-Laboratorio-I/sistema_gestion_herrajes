#pragma once
#include "Persona.h"
#include <iostream>
#include <cstdio>

class Proveedor : public Persona
{
public:

	void cargarProveedor();
	void MostarProveedor();

	/// <getters especiales>
	/// agregar los getters del diagrama de clases 
	/// </summary>
	/// <returns></returns>

	int getIdProveedor();

	void setIdProveedor(int id);

private:

	int _idProveedor;

};

