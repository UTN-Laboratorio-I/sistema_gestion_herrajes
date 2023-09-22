#pragma once
#include <string>
using namespace std;
class Categoria
{
private:
	int id;
	int TipoCategoria;
	char Nombre[20];
public:
	//Id:
	void setId();
	int getId(string nombre);

	void setTipoCategoria(string tipoCategoria);
	string getTipoCategoria();

	void setNombre(string nombre);
	string getNombre(int id);

	void createNewCategoria(string tipoCategoria, string nombreCategoria);

	void asignarCategoriaAEntidad(string entidad, string categoria);
};

