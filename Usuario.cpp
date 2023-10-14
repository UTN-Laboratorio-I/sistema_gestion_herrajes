#include "Usuario.h"
#include <iostream>

Usuario::Usuario()
    : _isAdmin(false) {}

Usuario::Usuario(const std::string& usuario, const std::string& nombre, const std::string& rol, bool isAdmin, const std::string& password)
    : _usuario(usuario), _password(password), _nombre(nombre), _rol(rol), _isAdmin(isAdmin) {}

void Usuario::setUsuario(const std::string& usuario) { _usuario = usuario; }
const std::string& Usuario::getUsuario() const { return _usuario; }

void Usuario::setPassword(const std::string& password) { _password = password; }
const std::string& Usuario::getPassword() const { return _password; }

void Usuario::setNombre(const std::string& nombre) { _nombre = nombre; }
const std::string& Usuario::getNombre() const { return _nombre; }

void Usuario::setRol(const std::string& rol) { _rol = rol; }
const std::string& Usuario::getRol() const { return _rol; }

void Usuario::setIsAdmin(bool isAdmin) { _isAdmin = isAdmin; }
bool Usuario::getIsAdmin() const { return _isAdmin; }

void Usuario::setDatosUsuario(const std::string& usuario, const std::string& nombre, const std::string& rol, bool isAdmin, const std::string& password) {
    _usuario = usuario;
    _password = password;
    _nombre = nombre;
    _rol = rol;
    _isAdmin = isAdmin;
}

Usuario Usuario::obtenerDatosUsuario() {
    return Usuario(_usuario, _nombre, _rol, _isAdmin, _password);
}

Response Usuario::crearNuevoUsuario() {
    Usuario nuevoUser;
    Response response;
    const char* nombreArchivo = "usuarios.dat";
    Archivo<Usuario> archivo(nombreArchivo);

    std::cout << "Ingrese nuevo usuario: ";
    std::cin >> nuevoUser._usuario;
    std::cout << "Ingrese password: ";
    std::cin >> nuevoUser._password;
    std::cin.ignore();  // Para manejar el '\n' en el buffer

    std::cout << "Ingrese 1 si es admin, 0 si no lo es: ";
    std::cin >> nuevoUser._isAdmin;
    std::cin.ignore();  // Para manejar el '\n' en el buffer

    std::cout << "Ingrese nombre del Usuario: ";
    std::getline(std::cin, nuevoUser._nombre);

    std::cout << "Ingrese rol del Usuario: ";
    std::getline(std::cin, nuevoUser._rol);

    bool registro = archivo.grabarRegistroArchivo(nuevoUser);

    if (registro) {
        response.setSuccess("Usuario creado con éxito.");
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
