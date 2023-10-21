#pragma once
#pragma warning (disable : 4996)
#include <functional>
#include <vector>
using namespace std;
template <class T>
class Archivo
{
private:
    const char* _nombreArchivo;

public:
    Archivo(const char* nombreArchivo){ _nombreArchivo = nombreArchivo; }

    //Esta función permite guardar un registro en cualquier archivo:
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

    //Esta función devuelve un listado de todos los registros de un determinado archivo.
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

    //Esta función recibe un puntero a una función que recibe un objeto de tipo T
    //Lo que permite hacerla genérica, e implementarle por fuera la lógica
    template<typename FuncionValidacion>
    T buscarRegistroByParametro(FuncionValidacion funcionValidacion) {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == nullptr) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            return T();
        }

        T objeto;
        bool valor_encontrado = false;
        while (fread(&objeto, sizeof(T), 1, p) == 1) {
            if (funcionValidacion(objeto)) {
                valor_encontrado = true;
                fclose(p);
                break;
                
            }
           
        }

        //Si encontró un valor, lo devuelve, sino devuelve objeto vacío:
        fclose(p);
        if(valor_encontrado)
			return objeto;
		else
			return T();
    }

    int contadorRegistros(vector <T> objeto, Archivo <T> archi)
    {
	    
        //Archivo <T> archivo(nombreArchivo);

	    objeto = archi.listarRegistroArchivo();

	    int cantidadReg = 0;

	    for (T i : objeto)
	    {
		    cantidadReg++;
	    }

	    return cantidadReg;
    }
private:

};




