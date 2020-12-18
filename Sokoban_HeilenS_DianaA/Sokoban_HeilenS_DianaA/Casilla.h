#pragma once
#include <iostream>

using namespace std;

class Casilla {
private:
	int x;
	int y;
	string imagen;
public:
	Casilla();
	Casilla(int x, int y, string imagen);
	
	int getX();
	int getY();
	string getImagen();
	void setX(int x);
	void setY(int y);
	void setImagen(string imagen);
	string toString();


};