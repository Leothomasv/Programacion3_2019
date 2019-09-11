#pragma once
#ifndef MATRIZ_H
#define MATRIZ_H
#include "nodo.h"
#include <iostream>
#include<fstream>
#include <string>
#include <sstream>

using namespace std;

class matriz {

public:

	nodo* inicio;
	nodo* cursor;
	int rows = 0;
	int cols = 0;

	matriz()
	{
		this->inicio = nullptr;
	}

	matriz(int r, int c)
	{
		this->inicio = nullptr;
		for (int i = 0; i < r; i++)
		{
			this->agregarNuevaFila();
		}
		for (int i = 0; i < c - 1; i++)
		{
			this->agregarNuevaColumna();
		}
	}
	void agregarNuevaFila(int n=0 );//tienen que estar dentro de la clase
	void agregarNuevaColumna(int n=0 );
	void moverUltimaCol();
	void moverUltimaFila();
	bool moverCursor(int r, int c);
	void dibujarMatriz();
	bool asignarValor(int r, int c, int val);
	bool moverSigCol();
	bool moverSigFila();
	void moverPosicion(int val);
	int getValor();
	void moverCursorInicio();
	int getValorPosicionEspecifica(int r, int c);
};


//operaciones
matriz leerMatriz(string fileName);
void guardarMatriz(string filename, matriz m);
matriz sumarMatrices(matriz 
	1, matriz m2);
matriz restarMatrices(matriz m1, matriz m2);
matriz multiplicarMatrices(matriz m1, matriz m2);
matriz getCofactor(matriz m, int p, int q);
int GetMatrixDeterminant(matriz m);
void ElegirSiGuarda(int , matriz);

#endif // !MATRIZ_H
