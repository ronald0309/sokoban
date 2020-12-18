#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
using namespace std;
using namespace sf;
class Imagen
{
private:
	Texture* texture;
	Sprite* sp;
	string nombre;
public:
	Imagen(string texture, string nombre, int tam);
	Sprite* getSprite();
	void cargarSprite(int i);
	string getNombre();
	void setNombre(string nombre);
};

