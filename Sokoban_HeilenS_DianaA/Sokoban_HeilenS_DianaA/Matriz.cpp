#include "Matriz.h"

Matriz::Matriz()
{
	inicio = NULL;
	int x = 325, y = 150;
	for (int i = 0; i < 8; i++) {
		insertarFila(new Fila(i));
		for (int j = 0; j < 8; j++) {
			insertarColumna(new Columna(j), i);
			insertarCasilla(new Casilla(x, y, "hola"), i, j);
			y += 50;
		}
		x += 50;
		y = 150;
	}
}

Matriz::Matriz(Fila* inicio)
{
	this->inicio = inicio;
}

Fila* Matriz::getInicio()
{
	return inicio;
}

void Matriz::setInicio(Fila* inicio)
{
	this->inicio = inicio;
}

void Matriz::insertarFila(Fila* dato)
{
	if (this->inicio == NULL) {
		inicio = dato;
	}
	else {
		Fila* auxFila = inicio;
		while (auxFila->getSig() != NULL) {
			auxFila = auxFila->getSig();
		}
		dato->setAnt(auxFila);
		auxFila->setSig(dato);
	}
}

void Matriz::insertarColumna(Columna* dato, int i)
{
	bool encontro = false;
	Fila* auxFila = inicio;
	while (auxFila != NULL)
		if (auxFila->getI() == i && !encontro) {
			encontro = true;
			break;
		}
		else
			auxFila = auxFila->getSig();
	if (encontro) {

		if (auxFila->getColumnas() == NULL) {
			auxFila->setColumnas(dato);
		}
		else {
			Columna* auxColumna = auxFila->getColumnas();
			while (auxColumna->getSig() != NULL) {
				auxColumna = auxColumna->getSig();
			}
			dato->setAnt(auxColumna);
			auxColumna->setSig(dato);
		}
	}
}

void Matriz::insertarCasilla(Casilla* dato, int i, int j)
{
	bool encontro = false;
	Fila* auxFila = inicio;
	if (inicio != NULL) {
		while (auxFila != NULL)
			if (auxFila->getI() == i && !encontro) {
				encontro = true;
				break;
			}
			else
				auxFila = auxFila->getSig();
		if (encontro) {
			Columna* auxColumna = auxFila->getColumnas();
			encontro = false;
			if (auxColumna != NULL && !encontro) {
				while (auxColumna != NULL)
					if (auxColumna->getJ() == j) {
						encontro = true;
						break;
					}
					else
						auxColumna = auxColumna->getSig();
			}
			else
				cout << "No hay filas aun" << endl;
			if (encontro) {
				auxColumna->setCasilla(dato);
			}
		}
	}
	else
		cout << "No hay filas aun" << endl;
}

Casilla* Matriz::DevolverCasilla(int i, int j)
{
	Casilla* casilla= NULL;
	bool encontro = false;
	Fila* auxFila = inicio;
	if (inicio != NULL) {
		while (auxFila != NULL)
			if (auxFila->getI() == i && !encontro) {
				encontro = true;
				break;
			}
			else
				auxFila = auxFila->getSig();
		if (encontro) {
			Columna* auxColumna = auxFila->getColumnas();
			encontro = false;
			if (auxColumna != NULL && !encontro) {
				while (auxColumna != NULL)
					if (auxColumna->getJ() == j) {
						encontro = true;
						break;
					}
					else
						auxColumna = auxColumna->getSig();
			}
			else
				cout << "No hay filas aun" << endl;
			if (encontro) {
				casilla= auxColumna->getCasilla();
			}
		}
	}
	return casilla;
}
