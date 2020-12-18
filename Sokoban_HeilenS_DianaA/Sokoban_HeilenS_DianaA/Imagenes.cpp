#include "Imagenes.h"

Imagenes::Imagenes()
{
	 tFondo = new Texture;
	fondo = new Sprite;
	tFondo->loadFromFile("ImgJuego/fondo.jpg");
	fondo->setTexture(*tFondo);
}

Sprite* Imagenes::getFondo()
{
	return fondo;
}

Sprite* Imagenes::getImagen(string nomImagen)
{
	Sprite* sp;
	for (int i = 0; i < 7; i++) {

	}
	return sp;
}
