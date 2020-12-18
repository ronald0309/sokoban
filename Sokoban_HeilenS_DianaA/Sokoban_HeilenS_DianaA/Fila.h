#pragma once
#include <iostream>
#include "Columna.h"
using namespace std;

class Fila {
private:
	int i;
	Columna* columnas;
	Fila* sig;
	Fila* ant;
public:
	Fila();
	Fila(int i);
	Fila(Columna* columnas, Fila* sig, Fila* ant);
	Columna* getColumnas();
	int getI();
	Fila* getSig();
	Fila* getAnt();
	void setColumnas(Columna* columnas);
	void setSig(Fila* sig);
	void setAnt(Fila* ant);
	void Insertar(Columna* columnas);
};