#pragma once
#include <iostream>
#include <stack>
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
	Imagenes* imagen = new Imagenes();
	Matriz* mat;
	Casilla* casilla;
	Sprite* sprite;
	Casilla* PosicionActual;
	stack <int> st;
	int p, k;
	int nivel;
public:
	Juego(int dimencion_x, int dimencion_y, string titulo);
	void Refrescar(int controlador_ventana, bool nuevo);
	void Dibujar(int opcion, bool nuevo);
	void CargarMenu();
	void CargarAcercaDe();
	void CargarGanar();
	
	//metodos para cargar los niveles;
	void CargarNiveles();
	void Nivel1(int i, int j);
	void Nivel2(int i, int j);
	void Nivel3(int i, int j);
	void Nivel4(int i, int j);
	void NivelSuperado();
	// metodos para repintar los niveles
	void RepintarNivel();
	//Lectura de mouse
	void CordenadasMouse();
	void ProcesarMouse(int controlador_ventana);
	void MouseNivel();
	void MouseMenu();
	void MouseAcercaDe();
	void MouseGanar();
	//Metodos de movimientos
	bool MovimientoArriba(int i, int j);
	bool MovimientoAbajo(int i, int j);
	bool MovimientoIzquierda(int i, int j);
	bool MovimientoDerecha(int i, int j);
	
};