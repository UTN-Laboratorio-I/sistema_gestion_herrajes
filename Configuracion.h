#pragma once
class Configuracion
{
private:
	float _margenUtilidad;
	int _formatoFecha;
	const char* _carpetaBackUp;
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
	const char* getCarpetaBackUp();

	//void setFormatoMoneda(int opc);
	//int getFormatoMoneda();
};

