#pragma once
class Configuracion
{
private:
	float _margenUtilidad;
	int _formatoFecha;
	int _formatoMoneda;

public:
	Configuracion();
	~Configuracion();

	void setConfiguracion();
	void setMargenUtilidad(int);
	void setFormatoFecha(int);

	float getMargenUtilidad();
	int getFormatoFecha();

	//void setFormatoMoneda(int opc);
	//int getFormatoMoneda();
};

