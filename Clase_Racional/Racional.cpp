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


Racional Racional::sumar(Racional fraccion)
{
	Racional resultado;

	if (fraccion.denominador == this->denominador)
	{
		resultado.setNumerador(this->numerador + fraccion.numerador);
		resultado.setDenominador(this->denominador);
	}
	else
	{
		resultado.setNumerador((this->numerador * fraccion.denominador) + (fraccion.numerador * this->denominador));
		resultado.setDenominador(this->denominador * fraccion.denominador);
	}

	return resultado;
}

Racional Racional::restar(Racional fraccion) {

	Racional resultado;

	if (fraccion.denominador == this->denominador)
	{
		resultado.setNumerador(this->numerador - fraccion.numerador);
		resultado.setDenominador(this->denominador);
	}
	else
	{
		resultado.setNumerador((this->numerador * fraccion.denominador) - (fraccion.numerador * this->denominador));
		resultado.setDenominador(this->denominador * fraccion.denominador);
	}

	return resultado;
}

Racional Racional::multiplicar(Racional fraccion) {
	Racional resultado;
	resultado.setNumerador(this->numerador * fraccion.numerador);
	resultado.setDenominador(this->denominador * fraccion.denominador);

	return resultado;
}

Racional Racional::dividir(Racional fraccion) {
	Racional resultado;
	resultado.setNumerador(this->numerador * fraccion.denominador);
	resultado.setDenominador(this->denominador * fraccion.numerador);

	return resultado;
}