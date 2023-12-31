#pragma once
#pragma warning (disable : 4996)
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "ResponseDto.h"
#include "Configuracion.h"
using namespace std;
template <class T>
class Archivo
{
private:
    const char* _nombreArchivo;

public:
    Archivo(const char* nombreArchivo){ _nombreArchivo = nombreArchivo; }

    //Esta funci�n permite guardar un registro en cualquier archivo:
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

    //Esta funci�n devuelve un listado de todos los registros de un determinado archivo.
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

    //Esta funci�n recibe un puntero a una funci�n que recibe un objeto de tipo T
    //Lo que permite hacerla gen�rica, e implementarle por fuera la l�gica
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

        //Si encontr� un valor, lo devuelve, sino devuelve objeto vac�o:
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

    bool modificarRegistroObajaRegistro(T &objeto, int posicion, bool modificar = true)
    {
        FILE* p = fopen(_nombreArchivo, "rb+");

        if (p == NULL)
        {
            return false;
        }

        if (!modificar)
        {
            fseek(p, sizeof(T) * posicion, 0);
            objeto.setId(posicion + 1);
            objeto.setEstado(false);
        }
        else
        {
            fseek(p, sizeof(T) * posicion, 0);
            objeto.setId(posicion+1);
            fwrite(&objeto, sizeof(T), 1, p);
        }


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

    Response<T> buscarUnRegistro(int id) {
        T obj;
        Response<T> res;
        int pos = buscarPosRegistro(T(), id);

        res = listarUnRegistro(pos, T());

        return res;
    }

    template <class FuncionValidacion>
    Response<T> grabarOModificarRegistro(T objeto, int idBuscado, FuncionValidacion validacion) {
        Response<T> response;

        FILE* p = fopen(_nombreArchivo, "rb+");
        T objetoLeido;

        if (p == NULL) {
            FILE* a = fopen(_nombreArchivo, "ab");
            bool escribio = fwrite(&objeto, sizeof(T), 1, a);
            response.setSuccess("Se creo el registro", objeto);
            fclose(a);
            return response;
        }

        int posicionObjeto = 0;

        while (fread(&objetoLeido, sizeof(T), 1, p) == 1) {
            if (validacion(idBuscado, objetoLeido)) {
                fseek(p, sizeof(T) * posicionObjeto, 0);
                bool actualizo = fwrite(&objeto, sizeof(T), 1, p);

                if (actualizo) {
                    fclose(p);
                    response.setSuccess("Se actualiz� el registro", objeto);
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
            response.setSuccess("Guardado con �xito", objeto);
        }
        else {
            response.setFailure("No se pudo guardar el registro.");
        }

        return response;
    }

    //Utilizado en registro y modificaci�n de configuraciones:
    Response<Configuracion> grabarOModificarConfiguracion(Configuracion objeto) {
        Response<Configuracion> res;
    FILE* p = fopen(_nombreArchivo, "rb+");
		if (p == NULL) {
			p = fopen(_nombreArchivo, "ab");
			bool escribio = fwrite(&objeto, sizeof(T), 1, p);
			fclose(p);
			res.setSuccess("Se creo el registro", objeto);
            return res;
		}

		Configuracion objetoLeido;
		while (fread(&objetoLeido, sizeof(Configuracion), 1, p) == 1) {
				fseek(p, sizeof(Configuracion) * 0, 0);
				bool actualizo = fwrite(&objeto, sizeof(Configuracion), 1, p);
				fclose(p);
                res.setSuccess("Se actualiz� el registro", objeto);
                return res;
		}
	}
    
    Response<Configuracion> obtenerConfiguracion() {
        Response<Configuracion> res;
		FILE* p = fopen(_nombreArchivo, "rb");
		Configuracion objetoLeido;
        if (p == NULL) {
            res.setFailure("El archivo no existe");
            return res;
		}
        while (fread(&objetoLeido, sizeof(Configuracion), 1, p) == 1) {
			fclose(p);
            res.setSuccess("Se obtuvo la configuracion", objetoLeido);
            return res;
		}
        res.setFailure("No se pudo obtener la configuracion");
        return res;
    }


private:

};




