#pragma once
#pragma warning (disable : 4996)

#include <vector>

template <class T>
class Archivo
{
private:
    const char* _nombreArchivo;

public:
    Archivo(const char* nombreArchivo){ _nombreArchivo = nombreArchivo; }

    bool grabarRegistroArchivo(T objeto) {
        FILE* p;
        p = fopen(_nombreArchivo, "ab");

        if (p == NULL) {
            return false;
        }

        bool escribio = fwrite(&objeto, sizeof(objeto), 1, p);

        fclose(p); 

        return escribio;
    }

    std::vector<T> listarRegistroArchivo() {
        std::vector<T> registros;

        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == nullptr) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return registros;
        }

        T objeto;
        while (fread(&objeto, sizeof(T), 1, p) == 1) {
            registros.push_back(objeto);
        }

        fclose(p);

        return registros;
    }

private:

};


