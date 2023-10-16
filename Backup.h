#pragma once
#pragma warning (disable : 4996)

#include <cstdlib>
#include <cstring>
#include <stdio.h>

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
	
	bool realizarBackUp(T objeto)
	{
		
		FILE* p;
		p = fopen(_nombreArchivo, "rb");
		FILE* pBack;
		pBack = fopen(_nombreBackUp, "wb");

		if (pBack == NULL) { return false; }
		if (p == NULL) { return false; }

		while (fread(&objeto, sizeof(T), 1, p) == 1)
		{
				fwrite(&objeto, sizeof(T), 1, pBack);
		}

		fclose(p);
		fclose(pBack);

		pBack = fopen(_nombreBackUp, "rb");
		p = fopen(_nombreArchivo, "wb");

		if (pBack == NULL) { return false; }
		if (p == NULL) { return false; }

		while (fread(&objeto, sizeof(T), 1, pBack) == 1)
		{
			fwrite(&objeto, sizeof(T), 1, p);
		}

		fclose(p);
		fclose(pBack);

		cout << "BackUp realizado correctamente...";

		return true;
	}

#pragma endregion
};

