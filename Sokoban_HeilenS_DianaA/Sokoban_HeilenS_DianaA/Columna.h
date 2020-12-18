#pragma once
#include <iostream>
#include "Casilla.h"

using namespace std;
class Columna {
private:
	int j;
	Casilla* casillas;
	Columna* sig;
	Columna* ant;
public:
	Columna();
	Columna(int j);
	Columna(Casilla* casillas, Columna* sig, Columna* ant);
	Casilla* getCasilla();
	int getJ();
	Columna* getSig();
	Columna* getAnt();
	void setCasilla(Casilla* casillas);
	void setSig(Columna* sig);
	void setAnt(Columna* ant);
};