#pragma once
#include "Matriz.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Casilla.h"
#include "Imagenes.h"
using namespace sf;
using namespace std;
class Juego
{
private:
	RenderWindow* ventana1; 
	Event* evento;
	Vector2i cordenadas;
	Imagenes* imagen= new Imagenes();
	Matriz* mat;
	Casilla* casilla;
	Sprite* sprite;
	
public:
	Juego(int dimencion_x, int dimencion_y, string titulo);
	void Refrescar(int controlador_ventana, bool nuevo);
	void Dibujar(int opcion, bool nuevo);
	void CordenadasMouse();
	void Partida();
};