#pragma once
#ifndef NODO_H
#define NODO_H

class Nodo
{

private:
	int valor;
	Nodo *siguiente;


public:
	Nodo(void);
	Nodo(int, Nodo*);// le manda quien es el siguiente
	~Nodo(void);


	void setValor(int);
	int getValor(void);

	void setSiguiente(Nodo*);
	Nodo * getSiguiente(void);



};




#endif // !NODO_H
