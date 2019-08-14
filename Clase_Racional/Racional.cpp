#include <iostream>
#include "Racional.h"

using namespace std;

Racional::Racional(void) : numerador(1) , denominador(1) {

}

Racional::Racional(int _numerador, int _denominador) : numerador(_numerador), denominador(_denominador)
{

}

void Racional::setNumerador(int _numerador)
{
	this->numerador = _numerador;
}

void Racional::setDenominador(int _denominador)
{
	this->denominador = _denominador;
}


int Racional::getMenorOperando(void) {
	return(numerador < denominador ? numerador : denominador);
}


void Racional::reducir(void) {

	for (int x = 2; x <= getMenorOperando(); x++) {
		if (numerador % x == 0 && denominador % x == 0) {
			this->numerador = this->numerador / x;
			this->denominador = this->denominador / x;
			x = 1;
		}
	}
}

void Racional::imprimir(void) {

	reducir();
	if (numerador == 0 && denominador == 0) {
		cout << "Resultado Indefinido\n";
		return;
	}
	else if (denominador == 0) {
		cout << "No se puede dividir entre cero\n";
		return;
	}

	cout << numerador << "/" << denominador << "\n";
}

void Racional::imprimir_flotante(void) {

	reducir();
	if (numerador == 0 && denominador == 0) {
		cout << "Resultado Indefinido\n";
		return;
	}
	else if (denominador == 0) {
		cout << "No se puede dividir entre cero\n";
		return;
	}


	cout << (float(numerador) / float(denominador)) << "\n";

}


Racional operator+(const Racional &lo, const Racional &ro) {
	Racional resultado;
	
	if (lo.denominador == ro.denominador)
	{
		resultado.setNumerador(lo.numerador + ro.numerador);
		resultado.setDenominador(lo.denominador);
	}
	else
	{
		resultado.setNumerador((lo.numerador * ro.denominador) + (ro.numerador * lo.denominador));
		resultado.setDenominador(lo.denominador * ro.denominador);
	}

	return resultado;

}

Racional operator-(const Racional &lo, const Racional &ro) {

	Racional resultado;
	
		if (lo.denominador == ro.denominador)
		{
			resultado.setNumerador(lo.numerador - ro.numerador);
			resultado.setDenominador(lo.denominador);
		}
		else
		{
			resultado.setNumerador((lo.numerador * ro.denominador) - (ro.numerador * lo.denominador));
			resultado.setDenominador(lo.denominador * ro.denominador);
		}

		return resultado;
}

Racional operator*(const Racional &lo, const Racional &ro) {
	Racional resultado;
		resultado.setNumerador(lo.numerador * ro.numerador);
		resultado.setDenominador(lo.denominador * ro.denominador);

		
		return resultado;
}

Racional operator/(const Racional &lo, const Racional& ro) {
	Racional resultado;
		resultado.setNumerador(lo.numerador * ro.denominador);
		resultado.setDenominador(lo.denominador * ro.numerador);
	
		return resultado;
}
