#include "Imagenes.h"

Imagenes::Imagenes()
{
	tFondo = new Texture;
	fondo = new Sprite;
	tFondo->loadFromFile("ImgSokoban/Homero/Fondo.jpg");
	fondo->setTexture(*tFondo);
	acercaDe = new Texture;
	sAcercaDe = new Sprite;
	acercaDe->loadFromFile("ImgSokoban/Homero/AcercaDe.png");
	sAcercaDe->setTexture(*acercaDe);
	fondoMenu = new Texture;
	sFondoMenu = new Sprite;
	fondoMenu->loadFromFile("ImgSokoban/Homero/FondoMenu.png");
	sFondoMenu->setTexture(*fondoMenu);
	fGanar = new Texture;
	fondoGanar = new Sprite;
	fGanar->loadFromFile("ImgSokoban/Homero/Celebración.png");
	fondoGanar->setTexture(*fGanar);
	t = new Texture;
	s = new Sprite;
	t->loadFromFile("ImgSokoban/Vacío(adentro).jpg");
	s->setTexture(*t);
	reiniciar = new Texture;
	botonReiniciar = new Sprite;
	reiniciar->loadFromFile("ImgSokoban/Homero/Reiniciar.png");
	botonReiniciar->setTexture(*reiniciar);
	menu = new Texture;
	botonMenu = new Sprite;
	menu->loadFromFile("ImgSokoban/Homero/MenúPrincipal.png");
	botonMenu->setTexture(*menu);
	s->setPosition(200, 0);
	s->scale(1.171875, 1.171875);
	CargarImagenes();
}

Sprite* Imagenes::getFondo()
{
	return fondo;
}

Sprite* Imagenes::getFondoMenu()
{
	return sFondoMenu;
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

Sprite* Imagenes::getNivel(int n)
{
	switch (n)
	{
	case 1:
		return niveles[0]->getSprite();
		break;
	case 2:
		return niveles[1]->getSprite();
		break;
	case 3:
		return niveles[2]->getSprite();
		break;
	case 4:
		return niveles[3]->getSprite();
		break;
	}
}

Sprite* Imagenes::getAcercaDe()
{
	return sAcercaDe;
}

Sprite* Imagenes::getFondoGanar()
{
	return fondoGanar;
}

Sprite* Imagenes::getBotonReiniciar()
{
	return botonReiniciar;
}

Sprite* Imagenes::getBotonMenu()
{
	return botonMenu;
}

void Imagenes::CargarImagenes() {
	imagenes[0] = new Imagen("ImgSokoban/Homero/Caja.png", "Caja", 1, tFondo);
	imagenes[1] = new Imagen("ImgSokoban/Homero/CajaObjetivo.png", "CajaObjetivo", 1, tFondo);
	imagenes[2] = new Imagen("ImgSokoban/Homero/Muro.png", "Muro", 1, tFondo);
	imagenes[3] = new Imagen("ImgSokoban/Homero/Objetivo.png", "Objetivo", 1, tFondo);
	imagenes[4] = new Imagen("ImgSokoban/Homero/Personaje.png", "Personaje", 1, tFondo);
	imagenes[5] = new Imagen("ImgSokoban/Vacío(adentro).jg", "Vacío(adentro)", 1, tFondo);
	imagenes[6] = new Imagen("ImgSokoban/Vacío(afuera).png", "Vacío(afuera)", 1, tFondo);
	niveles[0] = new Imagen("ImgSokoban/Homero/Nivel1.png", "Nivel1", 0, tFondo);
	niveles[1] = new Imagen("ImgSokoban/Homero/Nivel2.png", "Nivel2", 0, tFondo);
	niveles[2] = new Imagen("ImgSokoban/Homero/Nivel3.png", "Nivel3", 0, tFondo);
	niveles[3] = new Imagen("ImgSokoban/Homero/Nivel4.png", "Nivel4", 0, tFondo);
}
