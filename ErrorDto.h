#pragma once
#include <iostream>

class ErrorDto
{
private:
	bool _err;
	std::string _mensajeError;
public:
	ErrorDto();

	void setError(bool err, std::string mensajeError);

	ErrorDto getError();

	std::string getErrorMensaje();

	void limpiarErrores();

	bool hasError();

};

