#pragma once
#ifndef NODO_H
#define NODO_H

class Nodo
{

private:
	int valor;
	Nodo *siguiente;
	Nodo* anterior;

public:
	Nodo(void);
	Nodo(int, Nodo*, Nodo*);// le manda quien es el siguiente
	~Nodo(void);


	void setValor(int);
	int getValor(void);

	void setSiguiente(Nodo*);
	Nodo * getSiguiente(void);

	void setAnterior(Nodo*);
	Nodo* getAnterior(void);


};




#endif // !NODO_H