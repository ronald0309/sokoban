#include "Fila.h"

Fila::Fila()
{
	this->i = 0;
	this->columnas = NULL;
	this->sig = NULL;
	this->ant = NULL;
}

Fila::Fila(int i)
{
	this->i = i;
	this->columnas = NULL;
	this->sig = NULL;
	this->ant = NULL;
}

Fila::Fila(Columna* columnas, Fila* sig, Fila* ant)
{
	this->i = i;
	this->columnas = columnas;
	this->sig = sig;
	this->ant = ant;
}
int Fila::getI()
{
	return i;
}
Columna* Fila::getColumnas()
{
	
	return columnas;
}

Fila* Fila::getSig()
{
	return sig;
}

Fila* Fila::getAnt()
{
	return ant;
}

void Fila::setColumnas(Columna* columnas)
{
	this->columnas = columnas;
}

void Fila::setSig(Fila* sig)
{
	this->sig = sig;
}

void Fila::setAnt(Fila* ant)
{
	this->ant = ant;
}

void Fila::Insertar(Columna* columnas)
{
}
