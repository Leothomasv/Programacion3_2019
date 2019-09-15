
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<list>



using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


//Estadisticas
int puntos = 0;
int puntaje[10][2];

//color
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}//void gotoxy

void OcultarCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);

}//void ocultarcursor

void pintar_limites()
{
	for (int i = 2; i < 78; i++)
	{
		gotoxy(i, 3);
		printf("%c", 205);
		gotoxy(i, 32);
		printf("%c", 205);
	}//for limites x
	for (int i = 4; i < 32; i++)
	{
		gotoxy(2, i);
		printf("%c", 186);
		gotoxy(77, i);
		printf("%c", 186);

	}//for limites y
	gotoxy(2, 3);
	printf("%c", 201);
	gotoxy(2, 32);
	printf("%c", 200);
	gotoxy(77, 3);
	printf("%c", 187);
	gotoxy(77, 32);
	printf("%c", 188);

}//void pintar_limites

//NAVE
class NAVE
{
private:
	int x, y, salud, vidas;
public:
	NAVE(int _x, int _y, int _salud, int _vidas) :x(_x), y(_y), salud(_salud), vidas(_vidas)
	{
	}//constructor nave::nave
	int X()
	{
		return x;
	}//int X

	int Y()
	{
		return y;
	}//int Y
	
	int VIDAS()

	{

		return vidas;

	}//int VIDAS

	void msalud()

	{

		salud--;

	}//void msalud
	void pintar();
	void borrar();
	void mover();
	void pintar_salud();
	void morir();

};//clase nave

void NAVE::pintar()
{
	gotoxy(x + 2, y);
	printf("%c", 30);
	gotoxy(x + 1, y + 1);
	printf("%c%c%c", 40, 207, 41);
	gotoxy(x, y + 2);
	printf("%c%c %c%c", 30, 190, 190, 30);

}//void nave pintar

void NAVE::borrar()
{
	gotoxy(x, y);
	printf("     ");
	gotoxy(x, y + 1);
	printf("     ");
	gotoxy(x, y + 2);
	printf("     ");

}//void nave borrar

void NAVE::mover()
{
	if (_kbhit())
	{
		char tecla = _getch();
		borrar();
		if (tecla == IZQUIERDA && x > 3)x--;
		if (tecla == DERECHA && x + 5 < 77)x++;
		if (tecla == ARRIBA && y > 4)y--;
		if (tecla == ABAJO && y + 3 < 32)y++;
		pintar();
		pintar_salud();
	}//if

}//void nave mover

void NAVE::pintar_salud()
{
	gotoxy(50, 2);
	printf("Vidas %d", vidas);
	gotoxy(64, 2);
	printf("Salud");
	gotoxy(70, 2);
	printf("      ");
	for (int i = 0; i < salud; i++)
	{
		gotoxy(70 + i, 2);
		printf("%c", 220);

	}//for

}//void nave pintar_salud

void NAVE::morir()
{
	if (salud == 0)
	{
		borrar();
		gotoxy(x + 1, y);
		printf("**");
		gotoxy(x, y + 1);
		printf("****");
		gotoxy(x + 1, y + 2);
		printf("**");
		Sleep(200);
		borrar();
		gotoxy(x, y);
		printf("*  *");
		gotoxy(x, y + 1);
		printf("*++*");
		gotoxy(x, y + 2);
		printf("*  *");
		Sleep(200);
		borrar();
		vidas--;
		salud = 3;
		pintar_salud();
		pintar();
	}//if

}//void nave morir


//ASTEROIDE
class ASTEROIDE
{
	int x, y;
public:
	ASTEROIDE(int _x, int _y) :x(_x), y(_y)
	{
	}//constructor asteroide::asteriode
	
	int X()
	{
		return x;
	}//int X

	int Y()
	{
		return y;
	}//int Y
	
	void pintar();
	void mover();
	void colision(class NAVE &N);
};//class asteriode

void ASTEROIDE::pintar()
{
	gotoxy(x, y);
	printf("%c", 64);
}//void asteroide::pintar

void ASTEROIDE::mover()
{
	gotoxy(x, y);
	printf(" ");
	y++;
	if (y > 31)
	{
		x = rand() % 72 + 4;
		y = 4;
	}//if
	pintar();
}//void asteroide::mover

void ASTEROIDE::colision(class NAVE &N)
{
	if (x >= N.X() && x < N.X() + 5 && y >= N.Y() && y <= N.Y() + 2)
	{
		N.msalud();
		N.borrar();
		N.pintar();
		N.pintar_salud();
		x = rand() % 72 + 4;
		y = 4;
	}//if
}//void ASTEROIDE::colision

