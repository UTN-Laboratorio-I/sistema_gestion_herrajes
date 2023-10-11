#include <iostream>
#include "Producto.h"
#include "Sistema.h"

using namespace std;


int main() {
    int opc;
    while (true) {
        system("cls");
        cout << "MENU CLIENTES " << endl;
        cout << "********************** " << endl;
        cout << "1. AGREGAR CLIENTE " << endl;
        cout << "2. DAR DE BAJA CLIENTE " << endl;
        cout << "3. MODIFICAR REGISTRO DE CLIENTE " << endl;
        cout << "4. MOSTRAR CLIENTE " << endl;
        cout << "0. SALIR DEL PROGRAMA " << endl;
        cout << "********************** " << endl;
        cout << "OPCION " << endl;
        cin >> opc;
        system("cls");

        switch (opc) {
        case 1: cargarCliente();
            break;

        case 2: /*code*/
              break;

        case 3: /*code*/    
            break;

        case 4: /*code*/
            break;

        case 5: /*code*/
            break;

        case 0: return 0;
            break;

	return 0;
}