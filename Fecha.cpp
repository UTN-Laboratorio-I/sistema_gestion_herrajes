#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <chrono>
#include "fecha.h"

int Fecha::getDia() {
    return _dia;
}
int Fecha::getMes() {
    return _mes;
}
int Fecha::getAnio() {
    return _anio;
}
void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}
///Queda por revisar la funcion localtime
Fecha::Fecha() {
    /*time_t t = time(NULL);
    struct tm* f = localtime(&t);
    _dia = (*f).tm_mday; // Indirecciona f y accede a tm_mday
    _mes = f->tm_mon + 1; // Indirecciona f y accede a tm_mon
    _anio = f->tm_year + 1900;
    _diaSemana = f->tm_wday;*/
}
Fecha::Fecha(int dia, int mes, int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    _diaSemana = -1;
}
std::string Fecha::toString() {
    std::string valorADevolver;
    valorADevolver = std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
    return valorADevolver;
}
std::string Fecha::getNombreDia() {
    std::string nombres[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
    if (_diaSemana >= 0 && _diaSemana <= 6) {
        return nombres[_diaSemana];
    }
    return "";
}

std::string Fecha::hoy() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Convierte el punto de tiempo actual a un objeto de tiempo local
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convierte el tiempo local a una estructura tm para extraer la fecha
    std::tm* localTime = std::localtime(&currentTime);

    // Obtén los componentes de la fecha
    _anio = localTime->tm_year + 1900;  // Añade 1900 al año
    _mes = localTime->tm_mon + 1;      // Los meses comienzan desde 0
    _dia = localTime->tm_mday;           // Día del mes

    // Imprime la fecha actual
    std::string fecha =""+ std::to_string(_anio) + "/" + std::to_string(_mes) + "/"+ std::to_string(_dia)+"";
    return fecha;
}