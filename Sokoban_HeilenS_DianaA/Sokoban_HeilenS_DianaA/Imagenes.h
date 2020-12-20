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
	Texture* t;
	Sprite* s;
	Imagen* imagenes[7];
public:
	Imagenes();
	Sprite* getFondo();
	Sprite* getImagen(string nomImagen);
	Sprite* getS();
	void CargarImagenes();
};