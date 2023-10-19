#include "Cliente.h"


void Cliente::cargarCliente()
{
	int cuit, idCliente;
	char razonSocial[50];

	cargar();

	cout << "INGRESE ID CLIENTE: ";
	cin >> idCliente;
	cout << endl;
	cout << "CUIT: ";
	cin >> cuit;
	cout << endl;
	cout << "RAZON SOCIAL: ";
	cin >> razonSocial;
	cout << endl;

	setIdCliente(idCliente);
	setCuit(cuit);
	setRazonSocial(razonSocial);

}

void Cliente::MostarCliente()
{
	mostrar();

	cout << "ID CLIENTE: " << getIdCliente() << endl;
	cout << "CUIT: " << getCuit() << endl;
	cout << "RAZON SOCIAL: " << getRazonSocial() << endl;

}

int Cliente::getIdCliente() {return _idCliente; }
char* Cliente::getRazonSocial(){return _razonSocial;}
int Cliente::getCuit(){return _cuit;}

void Cliente::setIdCliente(int id){_idCliente = id;}
void Cliente::setCuit(int cuit){cuit = cuit;}
void Cliente::setRazonSocial(const char* razonSocial){strcpy_s(_razonSocial, razonSocial);}