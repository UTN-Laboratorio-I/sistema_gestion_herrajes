#pragma once
#include "Persona.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "ResponseDto.h"
#include "Archivo.h"

using namespace std;

class Cliente : public Persona
{

public:

	void cargarCliente();
	void MostarCliente();

	/// <getters especiales>
	/// agregar los getters del diagrama de clases 
	/// </summary>
	/// <returns></returns>

	int getIdCliente();
	char* getRazonSocial();
	int getCuit();

	void setIdCliente(int id);
	void setCuit(int cuit);
	void setRazonSocial(const char* razonSocial);

	Response<Cliente> crearNuevoCliente();


private:

	int _idCliente, _cuit, _PersonaId;
	char _razonSocial[50];
};