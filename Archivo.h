#pragma once

template <class T>
class Archivo
{
public:
	Archivo() = default;

	bool listarRegistroArchivo(const char* archivo);
	bool grabarRegistroArchivo(T objeto, const char* archivo);

private:

};
