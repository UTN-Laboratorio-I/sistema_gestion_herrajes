#include "Usuario.h"
#include <iostream>
#include <cstring>

Usuario::Usuario()
    : _isAdmin(false) {
    std::memset(_usuario, 0, sizeof(_usuario));
    std::memset(_password, 0, sizeof(_password));
    std::memset(_nombre, 0, sizeof(_nombre));
    std::memset(_rol, 0, sizeof(_rol));
}

Usuario::Usuario(char* usuario, char* nombre, char* rol, bool isAdmin, const char* password) {
    std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
    std::strncpy(_password, password, sizeof(_password) - 1);
    std::strncpy(_nombre, nombre, sizeof(_nombre) - 1);
    std::strncpy(_rol, rol, sizeof(_rol) - 1);
    _isAdmin = isAdmin;
}

void Usuario::setUsuario(char* usuario) {
    std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
}

const char* Usuario::getUsuario() const {
    return _usuario;
}

void Usuario::setPassword(char* password) {
    std::strncpy(_password, password, sizeof(_password) - 1);
}

const char* Usuario::getPassword() const {
    return _password;
}

void Usuario::setNombre(char* nombre) {
    std::strncpy(_nombre, nombre, sizeof(_nombre) - 1);
}

const char* Usuario::getNombre() const {
    return _nombre;
}

void Usuario::setRol(char* rol) {
    std::strncpy(_rol, rol, sizeof(_rol) - 1);
}

const char* Usuario::getRol() const {
    return _rol;
}

void Usuario::setIsAdmin(bool isAdmin) {
    _isAdmin = isAdmin;
}

bool Usuario::getIsAdmin() const {
    return _isAdmin;
}

void Usuario::setDatosUsuario(char* usuario, char* nombre, char* rol, bool isAdmin, char* password) {
    std::strncpy(_usuario, usuario, sizeof(_usuario) - 1);
    std::strncpy(_password, password, sizeof(_password) - 1);
    std::strncpy(_nombre, nombre, sizeof(_nombre) - 1);
    std::strncpy(_rol, rol, sizeof(_rol) - 1);
    _isAdmin = isAdmin;
}

Response<Usuario> Usuario::crearNuevoUsuario() {
    Usuario nuevoUser;
    Response<Usuario> response;

    const char* nombreArchivo = "usuarios.dat";
    Archivo<Usuario> archivo(nombreArchivo);

    std::cout << "Ingrese nuevo usuario: ";
    std::cin.ignore();  
    std::cin.getline(nuevoUser._usuario, sizeof(nuevoUser._usuario));

    std::cout << "Ingrese password: ";
    std::cin.getline(nuevoUser._password, sizeof(nuevoUser._password));

    std::cout << "Ingrese 1 si es admin, 0 si no lo es: ";
    std::cin >> nuevoUser._isAdmin;
    std::cin.ignore();  

    std::cout << "Ingrese nombre del Usuario: ";
    std::cin.getline(nuevoUser._nombre, sizeof(nuevoUser._nombre));

    std::cout << "Ingrese rol del Usuario: ";
    std::cin.getline(nuevoUser._rol, sizeof(nuevoUser._rol));

    bool registro = archivo.grabarRegistroArchivo(nuevoUser);

    if (registro) {
        response.setSuccess("Usuario creado con éxito.", nuevoUser);
    }
    else {
        response.setFailure("Error al crear usuario.");
    }

    return response;
}

std::vector<Usuario> Usuario::listarUsuarios() {
    std::vector<Usuario> usuarios;
    const char* nombreArchivo = "usuarios.dat";
    Archivo<Usuario> archivo(nombreArchivo);

    usuarios = archivo.listarRegistroArchivo();
    return usuarios;
}
