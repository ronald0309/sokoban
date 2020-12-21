#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Imagen.h"
using namespace std;
using namespace sf;
class Imagenes {
private:
	Sprite *fondo;
	Texture* tFondo;
	Texture* fondoMenu;
	Sprite* sFondoMenu;
	Texture* t;
	Sprite* s;
	Texture* acercaDe;
	Sprite* sAcercaDe;
	Texture* fGanar;
	Sprite* fondoGanar;
	Imagen* niveles[4];

	Imagen* imagenes[7];
public:
	Imagenes();
	Sprite* getFondo();
	Sprite* getFondoMenu();
	Sprite* getImagen(string nomImagen);
	Sprite* getS();
	Sprite* getNivel(int n);
	Sprite* getAcercaDe();
	Sprite* getFondoGanar();

	void CargarImagenes();
};