#include "Imagenes.h"

Imagenes::Imagenes()
{
	tFondo = new Texture;
	fondo = new Sprite;
	tFondo->loadFromFile("ImgJuego/fondo.jpg");
	fondo->setTexture(*tFondo);
	t = new Texture;
	s = new Sprite;
	t->loadFromFile("ImgSokoban/Vacío(adentro).jpg");
	s->setTexture(*t);
	s->setPosition(200, 0);
	s->scale(1.171875, 1.171875);
	CargarImagenes();
}

Sprite* Imagenes::getFondo()
{
	return fondo;
}

Sprite* Imagenes::getImagen(string nomImagen)
{
	Sprite* sp = NULL;
	for (int i = 0; i < 7; i++) {
		if (imagenes[i]->getNombre() == nomImagen)
			sp=imagenes[i]->getSprite();
	}
	return sp;
}

Sprite* Imagenes::getS()
{
	return s;
}

void Imagenes::CargarImagenes() {
	imagenes[0] = new Imagen("ImgSokoban/Homero/Caja.png", "Caja", 1, tFondo);
	imagenes[1] = new Imagen("ImgSokoban/Homero/CajaObjetivo.jpg", "CajaObjetivo", 1, tFondo);
	imagenes[2] = new Imagen("ImgSokoban/Homero/Muro.png", "Muro", 1, tFondo);
	imagenes[3] = new Imagen("ImgSokoban/Homero/Objetivo.png", "Objetivo", 1, tFondo);
	imagenes[4] = new Imagen("ImgSokoban/Homero/Personaje.png", "Personaje", 1, tFondo);
	imagenes[5] = new Imagen("ImgSokoban/Vacío(adentro).jpg", "Vacío(adentro)", 1, tFondo);
	imagenes[6] = new Imagen("ImgSokoban/Vacío(afuera).png", "Vacío(afuera)", 1, tFondo);
}
