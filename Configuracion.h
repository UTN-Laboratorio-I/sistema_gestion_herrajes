#pragma once
class Configuracion
{
private:
	int _id;
	float _margenUtilidad;
	int _formatoFecha;
	int _formatoMoneda;

public:
	Configuracion();
	~Configuracion();

	void setConfiguracion();
	void setId(int);
	int getId();
	void setMargenUtilidad(float);
	void setFormatoFecha(int);

	float getMargenUtilidad();
	int getFormatoFecha();

	//void setFormatoMoneda(int opc);
	//int getFormatoMoneda();
};

