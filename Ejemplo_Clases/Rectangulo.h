#pragma once


#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {

private:
	int base;
	int altura;

public:
	Rectangulo(void);
	Rectangulo(int, int);

	void setBase(int);
	void setAltura(int);

	int getBase();
	int getAltura();

	int getArea();
	int getPerimetro();
	void imprimir();


};





#endif // !
