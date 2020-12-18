#include "Matriz.h"

Matriz::Matriz()
{
	inicio = NULL;
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
