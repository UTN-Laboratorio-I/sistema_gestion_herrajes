#include "ErrorDto.h"

ErrorDto::ErrorDto() { _err = false; _mensajeError = ""; }

/// <summary>
/// Setea un nuevo error.
/// </summary>
/// <param name="err"></param>
/// <param name="mensajeError"></param>
void ErrorDto::setError(bool err, std::string mensajeError) 
{
	_err = err;
	_mensajeError = mensajeError;
}

/// <summary>
/// 
/// </summary>
/// <returns>Retorna objeto Error</returns>
ErrorDto ErrorDto::getError() { return *this; }

/// <summary>
/// Obtiene el mensaje de error
/// </summary>
/// <returns>mensajeError</returns>
std::string ErrorDto::getErrorMensaje() { return _mensajeError; }

/// <summary>
/// Se limpian errores
/// </summary>
void ErrorDto::limpiarErrores()
{
	_err = false;
	_mensajeError = "";
}

bool ErrorDto::hasError() { return _err; }
