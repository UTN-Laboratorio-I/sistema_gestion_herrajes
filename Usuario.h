#pragma once
#include <string>
#include <vector>
#include "ResponseDto.h"
#include "Archivo.h"

class Usuario {
private:
    char _usuario[30];
    char _password[30];
    char _nombre[50];
    char _rol[30];
    bool _isAdmin;

public:
    Usuario();
    Usuario(char* usuario, char* nombre, char* rol, bool isAdmin, const char* password = "");

    void setUsuario(char* usuario);
    const char* getUsuario() const;
    void setPassword(char* password);
    const char* getPassword() const;
    void setNombre(char* nombre);
    const char* getNombre() const;
    void setIsAdmin(bool isAdmin);
    bool getIsAdmin() const;
    void setRol(char* rol);
    const char* getRol() const;
    void setDatosUsuario(char* usuario, char* nombre, char* rol, bool isAdmin, char* password);

    Response<Usuario> crearNuevoUsuario();
    std::vector<Usuario> listarUsuarios();
};
