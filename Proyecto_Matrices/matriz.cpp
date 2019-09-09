#include "matriz.h"
#include "nodo.h"

void matriz::moverUltimaCol()
{
	cursor = inicio;
	while (cursor->siguiente != nullptr)
	{
		cursor = cursor->siguiente;
	}
}

void matriz::moverUltimaFila()
{
	cursor = inicio;
	while (cursor->debajo != nullptr)
	{
		cursor = cursor->debajo;
	}
}

bool matriz::moverCursor(int r, int c)
{
	cursor = inicio;
	for (int i = 0; i < r; i++)
	{
		if (cursor->debajo != nullptr)
		{
			cursor = cursor->debajo;
		}
		else
		{
			cout << "Cursor fuera de posicion" << endl;
			cursor = inicio;
			return false;
		}
	}

	for (int i = 0; i < c; i++)
	{
		if (cursor->siguiente != nullptr)
		{
			cursor = cursor->siguiente;
		}
		else
		{
			cout << "Cursor fuera de posicion" << endl;
			cursor = inicio;
			return false;
		}
	}
	return true;
}

void matriz::agregarNuevaFila(int n )
{
	if (inicio == nullptr)
	{
		inicio = new nodo(n);
		rows = 1;
		cols = 1;
	}
	else
	{
		moverUltimaFila();
		nodo* temp = cursor;

		temp->debajo = new nodo(n);
		while (temp->siguiente != nullptr)
		{
			temp = temp->siguiente;
			temp->debajo = new nodo(0);
		}

		temp = cursor;

		while (temp->siguiente != nullptr)
		{
			temp->debajo->siguiente = temp->siguiente->debajo;
			temp = temp->siguiente;
		}
		rows++;

	}

}

void matriz::agregarNuevaColumna(int n )
{
	if (inicio == nullptr)
	{
		inicio = new nodo(n);
		rows = 1;
		cols = 1;
	}
	else
	{
		moverUltimaCol();
		nodo* temp = cursor;

		temp->siguiente = new nodo(n);
		while (temp->debajo != nullptr)
		{
			temp = temp->debajo;
			temp->siguiente = new nodo(0);
		}

		temp = cursor;

		while (temp->debajo != nullptr)
		{
			temp->siguiente->debajo = temp->debajo->siguiente;
			temp = temp->debajo;
		}
		cols++;

	}

}

void matriz::dibujarMatriz()
{
	nodo* temp = inicio;

	while (temp != nullptr)
	{
		nodo* temp2 = temp;
		while (temp2 != nullptr)
		{
			cout << temp2->valor << " ";
			temp2 = temp2->siguiente;
		}
		cout << endl;
		temp = temp->debajo;
	}

}

bool matriz::asignarValor(int r, int c, int val)
{
	if (moverCursor(r, c))
	{
		cursor->valor = val;
		return true;
	}
	cout << "No se pudo asignar valor, revisar archivo" << endl;
	return false;
}

bool matriz::moverSigCol()
{
	if (cursor->siguiente != nullptr)
	{
		cursor = cursor->siguiente;
		return true;
	}
	return false;
}

bool matriz::moverSigFila()
{
	if (cursor->debajo != nullptr)
	{
		cursor = cursor->debajo;
		return true;
	}
	return false;
}

void matriz::moverPosicion(int val)
{
	cursor->valor = val;
}

int matriz::getValor()
{
	return cursor->valor;
}

void matriz::moverCursorInicio()
{
	cursor = inicio;
}

int matriz::getValorPosicionEspecifica(int r, int c)
{
	if (moverCursor(r, c))
	{
		return getValor();
	}
	cout << "No se pudo capturar el valor, revisar el archivo " << endl;
	return -1;
}



matriz leerMatriz(string fileName)
{
	ifstream ifile(fileName);

	if (!ifile.good())
	{
		cout << "FATAL ERROR!! No se pudo abrir el archivo" << endl;
		return matriz();
	}

	matriz m;

	string line;
	getline(ifile, line);
	stringstream ss(line);

	while (!ss.eof())
	{
		int n;
		ss >> n;
		m.agregarNuevaColumna(n);
	}

	while (!ifile.eof())
	{
		m.agregarNuevaFila();
		m.moverUltimaFila();
		getline(ifile, line);
		stringstream ss2(line);
		int count = 0;
		while (!ss2.eof())
		{
			int n;
			ss2 >> n;
			m.moverPosicion(n);
			m.moverSigCol();
			count++;
			if (count > m.cols)
			{
				cout << "Matriz mal escrita" << endl;
				return matriz();
			}
		}
		if (count < m.cols)
		{
			cout << "Matriz mal escrita" << endl;
			return matriz();
		}
	}

	ifile.close();
	return m;

}

