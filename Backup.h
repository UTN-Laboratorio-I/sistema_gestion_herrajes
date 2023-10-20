#pragma once
#pragma warning (disable : 4996)

#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include "Fecha.h"
#include "ErrorDto.h"

using namespace std;

template <class T>
class Backup
{
private:
	const char* _nombreArchivo;
	const char* _nombreBackUp;

public:
#pragma region CONSTRUCTOR
	Backup(){
	}
	
	Backup(const char* nombreArchivo, const char* nombreBackUp)
	{
		_nombreArchivo = nombreArchivo;
		_nombreBackUp = nombreBackUp;
	}
#pragma endregion

#pragma region METODOS
	
	bool grabarCopiaDeSeguridad(T objeto)
	{
		bool cargo = false;
		
		FILE* p;
		p = fopen(_nombreArchivo, "rb");
		FILE* pBack;
		pBack = fopen(_nombreBackUp, "wb");

		if (pBack == NULL) { return cargo; }
		if (p == NULL) { return cargo; }

		while (fread(&objeto, sizeof(T), 1, p) == 1)
		{
			fwrite(&objeto, sizeof(T), 1, pBack);
		}
		fclose(p);
		fclose(pBack);

		cargo = true;

		cout << "BackUp realizado correctamente..." << endl;
		
		return cargo;
	}

	/*bool cargarCopiaDeSeguridad(T objeto) {
		
		FILE* p;
		FILE* pBack;

		bool cargo = true;
		
		pBack = fopen(_nombreBackUp, "rb");
		p = fopen(_nombreArchivo, "wb");

		if (pBack == NULL) {
			error.getError();
			cargo = false;
			return cargo;
		}
		if (p == NULL) { 
			error.getError();
			cargo = false;
			return false;
		}

		while (fread(&objeto, sizeof(T), 1, pBack) == 1)
		{
			fwrite(&objeto, sizeof(T), 1, p);
		}

		fclose(p);
		fclose(pBack);

		cout << "BackUp realizado correctamente...";

		return cargo;
	}*/

#pragma endregion
};

