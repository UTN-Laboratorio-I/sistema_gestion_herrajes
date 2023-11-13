#pragma once
#pragma warning (disable : 4996)
#include <functional>
#include <vector>
#include <iostream>
#include "ResponseDto.h"
using namespace std;
template <class T>
class Archivo
{
private:
    const char* _nombreArchivo;

public:
    Archivo(const char* nombreArchivo){ _nombreArchivo = nombreArchivo; }

    //Esta función permite guardar un registro en cualquier archivo:
    Response<T> grabarRegistroArchivo(T objeto) {
        Response<T> response;
        FILE* p;
        p = fopen(_nombreArchivo, "ab");

        if (p == NULL) {
            response.setFailure("No se encontro archivo");
            return response;
        }

        setIdIncremental(objeto, p);

        bool escribio = fwrite(&objeto, sizeof(objeto), 1, p);

        fclose(p); 

        if (escribio) {
            response.setSuccess("Guardado con exito", objeto);
        } 
        else{
            response.setFailure("No se pudo guardar el registro.");
        }
        return response;
    }

    //Esta función devuelve un listado de todos los registros de un determinado archivo.
    std::vector<T> listarRegistroArchivo() {
        std::vector<T> registros;

        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == nullptr) {
            cerr << "Error al abrir el archivo." << endl;
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
            std::cerr << "Error al abrir el archivo." << endl;
            return T();
        }

        T objeto{};
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

    // Esta es una funcion que cuenta la cantidad de registros.
    bool setIdIncremental(T &objeto, FILE* p)
    {

        fseek(p, 0, SEEK_END);
        int tam = ftell(p);

        int cantidadReg = tam / sizeof(T);
        int idSecuencial = cantidadReg + 1;

        objeto.setId(idSecuencial);

        return true;

    }

    bool modificarRegistro(T &objeto, int posicion)
    {
        FILE* p = fopen(_nombreArchivo, "rb+");

        if (p == NULL)
        {
            return false;
        }

        fseek(p, sizeof(T) * posicion, 0);
        objeto.setId(posicion);
        fwrite(&objeto, sizeof(T), 1, p);

        fclose(p);

        return true;

    }

    int buscarPosRegistro(T objeto, int valorBuscado)
    {
        FILE* p = fopen(_nombreArchivo, "rb");

        if (p == NULL)
        {
            return -1;
        }

        int contador = 0;
        bool encontro = false;
        int posicion = -1;

        while (fread(&objeto, sizeof(T), 1, p) == 1)
        {
            if (objeto.getId() == valorBuscado)
            {
                posicion = contador;
                encontro = true;
                break;
            }
            contador++;
        }

        if (encontro)
        {
           return posicion;
        }
        else
        {
            posicion = -1;
        }
        
        fclose(p);
        return posicion;
    }

    Response <T> listarUnRegistro(int posicion, T objeto)
    {
        Response <T> response;

        FILE* p = fopen(_nombreArchivo, "rb");

        if (p == NULL)
        {
            response.setFailure("No se pudo leer el archivo...");
            return response;
        }

        if (posicion == -1)
        {
            response.setFailure("No se pudo encontrar el registro solicitado");
            return response;
        }


        fseek(p, sizeof(T) * posicion, 0);
        
        fread(&objeto, sizeof(T), 1, p);

        response.setSuccess("Registro encontrado: ", objeto);

        fclose(p);

        return response;
           
    }

    template <class FuncionValidacion>
    Response<T> grabarOModificarRegistro(T objeto, int idBuscado, FuncionValidacion validacion) {
        Response<T> response;

        FILE* p = fopen(_nombreArchivo, "rb+");
        T objetoLeido;

        if (p == NULL) {

            p = fopen(_nombreArchivo, "ab");
            bool escribio = fwrite(&objeto, sizeof(T), 1, p);
            response.setSuccess("Se creo el registro", objeto);
            return response;
        }

        int posicionObjeto = 0;

        while (fread(&objetoLeido, sizeof(T), 1, p) == 1) {
            if (validacion(idBuscado, objetoLeido)) {
                fseek(p, sizeof(T) * posicionObjeto, 0);
                bool actualizo = fwrite(&objeto, sizeof(T), 1, p);

                if (actualizo) {
                    fclose(p);
                    response.setSuccess("Se actualizó el registro", objeto);
                    return response;
                }
                else {
                    fclose(p);
                    response.setFailure("No se pudo actualizar el registro.");
                    return response;
                }
            }
            posicionObjeto++;
        }

        fseek(p, 0, SEEK_END);
        bool escribio = fwrite(&objeto, sizeof(T), 1, p);

        fclose(p);

        if (escribio) {
            response.setSuccess("Guardado con éxito", objeto);
        }
        else {
            response.setFailure("No se pudo guardar el registro.");
        }

        return response;
    }


private:

};




