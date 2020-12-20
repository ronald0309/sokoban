#include "Imagen.h"

Imagen::Imagen(string texture, string nombre, int tam, Texture* text)
{
	this->texture = new Texture;
	this->nombre = nombre;
	this->texture->loadFromFile(texture);
	cargarSprite(tam, text);
}

Sprite* Imagen::getSprite()
{
	return this->sp;
}

void Imagen::cargarSprite(int i, Texture* text)
{
	sp = new Sprite(*texture);
	if (i == 1) {
		sp->setScale(100.f / text->getSize().x, 100.f / text->getSize().y);
		sp->setScale(0.117, 0.117);
	}

}
string Imagen::getNombre()
{
	return this->nombre; 
}

void Imagen::setNombre(string nombre)
{
	this->nombre = nombre;
}
