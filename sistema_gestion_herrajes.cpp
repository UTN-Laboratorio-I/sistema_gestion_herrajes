#include <iostream>
#include "Producto.h"
#include "Sistema.h"
#include "Persona.h"


using namespace std;


int main() {
	/*Sistema sistema;

	sistema.administrarPrograma();*/

	Persona persona;
	persona.cargar();

	persona.mostrar();



	system("pause");
	return 0;
}