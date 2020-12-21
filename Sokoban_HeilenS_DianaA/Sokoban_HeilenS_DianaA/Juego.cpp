#include "Juego.h"


Juego::Juego(int dimencion_x, int dimencion_y, string titulo) {
	ventana1 = new RenderWindow(VideoMode(dimencion_x, dimencion_y), titulo);
	ventana1->setFramerateLimit(60);
	evento = new Event;
	nivel = 1;
	mat = new Matriz();
	PosicionActual = NULL;
	casilla = NULL;
	
	Refrescar(0, true);
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
	while (ventana1->isOpen())
	{
		ProcesarMouse(controlador_ventana);
	}
}
void Juego::Dibujar(int opcion, bool nuevo)
{
	switch (opcion)
	{
	case 0:
		CargarMenu();
		break;

	case 1:
		CargarNiveles();
		RepintarNivel();
		break;

	case 2:
		CargarAcercaDe();
		break;

	case 3:
		CargarGanar();
		break;
	}
}
void Juego::CargarMenu()
{
	ventana1->clear();
	ventana1->draw(*imagen->getFondoMenu());
	ventana1->display();
}
void Juego::CargarAcercaDe()
{
	ventana1->clear();
	ventana1->draw(*imagen->getAcercaDe());
	ventana1->display();
}
void Juego::CargarGanar()
{
	ventana1->clear();
	ventana1->draw(*imagen->getFondoGanar());
	ventana1->display();
}
void Juego::CordenadasMouse()
{
	//ubicacion de lo que selecciono
	cordenadas = Mouse::getPosition(*ventana1);
	cordenadas = (Vector2i)ventana1->mapPixelToCoords(cordenadas);
	cout << cordenadas.x << "," << cordenadas.y << endl;
}
void Juego::ProcesarMouse(int controlador_ventana)
{
	switch (controlador_ventana)
	{
	case 0:
		MouseMenu();
		break;
	case 1:
		MouseNivel();
		break;

	case 2:
		MouseAcercaDe();
		break;

	case 3:
		MouseGanar();
		break;
	}
}
void Juego::MouseNivel()
{
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				
				if ((cordenadas.x >= PosicionActual->getX()) && (cordenadas.x <= (PosicionActual->getX() + 60)) && (cordenadas.y >= PosicionActual->getY() + 60) && (cordenadas.y <= (PosicionActual->getX() + 120))) {
					if (MovimientoAbajo(p, k)) {//abajo
						cout << "Entro";
						RepintarNivel();
						NivelSuperado();
					}
				}else
				if ((cordenadas.x >= PosicionActual->getX()) && (cordenadas.x <= (PosicionActual->getX() + 60)) && (cordenadas.y >= PosicionActual->getY() - 60) && (cordenadas.y <= (PosicionActual->getX()))) {
					if (MovimientoArriba(p, k)) {//arriba
						cout << "holamundo";
						NivelSuperado();
						RepintarNivel();

					}
				}
				if ((cordenadas.x >= PosicionActual->getX() + 60) && (cordenadas.x <= (PosicionActual->getX() + 120)) && (cordenadas.y >= PosicionActual->getY()) && (cordenadas.y <= (PosicionActual->getX() + 60))) {
					if (MovimientoDerecha(p, k)) {
						RepintarNivel();
						NivelSuperado();
					}
				}
				if ((cordenadas.x >= PosicionActual->getX() - 60) && (cordenadas.x <= (PosicionActual->getX())) && (cordenadas.y >= PosicionActual->getY()) && (cordenadas.y <= (PosicionActual->getX() + 60))) {
					if (MovimientoIzquierda(p, k)) {
						RepintarNivel();
						NivelSuperado();
					}
				}

			}
			break;
		}
	}
}
void Juego::MouseMenu()
{
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 226) && (cordenadas.x <= 667) && (cordenadas.y >= 257) && (cordenadas.y <= 343)) {
					Refrescar(1);
				}
				if ((cordenadas.x >= 224) && (cordenadas.x <= 666) && (cordenadas.y >= 360) && (cordenadas.y <= 446)) {
					
				}
				if ((cordenadas.x >= 224) && (cordenadas.x <= 666) && (cordenadas.y >= 466) && (cordenadas.y <= 552)) {
					Refrescar(2);
				}
				
				
			}
			break;
		}
	}
}
void Juego::MouseAcercaDe()
{
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 837) && (cordenadas.x <= 960) && (cordenadas.y >= 518) && (cordenadas.y <= 572)) {
					Refrescar(0);
				}
			}
			break;
		}
	}
}
void Juego::MouseGanar()
{
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 658) && (cordenadas.x <= 962) && (cordenadas.y >= 182) && (cordenadas.y <= 303)) {
					Refrescar(1);
				}
			}
			break;
		}
	}
}
/*void Juego::PintarPartida()
{
	ventana1->clear();
	ventana1->draw(*imagen->getFondo());
	ventana1->draw(*imagen->getS());
	for (int i = 1; i <= 8; i++) {
		casilla = NULL;
		for (int j = 1; j <= 8; j++) {
			casilla = mat->DevolverCasilla(i - 1, j - 1);
			if (casilla != NULL)
				casilla->toString();
			cout << endl;
			sprite = new Sprite();
			switch (nivel)
			{
			case 1:
				Nivel1(i, j);
				break;
			case 2:
				Nivel2(i, j);
				break;
			case 3:
				Nivel3(i, j);
				break;
			case 4:
				Nivel4(i, j);
				break;
			}
			Nivel1(i, j);
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
}*/
void Juego::CargarNiveles() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			casilla = mat->DevolverCasilla(i, j);
			sprite = new Sprite();
			switch (nivel)
			{
			case 1:
				Nivel1(i, j);
				break;
			case 2:
				Nivel2(i, j);
				break;
			case 3:
				Nivel3(i, j);
				break;
			case 4:
				Nivel4(i, j);
				break;
			}

		}
	}

}
void Juego::Nivel1(int i, int j) {
	if (i == 0) {
		sprite = imagen->getImagen("Vacío(afuera)");
		casilla->setImagen("Vacío(afuera)");
	}
	else
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
				}
				else
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
					}
					else
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
						}
						else
							if (j == 7) {
								// matrizS[i][j] = 4;
								sprite = imagen->getImagen("Objetivo");
								casilla->setImagen("Objetivo");
							}
							else
								if ((j == 4) || (j == 6)) { //Si es la columna 4 ó 6
									sprite = imagen->getImagen("Caja");
									casilla->setImagen("Caja");
									//  matrizS[i][j] = 3; //se le asigna la imagen de la caja que es el número 3.
								}
								else
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
							}
							else
								if (j == 2) {
									sprite = imagen->getImagen("Objetivo");
									casilla->setImagen("Objetivo");
									// matrizS[i][j] = 4;
								}
								else
									if (j == 4) {
										sprite = imagen->getImagen("Caja");
										casilla->setImagen("Caja");
										// matrizS[i][j] = 3;
									}
									else
										if (j == 5) { //Si es la columna 5
											sprite = imagen->getImagen("Personaje");
											casilla->setImagen("Personaje");
											PosicionActual = casilla;
											p = i;
											k = j;
											//  matrizS[i][j] = 2; //se le asigna la imagen del personaje que es el número 2. 
											 // Singlenton.getInstance().x = i; //Obtiene la posicíón inicial de i y j.
											 // Singlenton.getInstance().y = j;
										}
										else
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
								}
								else
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
									}
									else
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
									else {
										if (i == 9) {
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
}
void Juego::Nivel2(int i, int j) {
	//Singlenton.getInstance().movimientos = 89;

	if (i == 0) { //Fila 0.
		sprite = imagen->getImagen("Vacío(afuera)");
		casilla->setImagen("Vacío(afuera)");
	}
	else {
		if (i == 1) { //Fila 1.
			if ((j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5)) {
				//matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
				sprite = imagen->getImagen("Muro");
				casilla->setImagen("Muro");
			}
			else {
				sprite = imagen->getImagen("Vacío(afuera)");
				casilla->setImagen("Vacío(afuera)");
			}
		}
		else {
			if (i == 2) { //Fila 2.
				if ((j == 1) || (j == 5)) {
					//matrizS[i][j] = 1;
					sprite = imagen->getImagen("Muro");
					casilla->setImagen("Muro");
				}else
				if ((j == 2) || (j == 3) || (j == 4)) {
					//matrizS[i][j] = 7;
					sprite = imagen->getImagen("Vacío(adentro)");
					casilla->setImagen("Vacío(adentro)");
				}
				else {
					sprite = imagen->getImagen("Vacío(afuera)");
					casilla->setImagen("Vacío(afuera)");
				}
			}
			else {
				if (i == 3) { //Fila 3.
					if ((j == 1) || (j == 5) || (j == 7) || (j == 8) || (j == 9)) {
						// matrizS[i][j] = 1;
						sprite = imagen->getImagen("Muro");
						casilla->setImagen("Muro");
					}else
					if (j == 3) {
						//matrizS[i][j] = 3;
						sprite = imagen->getImagen("Caja");
						casilla->setImagen("Caja");
					}else
					if ((j == 2) || (j == 4)) {
						//matrizS[i][j] = 7;
						sprite = imagen->getImagen("Vacío(adentro)");
						casilla->setImagen("Vacío(adentro)");
					}
					else {
						sprite = imagen->getImagen("Vacío(afuera)");
						casilla->setImagen("Vacío(afuera)");
					}
				}
				else {
					if (i == 4) { //Fila 4.
						if ((j == 1) || (j == 5) || (j == 7) || (j == 9)) {
							//matrizS[i][j] = 1;
							sprite = imagen->getImagen("Muro");
							casilla->setImagen("Muro");
						}else
						if (j == 3) {
							// matrizS[i][j] = 3;
							sprite = imagen->getImagen("Caja");
							casilla->setImagen("Caja");
						}else
						if (j == 4) {
							//matrizS[i][j] = 2;
							//Singlenton.getInstance().x = i;
							//Singlenton.getInstance().y = j;
							sprite = imagen->getImagen("Personaje");
							casilla->setImagen("Personaje");
							PosicionActual = casilla;
							p = i;
							k = j;
						}else
						if (j == 8) {
							//matrizS[i][j] = 4;
							sprite = imagen->getImagen("Objetivo");
							casilla->setImagen("Objetivo");
						}else
						if (j == 2) {
							//matrizS[i][j] = 7;
							sprite = imagen->getImagen("Vacío(adentro)");
							casilla->setImagen("Vacío(adentro)");
						}
						else {
							sprite = imagen->getImagen("Vacío(afuera)");
							casilla->setImagen("Vacío(afuera)");
						}
					}
					else {
						if (i == 5) { //Fila 5.
							if ((j == 1) || (j == 2) || (j == 3) || (j == 5) || (j == 6) || (j == 7) || (j == 9)) {
								//matrizS[i][j] = 1;
								sprite = imagen->getImagen("Muro");
								casilla->setImagen("Muro");
							}else
							if (j == 4) {
								//matrizS[i][j] = 3;
								sprite = imagen->getImagen("Caja");
								casilla->setImagen("Caja");
							}else
							if (j == 8) {
								//matrizS[i][j] = 4;
								sprite = imagen->getImagen("Objetivo");
								casilla->setImagen("Objetivo");
							}
							else {
								sprite = imagen->getImagen("Vacío(afuera)");
								casilla->setImagen("Vacío(afuera)");
							}
						}
						else {
							if (i == 6) { //Fila 6.
								if ((j == 2) || (j == 3) || (j == 9)) {
									//matrizS[i][j] = 1;
									sprite = imagen->getImagen("Muro");
									casilla->setImagen("Muro");
								}else
								if (j == 8) {
									//matrizS[i][j] = 4;
									sprite = imagen->getImagen("Objetivo");
									casilla->setImagen("Objetivo");
								}else
								if ((j == 4) || (j == 5) || (j == 6) || (j == 7)) {
									//matrizS[i][j] = 7;
									sprite = imagen->getImagen("Vacío(adentro)");
									casilla->setImagen("Vacío(adentro)");
								}
								else {
									sprite = imagen->getImagen("Vacío(afuera)");
									casilla->setImagen("Vacío(afuera)");
								}
							}
							else {
								if (i == 7) { //Fila 7.
									if ((j == 2) || (j == 6) || (j == 9)) {
										//matrizS[i][j] = 1;
										sprite = imagen->getImagen("Muro");
										casilla->setImagen("Muro");
									}else
									if ((j == 3) || (j == 4) || (j == 5) || (j == 7) || (j == 8)) {
										//matrizS[i][j] = 7;
										sprite = imagen->getImagen("Vacío(adentro)");
										casilla->setImagen("Vacío(adentro)");
									}
									else {
										sprite = imagen->getImagen("Vacío(afuera)");
										casilla->setImagen("Vacío(afuera)");
									}
								}
								else {
									if (i == 8) { //Fila 8.
										if ((j == 2) || (j == 6) || (j == 7) || (j == 8) || (j == 9)) {
											//matrizS[i][j] = 1;
											sprite = imagen->getImagen("Muro");
											casilla->setImagen("Muro");
										}else
										if ((j == 3) || (j == 4) || (j == 5)) {
											//matrizS[i][j] = 7;
											sprite = imagen->getImagen("Vacío(adentro)");
											casilla->setImagen("Vacío(adentro)");
										}
										else {
											sprite = imagen->getImagen("Vacío(afuera)");
											casilla->setImagen("Vacío(afuera)");
										}
									}
									else {
										if (i == 9) { //Fila 9.
											if ((j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6)) {
												//matrizS[i][j] = 1;
												sprite = imagen->getImagen("Muro");
												casilla->setImagen("Muro");
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
		}
	}
}
void Juego::Nivel3(int i, int j) {
	//Singlenton.getInstance().movimientos = 33;

	if (i == 0) { //Fila 0.
		sprite = imagen->getImagen("Vacío(afuera)");
		casilla->setImagen("Vacío(afuera)");
	}
	else {
		if (i == 1) { //Fila 1.
			if ((j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5)) {
				//matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
				sprite = imagen->getImagen("Muro");
				casilla->setImagen("Muro");
			}
			else {
				sprite = imagen->getImagen("Vacío(afuera)");
				casilla->setImagen("Vacío(afuera)");
			}
		}
		else {
			if (i == 2) { //Fila 2.
				if ((j == 1) || (j == 2) || (j == 5)) {
					//matrizS[i][j] = 1;
					sprite = imagen->getImagen("Muro");
					casilla->setImagen("Muro");
				}else
				if ((j == 3) || (j == 4)) {
					//matrizS[i][j] = 7;
					sprite = imagen->getImagen("Vacío(adentro)");
					casilla->setImagen("Vacío(adentro)");
				}
				else {
					sprite = imagen->getImagen("Vacío(afuera)");
					casilla->setImagen("Vacío(afuera)");
				}
			}
			else {
				if (i == 3) { //Fila 3.
					if ((j == 1) || (j == 5)) {
						//matrizS[i][j] = 1;
						sprite = imagen->getImagen("Muro");
						casilla->setImagen("Muro");
					}else
					if (j == 3) {
						//matrizS[i][j] = 3;
						sprite = imagen->getImagen("Caja");
						casilla->setImagen("Caja");
					}else
					if (j == 2) {
						//matrizS[i][j] = 2;
						//Singlenton.getInstance().x = i;
						//Singlenton.getInstance().y = j;
						sprite = imagen->getImagen("Personaje");
						casilla->setImagen("Personaje");
						PosicionActual = casilla;
						p = i;
						k = j;
					}else
					if (j == 4) {
						//matrizS[i][j] = 7;
						sprite = imagen->getImagen("Vacío(adentro)");
						casilla->setImagen("Vacío(adentro)");
					}
					else {
						sprite = imagen->getImagen("Vacío(afuera)");
						casilla->setImagen("Vacío(afuera)");
					}
				}
				else {
					if (i == 4) { //Fila 4.
						if ((j == 1) || (j == 2) || (j == 5) || (j == 6)) {
							//matrizS[i][j] = 1;
							sprite = imagen->getImagen("Muro");
							casilla->setImagen("Muro");
						}else
						if (j == 3) {
							//matrizS[i][j] = 3;
							sprite = imagen->getImagen("Caja");
							casilla->setImagen("Caja");
						}else
						if (j == 4) {
							//matrizS[i][j] = 7;
							sprite = imagen->getImagen("Vacío(adentro)");
							casilla->setImagen("Vacío(adentro)");
						}
						else {
							sprite = imagen->getImagen("Vacío(afuera)");
							casilla->setImagen("Vacío(afuera)");
						}
					}
					else {
						if (i == 5) { //Fila 5.
							if ((j == 1) || (j == 2) || (j == 6)) {
								//matrizS[i][j] = 1;
								sprite = imagen->getImagen("Muro");
								casilla->setImagen("Muro");
							}else
							if (j == 4) {
								//matrizS[i][j] = 3;
								sprite = imagen->getImagen("Caja");
								casilla->setImagen("Caja");
							}else
							if ((j == 3) || (j == 5)) {
								//matrizS[i][j] = 7;
								sprite = imagen->getImagen("Vacío(adentro)");
								casilla->setImagen("Vacío(adentro)");
							}
							else {
								sprite = imagen->getImagen("Vacío(afuera)");
								casilla->setImagen("Vacío(afuera)");
							}
						}
						else {
							if (i == 6) { //Fila 6.
								if ((j == 1) || (j == 6)) {
									//matrizS[i][j] = 1;
									sprite = imagen->getImagen("Muro");
									casilla->setImagen("Muro");
								}else
								if (j == 3) {
									//matrizS[i][j] = 3;
									sprite = imagen->getImagen("Caja");
									casilla->setImagen("Caja");
								}else
								if (j == 2) {
									//matrizS[i][j] = 4;
									sprite = imagen->getImagen("Objetivo");
									casilla->setImagen("Objetivo");
								}else
								if ((j == 4) || (j == 5)) {
									//matrizS[i][j] = 7;
									sprite = imagen->getImagen("Vacío(adentro)");
									casilla->setImagen("Vacío(adentro)");
								}
								else {
									sprite = imagen->getImagen("Vacío(afuera)");
									casilla->setImagen("Vacío(afuera)");
								}
							}
							else {
								if (i == 7) { //Fila 7.
									if ((j == 1) || (j == 6)) {
										//matrizS[i][j] = 1;
										sprite = imagen->getImagen("Muro");
										casilla->setImagen("Muro");
									}else
									if (j == 4) {
										// matrizS[i][j] = 5;
										sprite = imagen->getImagen("CajaObjetivo");
										casilla->setImagen("CajaObjetivo");
									}else
									if ((j == 2) || (j == 3) || (j == 5)) {
										//matrizS[i][j] = 4;
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
										if ((j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6)) {
											//matrizS[i][j] = 1;
											sprite = imagen->getImagen("Muro");
											casilla->setImagen("Muro");
										}
										else {
											sprite = imagen->getImagen("Vacío(afuera)");
											casilla->setImagen("Vacío(afuera)");
										}
									}else
									if (i == 9) { //Fila 9.
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
}
void Juego::Nivel4(int i, int j) {
	//Singlenton.getInstance().movimientos = 49;

	if (i == 0) {  //Fila 0.
		sprite = imagen->getImagen("Vacío(afuera)");
		casilla->setImagen("Vacío(afuera)");
	}
	if (i == 1) {  //Fila 1.
		if ((j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6)) {
			//matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
			sprite = imagen->getImagen("Muro");
			casilla->setImagen("Muro");
		}
		else {
			sprite = imagen->getImagen("Vacío(afuera)");
			casilla->setImagen("Vacío(afuera)");
		}
	}
	else {
		if (i == 2) { //Fila 2.
			if ((j == 2) || (j == 5) || (j == 6) || (j == 7)) {
				//matrizS[i][j] = 1; //Se la asigna el número 1 que corresponde a la imagen del muro.
				sprite = imagen->getImagen("Muro");
				casilla->setImagen("Muro");
			}else
			if (j == 4) {
				//matrizS[i][j] = 2;
				//Singlenton.getInstance().x = i; //Guarda el valor de i y j.
				//Singlenton.getInstance().y = j;
				sprite = imagen->getImagen("Personaje");
				casilla->setImagen("Personaje");
				PosicionActual = casilla;
				p = i;
				k = j;
			}else
			if (j == 3) {
				//matrizS[i][j] = 7;
				sprite = imagen->getImagen("Vacío(adentro)");
				casilla->setImagen("Vacío(adentro)");
			}
			else {
				sprite = imagen->getImagen("Vacío(afuera)");
				casilla->setImagen("Vacío(afuera)");
			}
		}
		else {
			if (i == 3) { //Fila 3.
				if ((j == 2) || (j == 7)) {
					//matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
					sprite = imagen->getImagen("Muro");
					casilla->setImagen("Muro");
				}else
				if (j == 4) {
					//matrizS[i][j] = 3;
					sprite = imagen->getImagen("Caja");
					casilla->setImagen("Caja");
				}else
				if ((j == 3) || (j == 5) || (j == 6)) {
					//matrizS[i][j] = 7;
					sprite = imagen->getImagen("Vacío(adentro)");
					casilla->setImagen("Vacío(adentro)");
				}
				else {
					sprite = imagen->getImagen("Vacío(afuera)");
					casilla->setImagen("Vacío(afuera)");
				}
			}
			else {
				if (i == 4) { //Fila 4.
					if ((j == 1) || (j == 2) || (j == 3) || (j == 5) || (j == 7) || (j == 8)) {
						//matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
						sprite = imagen->getImagen("Muro");
						casilla->setImagen("Muro");
					}else
					if ((j == 4) || (j == 6)) {
						//matrizS[i][j] = 7;
						sprite = imagen->getImagen("Vacío(adentro)");
						casilla->setImagen("Vacío(adentro)");
					}
					else {
						sprite = imagen->getImagen("Vacío(afuera)");
						casilla->setImagen("Vacío(afuera)");
					}
				}
				else {
					if (i == 5) { //Fila 5.
						if ((j == 1) || (j == 3) || (j == 5) || (j == 8)) {
							//matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
							sprite = imagen->getImagen("Muro");
							casilla->setImagen("Muro");
						}else
						if (j == 2) {
							//matrizS[i][j] = 4;
							sprite = imagen->getImagen("Objetivo");
							casilla->setImagen("Objetivo");
						}else
						if ((j == 4) || (j == 6) || (j == 7)) {
							//matrizS[i][j] = 7;
							sprite = imagen->getImagen("Vacío(adentro)");
							casilla->setImagen("Vacío(adentro)");
						}
						else {
							sprite = imagen->getImagen("Vacío(afuera)");
							casilla->setImagen("Vacío(afuera)");
						}
					}
					else {
						if (i == 6) { //Fila 6.
							if ((j == 1) || (j == 6) || (j == 8)) {
								//matrizS[i][j] = 1;
								sprite = imagen->getImagen("Muro");
								casilla->setImagen("Muro");
							}else
							if (j == 3) {
								//matrizS[i][j] = 3;
								sprite = imagen->getImagen("Caja");
								casilla->setImagen("Caja");
							}else
							if (j == 2) {
								//matrizS[i][j] = 4;
								sprite = imagen->getImagen("Objetivo");
								casilla->setImagen("Objetivo");
							}else
							if ((j == 4) || (j == 5) || (j == 7)) {
								//matrizS[i][j] = 7;
								sprite = imagen->getImagen("Vacío(adentro)");
								casilla->setImagen("Vacío(adentro)");
							}
							else {
								sprite = imagen->getImagen("Vacío(afuera)");
								casilla->setImagen("Vacío(afuera)");
							}
						}
						else {
							if (i == 7) { //Fila 7.
								if ((j == 1) || (j == 8)) {
									//matrizS[i][j] = 1;
									sprite = imagen->getImagen("Muro");
									casilla->setImagen("Muro");
								}else
								if (j == 6) {
									//matrizS[i][j] = 3;
									sprite = imagen->getImagen("Caja");
									casilla->setImagen("Caja");
								}else
								if (j == 2) {
									//matrizS[i][j] = 4;
									sprite = imagen->getImagen("Objetivo");
									casilla->setImagen("Objetivo");
								}else
								if ((j == 3) || (j == 4) || (j == 5) || (j == 7)) {
									//matrizS[i][j] = 7;
									sprite = imagen->getImagen("Vacío(adentro)");
									casilla->setImagen("Vacío(adentro)");
								}
								else {
									sprite = imagen->getImagen("Vacío(afuera)");
									casilla->setImagen("Vacío(afuera)");
								}
							}
							else {
								if (i == 8) { //Fila 8.
									if ((j == 1) || (j == 2) || (j == 3) || (j == 4) || (j == 5) || (j == 6) || (j == 7) || (j == 8)) {
										//matrizS[i][j] = 1; //se la asigna el número 1 que corresponde a la imagen del muro.
										sprite = imagen->getImagen("Muro");
										casilla->setImagen("Muro");
									}
									else {
										sprite = imagen->getImagen("Vacío(afuera)");
										casilla->setImagen("Vacío(afuera)");
									}
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
void Juego::NivelSuperado()
{
	switch(nivel)
	{
	case 1:
		if (st.size() == 4 ) {
			nivel = 2;
			while (!st.empty()) {
				st.pop();
			}
			Refrescar(3);
		}
		break;
	case 2:
		if (st.size() == 3 ) {
			nivel = 3;
			while (!st.empty()) {
				st.pop();
			}
			Refrescar(3);
		}
		break;
	case 3:
		if (st.size() == 4) {
			nivel = 4;
			while (!st.empty()) {
				st.pop();
			}
			Refrescar(3);
		}
		break;
	case 4:
		if (st.size() == 3) {
			nivel = 1;
			while (!st.empty()) {
				st.pop();
			}
			Refrescar(3);
		}
		break;
	}
}
void Juego::RepintarNivel()
{
	ventana1->clear();
	ventana1->draw(*imagen->getFondo());
	ventana1->draw(*imagen->getS());
	Sprite* p = imagen->getNivel(nivel);
	p->setPosition(30, 70);
	ventana1->draw(*p);
	for (int i = 0; i < 10; i++) {
		casilla = NULL;
		for (int j = 0; j < 10; j++) {
			casilla = mat->DevolverCasilla(i, j);
			sprite = new Sprite();
			if (casilla->getImagen() == "Vacío(afuera)")
				sprite = imagen->getImagen(casilla->getImagen());
			else if (casilla->getImagen() == "Vacío(adentro)")
				sprite = imagen->getImagen(casilla->getImagen());
			else if (casilla->getImagen() == "Muro")
				sprite = imagen->getImagen(casilla->getImagen());
			else if (casilla->getImagen() == "Objetivo")
				sprite = imagen->getImagen(casilla->getImagen());
			else if (casilla->getImagen() == "Caja")
				sprite = imagen->getImagen(casilla->getImagen());
			else if (casilla->getImagen() == "CajaObjetivo")
				sprite = imagen->getImagen(casilla->getImagen());
			else if (casilla->getImagen() == "Personaje" || casilla->getImagen() == "PersonajeObjetivo")
				sprite = imagen->getImagen("Personaje");
			sprite->setPosition(casilla->getX(), casilla->getY());
			ventana1->draw(*sprite);
		}
	}
	ventana1->display();
	for (int i = 0; i <= 10; i++) {
		casilla = NULL;
		for (int j = 0; j <= 10; j++) {
			casilla = mat->DevolverCasilla(i, j);
			if (casilla != NULL)
				cout << casilla->getImagen();
			cout << "\t";
		}cout << endl;
	}
}
//Método que hace el movimiento.
 //0 = Vacío(afuera).
	//1 = Muro.
	//2 = Personaje.
	//3 = Caja.
	//4 = Objetivo.
	//5 = CajaObjetivo.
	//6 = PersonajeObjetivo.
	//7 = Vacío(adentro).
bool Juego::MovimientoIzquierda(int i, int j) {
	bool movimiento = false;
	Casilla* auxCasilla = mat->DevolverCasilla(i - 2, j);// i,j
	Casilla* auxCasilla1 = mat->DevolverCasilla(i - 1, j);
	if (auxCasilla1->getImagen() == "Vacío(adentro)") { //El personaje se va a ir moviendo entre los espacios vacíos(adentro). //Es la posición siguiente, qué hay ahí.
		movimiento = true;
		auxCasilla1->setImagen("Personaje"); //El personaje se mueve.
		if (PosicionActual->getImagen() == "Personaje") { //Válida la posición del personaje.
			PosicionActual->setImagen("Vacío(adentro)"); //Si está en un espacio vacío
		}
		else {
			PosicionActual->setImagen("Objetivo"); //o sino sobre un punto.
		}
	}
	else {
		if (auxCasilla1->getImagen() == "Caja") {
			//Si hay una caja, válida en la posición hacia arriba de la caja.
			if (auxCasilla->getImagen() == "Vacío(adentro)") { //Si está vacío la caja se mueve.
				movimiento = true;
				auxCasilla->setImagen("Caja"); //Cambia el valor dos posciciones hacia arriba de la posición del jugador.
				auxCasilla1->setImagen("Personaje");
				if (PosicionActual->getImagen() == "Personaje") {
					PosicionActual->setImagen("Vacío(adentro)");
				}
				else {
					PosicionActual->setImagen("Objetivo");
				} //Limpia la posición original del jugador.
			}
			else {
				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					//Singlenton.getInstance().contadorPuntos++;
					st.push(1);
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("Personaje");
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetvo");
					}
				}
			}
		}
		else {
			if (auxCasilla1->getImagen() == "CajaObjetivo") { //La cajaObjetivo pasa a ser personajeObjetivo.

				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("PersonajeObjetivo");
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
				else {
					if (auxCasilla->getImagen() == "Vacío(adentro)") {
						//Singlenton.getInstance().contadorPuntos--;
						st.pop();
						movimiento = true;
						auxCasilla->setImagen("Caja");
						auxCasilla1->setImagen("PersonajeObjetivo");
						if (PosicionActual->getImagen() == "Personaje") {
							PosicionActual->setImagen("Vacío(adentro)");
						}
						else {
							PosicionActual->setImagen("Objetivo");
						}
					}

				}
			}
			if (auxCasilla1->getImagen() == "Objetivo") {
				movimiento = true;
				auxCasilla1->setImagen("PersonajeObjetivo");
				if (PosicionActual->getImagen() == "Personaje") {
					PosicionActual->setImagen("Vacío(adentro)");
				}
				else {
					PosicionActual->setImagen("Objetivo");
				}
			}
		}
	}
	if (movimiento) {
		p = i - 1;
		k = j;
		PosicionActual = auxCasilla1;
	}
	return movimiento;
}
bool Juego::MovimientoDerecha(int i, int j) {
	bool movimiento = false;
	Casilla* auxCasilla = mat->DevolverCasilla(i + 2, j);// i,j
	Casilla* auxCasilla1 = mat->DevolverCasilla(i + 1, j);//aux1,aux2
	if (auxCasilla1->getImagen() == "Vacío(adentro)") { //El personaje se va a ir moviendo entre los espacios vacíos(adentro).
		movimiento = true;
		auxCasilla1->setImagen("Personaje");
		if (PosicionActual->getImagen() == "Personaje") {
			PosicionActual->setImagen("Vacío(adentro)");
		}
		else {
			PosicionActual->setImagen("Objetivo");
		}
	}
	else {
		if (auxCasilla1->getImagen() == "Caja") {
			//Si hay una caja, válida en la posición hacia abajo de la caja.
			if (auxCasilla->getImagen() == "Vacío(adentro)") { //Si está vacío la caja se mueve.
				movimiento = true;
				auxCasilla->setImagen("Caja"); //Cambia el valor dos posciciones hacia abajo de la posición del jugador.
				auxCasilla1->setImagen("Personaje");
				//matrizS[i + 1][j] = 2; //Mueve el jugador hacia abajo.
				if (PosicionActual->getImagen() == "Personaje") {
					PosicionActual->setImagen("Vacío(adentro)");
				}
				else {
					PosicionActual->setImagen("Objetivo");
				} //Limpia la posición original del jugador.
			}
			else {
				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					//Singlenton.getInstance().contadorPuntos++;
					st.push(1);
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("Personaje");
					//matrizS[i + 1][j] = 2;
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
			}
		}
		else {
			if (auxCasilla1->getImagen() == "CajaObjetivo") { //La cajaObjetivo pasa a ser personajeObjetivo.
				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("PersonajeObjetivo");
					//matrizS[i + 1][j] = 6;
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
				else {
					if (auxCasilla->getImagen() == "Vacío(adentro)") {
						//Singlenton.getInstance().contadorPuntos--;
						st.pop();
						movimiento = true;
						auxCasilla->setImagen("Caja");
						auxCasilla1->setImagen("PersonajeObjetivo");
						//matrizS[i + 1][j] = 6;
						if (PosicionActual->getImagen() == "Personaje") {
							PosicionActual->setImagen("Vacío(adentro)");
						}
						else {
							PosicionActual->setImagen("Objetivo");
						}
					}

				}
			}
			else
				if (auxCasilla1->getImagen() == "Objetivo") {
					movimiento = true;
					auxCasilla1->setImagen("PersonajeObjetivo");
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
		}
	}
	if (movimiento) {
		p = i + 1;
		k = j;
		PosicionActual = auxCasilla1;
	}
	return movimiento;
}
bool Juego::MovimientoArriba(int i, int j) {
	bool movimiento = false;
	Casilla* auxCasilla = mat->DevolverCasilla(i, j - 2);// i,j
	Casilla* auxCasilla1 = mat->DevolverCasilla(i, j - 1);//aux1,aux2
	if (auxCasilla1->getImagen() == "Vacío(adentro)") { //El personaje se va a ir moviendo entre los espacios vacíos(adentro).
		movimiento = true;
		auxCasilla1->setImagen("Personaje");
		if (PosicionActual->getImagen() == "Personaje") {
			PosicionActual->setImagen("Vacío(adentro)");
		}
		else {
			PosicionActual->setImagen("Objetivo");
		}
	}
	else {
		if (auxCasilla1->getImagen() == "Caja") {
			if (auxCasilla->getImagen() == "Vacío(adentro)") { //Si está vacío la caja se mueve.
				movimiento = true;
				auxCasilla->setImagen("Caja");
				auxCasilla1->setImagen("Personaje");
				//matrizS[i][j - 1] = 2;
				if (PosicionActual->getImagen() == "Personaje") {
					PosicionActual->setImagen("Vacío(adentro)");
				}
				else {
					PosicionActual->setImagen("Objetivo");
				} //Limpia la posición original del jugador.
			}
			else {
				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					//Singlenton.getInstance().contadorPuntos++;
					st.push(1);
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("Personaje");
					//matrizS[i][j - 1] = 2;
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
			}
		}
		else {
			if (auxCasilla1->getImagen() == "CajaObjetivo") { //La cajaObjetivo pasa a ser personajeObjetivo.
				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("PersonajeObjetivo");
					//matrizS[i][j - 1] = 6;
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
				else {
					if (auxCasilla->getImagen() == "Vacío(adentro)") {
						//Singlenton.getInstance().contadorPuntos--;
						st.pop();
						movimiento = true;
						auxCasilla->setImagen("Caja");
						auxCasilla1->setImagen("PersonajeObjetivo");
						//matrizS[i][j - 1] = 6;
						if (PosicionActual->getImagen() == "Personaje") {
							PosicionActual->setImagen("Vacío(adentro)");
						}
						else {
							PosicionActual->setImagen("Objetivo");
						}
					}

				}
			}
			if (auxCasilla1->getImagen() == "Objetivo") {
				movimiento = true;
				auxCasilla1->setImagen("PersonajeObjetivo");
				if (PosicionActual->getImagen() == "Personaje") {
					PosicionActual->setImagen("Vacío(adentro)");
				}
				else {
					PosicionActual->setImagen("Objetivo");
				}
			}
		}
	}
	if (movimiento) {
		p = i;
		k = j - 1;
		PosicionActual = auxCasilla1;
	}
	return movimiento;
}
bool Juego::MovimientoAbajo(int i, int j) {
	bool movimiento = false;
	Casilla* auxCasilla = mat->DevolverCasilla(i, j + 2);// i,j
	Casilla* auxCasilla1 = mat->DevolverCasilla(i, j + 1);//aux1,aux2
	if (auxCasilla1->getImagen() == "Vacío(adentro)") { //El personaje se va a ir moviendo entre los espacios vacíos(adentro).
		movimiento = true;
		auxCasilla1->setImagen("Personaje");
		if (PosicionActual->getImagen() == "Personaje") {
			PosicionActual->setImagen("Vacío(adentro)");
		}
		else {
			PosicionActual->setImagen("Objetivo");
		}
	}
	else {
		if (auxCasilla1->getImagen() == "Caja") {
			if (auxCasilla->getImagen() == "Vacío(adentro)") { //Si está vacío la caja se mueve.
				movimiento = true;
				auxCasilla->setImagen("Caja");
				auxCasilla1->setImagen("Personaje");
				//matrizS[i][j + 1] = 2;
				if (PosicionActual->getImagen() == "Personaje") {
					PosicionActual->setImagen("Vacío(adentro)");
				}
				else {
					PosicionActual->setImagen("Objetivo");
				} //Limpia la posición original del jugador.
			}
			else {
				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					//Singlenton.getInstance().contadorPuntos++;
					st.push(1);
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("Personaje");
					//matrizS[i][j + 1] = 2;
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
			}
		}
		else {
			if (auxCasilla1->getImagen() == "CajaObjetivo") { //La cajaObjetivo pasa a ser personajeObjetivo.

				if (auxCasilla->getImagen() == "Objetivo") { //Hace que la caja llegue a la meta(objetivo).
					movimiento = true;
					auxCasilla->setImagen("CajaObjetivo"); //El objetivo pasó a ser cajaObjetivo.
					auxCasilla1->setImagen("PersonajeObjetivo");
					//matrizS[i][j + 1] = 6;
					if (PosicionActual->getImagen() == "Personaje") {
						PosicionActual->setImagen("Vacío(adentro)");
					}
					else {
						PosicionActual->setImagen("Objetivo");
					}
				}
				else {
					if (auxCasilla->getImagen() == "Vacío(adentro)") { //Válida que la posición siguiente a la caja esté vacío;
						//Singlenton.getInstance().contadorPuntos--; //Disminuye el contador de cajas en puntos porque se saca una caja del punto.
						st.pop();
						movimiento = true;
						auxCasilla->setImagen("Caja"); //Mueve la caja a su nueva posición.
						auxCasilla1->setImagen("PersonajeObjetivo");
						//matrizS[i][j + 1] = 6; //Coloca al personaje con el punto donde estaba la caja.
						if (PosicionActual->getImagen() == "Personaje") {
							PosicionActual->setImagen("Vacío(adentro)");
						}
						else {
							PosicionActual->setImagen("Objetivo");
						}
					}

				}
			}
			if (auxCasilla1->getImagen() == "Objetivo") {
				movimiento = true;
				auxCasilla1->setImagen("PersonajeObjetivo");
				if (PosicionActual->getImagen() == "Personaje") {
					PosicionActual->setImagen("Vacío(adentro)");
				}
				else {
					PosicionActual->setImagen("Objetivo");
				}
			}
		}
	}
	if (movimiento) {
		p = i;
		k = j + 1;
		PosicionActual = auxCasilla1;
	}
	return movimiento;
}