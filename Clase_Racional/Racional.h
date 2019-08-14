#pragma once

#ifndef RACIONAL_H
#define RACIONAL_H

class Racional {
	friend Racional operator+(const Racional &, const Racional &);
	friend Racional operator-(const Racional &, const Racional &);
	friend Racional operator*(const Racional &, const Racional &);
	friend Racional operator/(const Racional &, const Racional &);

public:
	Racional(void);
	Racional(int, int);
	void imprimir(void);
	void imprimir_flotante(void);

	void setDenominador(int);
	void setNumerador(int);


	
	

	/*Racional sumar(Racional);
	Racional restar(Racional);
	Racional multiplicar(Racional);
	Racional dividir(Racional);*/


private:
    int numerador, denominador;
	int getMenorOperando(void);
	void reducir(void);
	




	


};










#endif // !RACIONAL_H