//BALA
class BALA
{
private:
	int x, y;
public:
	BALA(int _x, int _y) :x(_x), y(_y)
	{
	}//constructor bala::bala
	
	int X()
	{
		return x;
	}//int X

	int Y()
	{
		return y;
	}//int Y

	void mover();
	bool fuera();
};//class bala

void BALA::mover()
{
	gotoxy(x, y);
	printf(" ");
	y--;
	gotoxy(x, y);
	printf("%c", 186);
}//void bala::mover

bool BALA::fuera()
{
	if (y <= 4)return true;
	return false;
}//bool bala::fuera

//STATS

void AgregarEstadisticas() {
	for (int i = 0; i < 10; i++) {
		if (puntaje[i][1] == 0) {
			puntaje[i][0] = i + 1;
			puntaje[i][1] = puntos;
			break;
		}
	}
}

void ImpStats() {
	for (int i = 0; i < 10; i++) {
		gotoxy(67, 10 + i); printf("Juego: %d            %d\n", puntaje[i][0], puntaje[i][1]);
	}
}

void Estadisticas() {
	gotoxy(70, 5); printf("___ESTADISTICAS___");


}



int main()
{
	SetConsoleTitle("ASTEROIDS");
	char opcion;
	//MENU
	do {
		system("cls");
		gotoxy(65, 10); printf("_____A S T E R O I D S_____");

		gotoxy(72, 15); printf("1. JUGAR");
		gotoxy(72, 17); printf("2. ESTADISTICAS");
		gotoxy(72, 19); printf("3. SALIR");
		cout << "\n";

		gotoxy(72, 21); printf("INGRESE OPCION: ");
		cin >> opcion;

		if (opcion == '1')
		{
			system("cls");
			OcultarCursor();
			pintar_limites();

			NAVE N(35, 29, 3, 3);
			N.pintar();
			N.pintar_salud();

			list<ASTEROIDE*>A;
			list<ASTEROIDE*>::iterator itA;

			for (int i = 0; i < 5; i++)
			{
				A.push_back(new ASTEROIDE(rand() % 75 + 3, rand() % 5 + 4));//crea un nuevo asteroid
			}//for
			list<BALA*>B;
			list<BALA*>::iterator it;

			//int puntos = 0;
			bool game_over = false;
			while (!game_over)
			{

				gotoxy(1, 1);
				printf("MUEVES LA NAVE CON LAS FLECHAS Y DISPARAS CON 'X'");
				gotoxy(4, 2);
				printf("PUNTOS %d", puntos);
				if (_kbhit())
				{
					char tecla = _getch();
					if (tecla == 'x' || tecla == 'X')
						B.push_back(new BALA(N.X() + 2, N.Y() - 1));
				}//if



				for (it = B.begin(); it != B.end(); )// aqui borre el it++ // este era el error 
				{
					(*it)->mover();
					if ((*it)->fuera())
					{
						gotoxy((*it)->X(), (*it)->Y());
						printf(" ");
						delete(*it);
						it = B.erase(it);
					}//if
					else
						it++; // este era el error

				}//for

				for (itA = A.begin(); itA != A.end(); itA++)
				{
					(*itA)->mover();
					(*itA)->colision(N);
				}//for

				for (itA = A.begin(); itA != A.end(); itA++)
				{
					for (it = B.begin(); it != B.end();)
					{
						if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y()))//Borra la bala y el asteroide
						{
							gotoxy((*it)->X(), (*it)->Y());
							printf(" ");//Borra el dibujo de la bala
							delete(*it);
							it = B.erase(it); // esto quiere decir que toma el siguiente valor en la lista que fue borrado
							A.push_back(new ASTEROIDE(rand() % 75 + 3, 4));// debemos crear un nuevo asteroide
							gotoxy((*itA)->X(), (*itA)->Y());
							printf(" ");
							delete(*itA);
							itA = A.erase(itA);
							puntos += 5;
						}//if
						else
							it++;

					}//for

				}//for



				if (N.VIDAS() == 0)game_over = true;
				N.morir();
				N.mover();
				Sleep(30);

			}//while(gameover)
			system("cls");
			AgregarEstadisticas();
			puntos = 0;
			gotoxy(65, 10); printf("<PRESIONE ENTER PARA VOLVER AL MENU>");
			

		}
		else if(opcion == '2'){
			system("cls");
			gotoxy(130, 5); printf("<<<Presione ENTER para salir>>>");
			Estadisticas();
			ImpStats();

		}
		else if (opcion == '3') {
			system("cls");
			gotoxy(70, 10); cout << ("GAME OVER");
		}
		_getch();

	}while (opcion != '3');//el whle que hace funcionar el main

}//int main()






