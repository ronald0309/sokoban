#include "Casilla.h"

Casilla::Casilla()
{
	this->x = 0;
	this->y = 0;
}

Casilla::Casilla(int x, int y, string imagen)
{
	this->x = x;
	this->y = y;
	this->imagen = imagen;
}
int Casilla::getX()
{
	return x;
}

int Casilla::getY()
{
	return y;
}

string Casilla::getImagen()
{
	return imagen;
}

void Casilla::setX(int x)
{
	this->x = x;
}

void Casilla::setY(int y)
{
	this->y = y;
}

void Casilla::setImagen(string imagen)
{
	this->imagen = imagen;
}

string Casilla::toString()
{
	cout << "x= " << x << ", y= " << y << ", imagen: " << imagen;
	return string();
}


