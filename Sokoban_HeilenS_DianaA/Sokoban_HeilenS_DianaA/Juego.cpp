#include "Juego.h"

Juego::Juego(int dimencion_x, int dimencion_y, string titulo) {
	ventana1 = new RenderWindow(VideoMode(dimencion_x, dimencion_y), titulo);
	ventana1->setFramerateLimit(60);
	evento = new Event;
	
	mat = new Matriz();

	casilla = NULL;
	Refrescar(1, true);
	while (ventana1->isOpen())
	{
		while (ventana1->pollEvent(*evento)) {
			switch (evento->type) {
			case Event::Closed:
				ventana1->close();
				exit(1);
				break;
			}
		}
	}

}
void Juego::Refrescar(int controlador_ventana, bool nuevo = true)
{
	Dibujar(controlador_ventana, nuevo);
	//while (ventana1->isOpen())
	//{
	//	ventana1->clear();
	//	//ProcesarMouse(controlador_ventana);
	//	ventana1->draw(*imagen->getFondo());
	//	ventana1->display();
	//}
}

void Juego::Dibujar(int opcion, bool nuevo)
{
	switch (opcion)
	{
	case 1:
		Partida();
		break;
	}
}
void Juego::CordenadasMouse()
{
	//ubicacion de lo que selecciono
	cordenadas = Mouse::getPosition(*ventana1);
	cordenadas = (Vector2i)ventana1->mapPixelToCoords(cordenadas);
	cout << cordenadas.x << "," << cordenadas.y << endl;
}

