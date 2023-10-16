#pragma once
#include "Sistema.h"
#include <iostream>
class AdminConfig
{
private:
	Sistema* _sistema;
	string _nombreModulo;
public:
	AdminConfig(Sistema* sistema);
	~AdminConfig();

	bool moduloConfigActivo();

	void moduloConfigSalir();

	void administrarModuloConfig();


};

