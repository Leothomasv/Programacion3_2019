
#include "Rectangulo.h"
#include <iostream>

using namespace std;


Rectangulo::Rectangulo(): base(0), altura(0)
{
}

Rectangulo::Rectangulo(int b, int a) {

	setBase(b);
	setAltura(a);

}

void Rectangulo::setBase(int b) {

	(b < 0) ? this->base = 0 : this->base = b;
	
}

void Rectangulo::setAltura(int a)
{
	(a < 0) ? this->altura = 0 : this->altura = a;
}

int Rectangulo::getBase() {
	return base;
}

int Rectangulo::getAltura() {
	return altura;
}

int Rectangulo::getArea() {
	return base * altura;
}


int Rectangulo::getPerimetro() {
	return 2 * (base + altura);
}

void Rectangulo::imprimir() {

	cout << "\nRectangulo {base: " << getBase() << ", altura: " << getAltura() <<
		", area: " << getArea() << ", perimetro: " << getPerimetro();

}