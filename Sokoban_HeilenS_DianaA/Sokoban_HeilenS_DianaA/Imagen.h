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
	Imagen(string texture, string nombre, int tam, Texture* text);
	Sprite* getSprite();
	void cargarSprite(int i, Texture*);
	string getNombre();
	void setNombre(string nombre);
};

