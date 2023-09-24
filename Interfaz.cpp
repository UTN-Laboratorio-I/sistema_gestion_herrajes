#include <iostream>
#include "Interfaz.h"
using namespace std;
void Interfaz::setPantalla(int opc) { this->_pantalla = opc; }
int Interfaz::getPantalla(int opc) { return opc; }

int Interfaz::menuPrincipal(int opc) {
	cout << "Sistema de Gestion" << endl;
	cout << "------------------" << endl << endl;
	cout << "1) Compras / Gestion Stock" << endl;
	cout << "2) Ventas" << endl;
	cout << "3) ABM" << endl;
	cout << "4) Reportes" << endl;
	cout << "";


}