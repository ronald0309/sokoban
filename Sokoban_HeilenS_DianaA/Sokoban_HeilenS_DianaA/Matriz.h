#pragma once
#include <iostream>
#include "Fila.h"

using namespace std;
class Matriz {
private:
	Fila* inicio;
public:
	Matriz();
	Matriz(Fila* inicio);

	Fila* getInicio();
	void setInicio(Fila* inicio);
	void insertarFila(Fila* dato);
	void insertarColumna(Columna* dato, int i);
	void insertarCasilla(Casilla* dato, int i, int j);
	Casilla* DevolverCasilla(int i, int j);
};