#include "Imagen.h"

Imagen::Imagen(string texture, string nombre, int tam)
{
	this->texture = new Texture;
	this->nombre = nombre;
	this->texture->loadFromFile(texture);
	cargarSprite(tam);
}

Sprite* Imagen::getSprite()
{
	return this->sp;
}

void Imagen::cargarSprite(int i)
{
	sp = new Sprite(*texture);

}
string Imagen::getNombre()
{
	return this->nombre; 
}

void Imagen::setNombre(string nombre)
{
	this->nombre = nombre;
}