void Juego::Partida()
{
	ventana1->clear();
	ventana1->draw(*imagen->getFondo());
    Texture* t = new Texture;
    Sprite* s = new Sprite;
    t->loadFromFile("ImgSokoban/Vacío(adentro).jpg");
    s->setTexture(*t);
    s->setPosition(325, 150);
    s->scale(0.7812, 0.7812);
    ventana1->draw(*s);
	for (int i = 1; i <= 8; i++) {
		casilla = NULL;
		for (int j = 1; j <= 8; j++) {
			casilla = mat->DevolverCasilla(i-1, j-1);
			if (casilla != NULL)
				casilla->toString();
			cout << endl;
			sprite = new Sprite();
			
			sprite->setPosition(casilla->getX(), casilla->getY());
            if (i == 1) { //Fila 1.
                if ((j == 3) || (j == 4) || (j == 5)) { //Si es la columna 3, 4, ó 5
                    sprite = imagen->getImagen("Muro");
                    //matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
                    casilla->setImagen("Muro");
                }
                else {
                    sprite = imagen->getImagen("Vacío(afuera)");
                    casilla->setImagen("Vacío(afuera)");
                }
            }
            else {
                if (i == 2) { //Fila 2.
                    if ((j == 3) || (j == 5)) { //Si es la columna 3 ó 5
                        sprite = imagen->getImagen("Muro");
                        casilla->setImagen("Muro");
                        //matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
                    }else
                    if (j == 4) { //Si es la columna 4
                        sprite = imagen->getImagen("Objetivo");
                        casilla->setImagen("Objetivo");
                        //matrizS[i][j] = 4; //se le asigna la imagen del objetivo que es el número 4.
                    }
                    else {
                        sprite = imagen->getImagen("Vacío(afuera)");
                        casilla->setImagen("Vacío(afuera)");
                    }
                }
                else {
                    if (i == 3) { //Fila 3.

                        if ((j == 3) || (j == 5) || (j == 6) || (j == 7) || (j == 8)) {
                           // matrizS[i][j] = 1;
                            sprite = imagen->getImagen("Muro");
                            casilla->setImagen("Muro");
                        }else
                        if (j == 4) { //Si es la columna 4
                            sprite = imagen->getImagen("Vacío(adentro)");
                            casilla->setImagen("Vacío(adentro)");
                           // matrizS[i][j] = 7; //se le asigna la imagen del vacío(adentro) que es el número 7.
                        }
                        else {
                            sprite = imagen->getImagen("Vacío(afuera)");
                            casilla->setImagen("Vacío(afuera)");
                        }
                    }
                    else {
                        if (i == 4) { //Fila 4.
                            if ((j == 1) || (j == 2) || (j == 3) || (j == 8)) {
                                sprite = imagen->getImagen("Muro");
                                casilla->setImagen("Muro");
                               // matrizS[i][j] = 1;
                            }else
                            if (j == 7) {
                               // matrizS[i][j] = 4;
                                sprite = imagen->getImagen("Objetivo");
                                casilla->setImagen("Objetivo");
                            }else
                            if ((j == 4) || (j == 6)) { //Si es la columna 4 ó 6
                                sprite = imagen->getImagen("Caja");
                                casilla->setImagen("Caja");
                              //  matrizS[i][j] = 3; //se le asigna la imagen de la caja que es el número 3.
                            }else
                            if (j == 5) {
                                sprite = imagen->getImagen("Vacío(adentro)");
                                casilla->setImagen("Vacío(adentro)");
                               // matrizS[i][j] = 7;
                            }
                            else {
                                sprite = imagen->getImagen("Vacío(afuera)");
                                casilla->setImagen("Vacío(afuera)");
                            }
                        }
                        else {
                            if (i == 5) { //Fila 5.
                                if ((j == 1) || (j == 6) || (j == 7) || (j == 8)) {
                                    sprite = imagen->getImagen("Muro");
                                    casilla->setImagen("Muro");
                                  //  matrizS[i][j] = 1;
                                }else
                                if (j == 2) {
                                    sprite = imagen->getImagen("Objetivo");
                                    casilla->setImagen("Objetivo");
                                   // matrizS[i][j] = 4;
                                }else
                                if (j == 4) {
                                    sprite = imagen->getImagen("Caja");
                                    casilla->setImagen("Caja");
                                   // matrizS[i][j] = 3;
                                }else
                                if (j == 5) { //Si es la columna 5
                                    sprite = imagen->getImagen("Personaje");
                                    casilla->setImagen("Personaje");
                                  //  matrizS[i][j] = 2; //se le asigna la imagen del personaje que es el número 2. 
                                   // Singlenton.getInstance().x = i; //Obtiene la posicíón inicial de i y j.
                                   // Singlenton.getInstance().y = j;
                                }else
                                if (j == 3) {
                                    sprite = imagen->getImagen("Vacío(adentro)");
                                    casilla->setImagen("Vacío(adentro)");
                                   // matrizS[i][j] = 7;
                                }
                                else {
                                    sprite = imagen->getImagen("Vacío(afuera)");
                                    casilla->setImagen("Vacío(afuera)");
                                }
                            }
                            else {
                                if (i == 6) { //Fila 6.

                                    if ((j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 6)) {
                                        sprite = imagen->getImagen("Muro");
                                        casilla->setImagen("Muro");
                                      //  matrizS[i][j] = 1;
                                    }else
                                    if (j == 5) {
                                        sprite = imagen->getImagen("Caja");
                                        casilla->setImagen("Caja");
                                       // matrizS[i][j] = 3;
                                    }
                                    else {
                                        sprite = imagen->getImagen("Vacío(afuera)");
                                        casilla->setImagen("Vacío(afuera)");
                                    }
                                }
                                else {
                                    if (i == 7) { //Fila 7.
                                        if ((j == 4) || (j == 6)) {
                                            sprite = imagen->getImagen("Muro");
                                            casilla->setImagen("Muro");
                                          //  matrizS[i][j] = 1;
                                        }else
                                        if (j == 5) {
                                           // matrizS[i][j] = 4;
                                            sprite = imagen->getImagen("Objetivo");
                                            casilla->setImagen("Objetivo");
                                        }
                                        else {
                                            sprite = imagen->getImagen("Vacío(afuera)");
                                            casilla->setImagen("Vacío(afuera)");
                                        }
                                    }
                                    else {
                                        if (i == 8) { //Fila 8.
                                            if ((j == 4) || (j == 5) || (j == 6)) {
                                                sprite = imagen->getImagen("Muro");
                                                casilla->setImagen("Muro");
                                             //   matrizS[i][j] = 1;
                                            }
                                            else {
                                                sprite = imagen->getImagen("Vacío(afuera)");
                                                casilla->setImagen("Vacío(afuera)");
                                            }
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            }
            sprite->setPosition(casilla->getX(), casilla->getY());
			ventana1->draw(*sprite);
		}
	}
    for (int i = 1; i <= 8; i++) {
        casilla = NULL;
        for (int j = 1; j <= 8; j++) {
            casilla = mat->DevolverCasilla(i - 1, j - 1);
            if (casilla != NULL)
                casilla->toString();
            cout << endl;
        }
    }
	ventana1->display();
}
