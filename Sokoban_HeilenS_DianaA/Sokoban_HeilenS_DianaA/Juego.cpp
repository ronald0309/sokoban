#include "Juego.h"
#include "Matriz.h"

Juego::Juego(int dimencion_x, int dimencion_y, string titulo) {
	ventana1 = new RenderWindow(VideoMode(dimencion_x, dimencion_y), titulo);
	ventana1->setFramerateLimit(60);
	evento = new Event;
	
	
	while (ventana1->isOpen())
	{
		Refrescar(1, true);
		while (ventana1->pollEvent(*evento)) {
			switch (evento->type) {
			case Event::Closed:
				ventana1->close();
				exit(1);
				break;
			}
		}
	}
	Matriz* mat = new Matriz();
	int x=100, y=200;
	for (int i = 0; i < 8; i++) {
		mat->insertarFila(new Fila(i));
		for (int j = 0; j < 8; j++) {
			mat->insertarColumna(new Columna(j),i);
			mat->insertarCasilla(new Casilla(x,y, "hola"), i, j);
			y += 30;
		}
		x += 30;
		y = 200;
	}
	Casilla* casilla = NULL;
	for (int i = 0; i < 8; i++) {
		casilla = NULL;
		for (int j = 0; j < 8; j++) {
			casilla = mat->DevolverCasilla(i, j);
			if (casilla != NULL)
				casilla->toString();
			cout << endl;
		}
	}
	
}
void Juego::Refrescar(int controlador_ventana, bool nuevo = true)
{
	Dibujar(controlador_ventana, nuevo);
	while (ventana1->isOpen())
	{
		ventana1->clear();
		//ProcesarMouse(controlador_ventana);
		ventana1->draw(*imagen->getFondo());
		ventana1->display();
	}
}

void Juego::Dibujar(int opcion, bool nuevo)
{
}
void Juego::CordenadasMouse()
{
	//ubicacion de lo que selecciono
	cordenadas = Mouse::getPosition(*ventana1);
	cordenadas = (Vector2i)ventana1->mapPixelToCoords(cordenadas);
	cout << cordenadas.x << "," << cordenadas.y << endl;
}