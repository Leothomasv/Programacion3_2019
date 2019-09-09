#pragma once
#ifndef NODO_H
#define NODO_H

class nodo
{
public:
	nodo* debajo;
	nodo* siguiente;
	int valor;

	nodo(int _valor, nodo* _siguiente = nullptr, nodo* _abajo = nullptr)
	{
		this->valor = _valor;
		this->siguiente = _siguiente;
		this->debajo = _abajo;
	}
};




#endif // !
