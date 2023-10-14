#pragma once
#include <string>
#include <vector>
#include "ResponseDto.h"
#include "Archivo.h"

class Usuario {
private:
    std::string _usuario;
    std::string _password;
    std::string _nombre;
    std::string _rol;
    bool _isAdmin;

public:
    Usuario();
    Usuario(const std::string& usuario, const std::string& nombre, const std::string& rol, bool isAdmin, const std::string& password = "");

    void setUsuario(const std::string& usuario);
    const std::string& getUsuario() const;
    void setPassword(const std::string& password);
    const std::string& getPassword() const;
    void setNombre(const std::string& nombre);
    const std::string& getNombre() const;
    void setIsAdmin(bool isAdmin);
    bool getIsAdmin() const;
    void setRol(const std::string& rol);
    const std::string& getRol() const;
    void setDatosUsuario(const std::string& usuario, const std::string& nombre, const std::string& rol, bool isAdmin, const std::string& password);

    Usuario obtenerDatosUsuario();

    Response crearNuevoUsuario();
    std::vector<Usuario> listarUsuarios();
};