void guardarMatriz(string filename, matriz m)
{
	ofstream odata(filename);

	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			odata << m.getValorPosicionEspecifica(i, j);
			if (j != m.cols - 1)
			{
				odata << " ";
			}
		}
		if (i != m.rows - 1)
		{
			odata << endl;
		}
	}

	odata.close();
}

matriz sumarMatrices(matriz m1, matriz m2)
{
	if (m1.rows != m2.rows || m1.cols != m2.cols)
	{
		cout << "Matrices incompatibles" << endl;
		return matriz();
	}
	else
	{
		matriz m(m1.rows, m1.cols);
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				m1.moverCursor(i, j);
				m2.moverCursor(i, j);

				m.asignarValor(i, j, m1.getValor() + m2.getValor());
			}
		}
		return m;
	}
}

matriz restarMatrices(matriz m1, matriz m2)
{
	if (m1.rows != m2.rows || m1.cols != m2.cols)
	{
		cout << "Matrices incompatibles" << endl;
		return matriz();
	}
	else
	{
		matriz m(m1.rows, m1.cols);
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				m1.moverCursor(i, j);
				m2.moverCursor(i, j);

				m.asignarValor(i, j, m1.getValor() - m2.getValor());
			}
		}
		return m;
	}
}

matriz multiplicarMatrices(matriz m1, matriz m2)
{
	if (m1.cols != m2.rows)
	{
		cout << "Matrices incompatibles" << endl;
		return matriz();
	}
	else
	{
		matriz m(m1.rows, m2.cols);

		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m2.cols; j++)
			{
				m.moverCursor(i, j);
				for (int k = 0; k < m1.cols; k++)
				{
					m1.moverCursor(i, k);
					m2.moverCursor(k, j);
					m.moverPosicion(m.getValor() + (m1.getValor() * m2.getValor()));
				}
			}
		}

		return m;
	}
}

matriz getCofactor(matriz m, int p, int q)
{
	int i = 0, j = 0;
	matriz temp(m.rows - 1, m.cols - 1);

	for (int row = 0; row < m.rows; row++)
	{
		for (int col = 0; col < m.rows; col++)
		{
			if (row != p && col != q)
			{
				temp.asignarValor(i, j++, m.getValorPosicionEspecifica(row, col));
				if (j == m.rows - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}

	return temp;
}

int GetMatrixDeterminant(matriz m)
{
	if (m.rows != m.cols)
	{
		cout << "La matriz no es cuadrada, no se pudo calcular el determinante" << endl;
		return -1;
	}
	else
	{
		if (m.rows == 1)
		{
			return m.getValorPosicionEspecifica(0, 0);
		}
		else if (m.rows == 2)
		{
			int res = (m.getValorPosicionEspecifica(0, 0)*m.getValorPosicionEspecifica(1, 1));
			res -= (m.getValorPosicionEspecifica(0, 1)*m.getValorPosicionEspecifica(1, 0));
			return res;
		}
		else if (m.rows == 3)
		{
			int res = (m.getValorPosicionEspecifica(0, 0)*m.getValorPosicionEspecifica(1, 1)*m.getValorPosicionEspecifica(2, 2));
			res += (m.getValorPosicionEspecifica(0, 1)*m.getValorPosicionEspecifica(1, 2)*m.getValorPosicionEspecifica(2, 0));
			res += (m.getValorPosicionEspecifica(1, 0)*m.getValorPosicionEspecifica(2, 1)*m.getValorPosicionEspecifica(0, 2));

			int res2 = (m.getValorPosicionEspecifica(0, 2)*m.getValorPosicionEspecifica(1, 1)*m.getValorPosicionEspecifica(2, 0));
			res2 += (m.getValorPosicionEspecifica(0, 1)*m.getValorPosicionEspecifica(1, 0)*m.getValorPosicionEspecifica(2, 2));
			res2 += (m.getValorPosicionEspecifica(1, 2)*m.getValorPosicionEspecifica(2, 1)*m.getValorPosicionEspecifica(0, 0));

			return (res - res2);
		}
		else
		{
			int res = 0;
			int sign = 1;
			for (int i = 0; i < m.rows; i++)
			{
				matriz temp = getCofactor(m, 0, i);
				res += (sign*m.getValorPosicionEspecifica(0, i)*GetMatrixDeterminant(temp));
				sign = -1 * sign;
			}
			return res;
		}
		
	}
}

void ElegirSiGuarda(int n, matriz m) {
	if (cin.fail())
	{
		cin.clear();
	}
	
	cin.ignore();
	if (n == 1)
	{
		cout << "Ingresar nombre del archivo: " << endl;
		string archivo;
		getline(cin, archivo);
		guardarMatriz(archivo, m);
	}

}
