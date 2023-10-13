#pragma once
#pragma warning (disable : 4996)

#include <vector>

template <class T>
class Archivo
{
public:
    Archivo() = default;

    bool grabarRegistroArchivo(T objeto, const char* archivo) {
        FILE* p;
        p = fopen(archivo, "ab");

        if (p == NULL) {
            return false;
        }

        bool escribio = fwrite(&objeto, sizeof(objeto), 1, p);

        fclose(p); 

        return escribio;
    }

    std::vector<T> listarRegistroArchivo(const char* archivo) {
        std::vector<T> registros; 

        FILE* p;
        p = fopen(archivo, "rb");

        if (p == NULL) {

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
