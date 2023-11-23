#pragma once
class Configuracion
{
private:
	float _margenUtilidad;
	int _formatoFecha;
	string _carpetaBackUp;
	int _formatoMoneda;

public:
	Configuracion();
	~Configuracion();

	void setConfiguracion();
	void setMargenUtilidad(int);
	void setFormatoFecha(int);

	float getMargenUtilidad();
	int getFormatoFecha();

	void setCarpetaBackUp(const char*);
	string getCarpetaBackUp();

	//void setFormatoMoneda(int opc);
	//int getFormatoMoneda();
};

