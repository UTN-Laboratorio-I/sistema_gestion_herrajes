#pragma once
class Caja
{
private:
	float _dineroTotal;

public:
	Caja();
	~Caja();

	//Response<Caja> gestionarCaja(float monto, char tipoTransaccion);

	float getDineroTotal();
	void setDineroTotal(float dineroTotal);

	Caja getEstadoCaja();

};

