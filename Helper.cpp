#include "Helper.h"

void cargarCadena(char* palabra, int tam) {
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++) {
        palabra[i] = cin.get();
        if (palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

bool grabarRegistro() {

    Cliente reg;
    ArchivoClientes arch("clientes.dat");
    cout << "INGRESAR LOS DATOS DEL CLIENTE " << endl;
    reg.Cargar();
    bool escribio = Arch.grabarRegistro(reg);
    return escribio;

}
