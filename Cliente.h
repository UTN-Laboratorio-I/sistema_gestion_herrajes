#pragma once
#include "Persona.h"
#include "ResponseDto.h"
#include <iostream>
#include <cstdio>

using namespace std;

class Cliente : public Persona
{

public:

	Response<Cliente> cargarCliente();
	Cliente cargarClienteAmodificar();
	Response<Cliente> modificarOdarBajaCliente(bool modificar = true);
	Cliente darBajaCliente(int id);
	void mostarCliente();

	/// <getters especiales>
	/// agregar los getters del diagrama de clases 
	/// </summary>
	/// <returns></returns>

	int getId();
	char* getRazonSocial();
	long long getCuit();

	void setId(int id);
	void setCuit(long long cuit);
	void setRazonSocial(const char* razonSocial);

	Cliente listarYSeleccionarClienteExistente();

	void verClienteAmodificar(Response <Cliente> responseCliente);

private:

	int _idCliente;
	char _razonSocial[50];
	long long _cuit;
	bool modificar = true;
};