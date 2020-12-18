#include "Columna.h"

Columna::Columna()
{
	this->j = 0;
	this->casillas = NULL;
	this->sig = NULL;
	this->ant = NULL;
}

Columna::Columna(int j)
{
	this->j = j;
	this->casillas = NULL;
	this->sig = NULL;
	this->ant = NULL;
}

Columna::Columna(Casilla* casillas, Columna* sig, Columna* ant)
{
	this->j = j;
	this->casillas = casillas;
	this->sig = sig;
	this->ant = ant;
}
int Columna::getJ()
{
	return j;
}

Casilla* Columna::getCasilla()
{
	return casillas;
}

Columna* Columna::getSig()
{
	return sig;
}

Columna* Columna::getAnt()
{
	return ant;
}

void Columna::setCasilla(Casilla* casillas)
{
	this->casillas = casillas;
}

void Columna::setSig(Columna* sig)
{
	this->sig = sig;
}

void Columna::setAnt(Columna* ant)
{
	this->ant = ant;
}
