#include "matriz.h"

int main() {

	int opcion;

	do {
		system("cls");
		cout << "SELECIONE UNA OPERACION" << endl << endl;
		
		cout << "==================================" << endl;
		cout << "1. SUMAR MATRICES\n2. RESTAR MATRICES\n3. MULTIPLICACION DE MATRICES\n4. DETERMINANTE DE UNA MATRIZ\n5. SALIR DEL SISTEMA" << endl;
		cout << "==================================" << endl;
		cout << "Opcion?: ";
		cin >> opcion;

		if (opcion == 1)
		{
			cout << "Ingrese archivo de la matriz 1" << endl;
			string n1;
			cin.clear();
			cin.ignore();
			getline(cin, n1);
			matriz m1 = leerMatriz(n1);

			cout << "Ingrese archivo de la matriz 2" << endl;
			string n2;
			getline(cin, n2);
			matriz m2 = leerMatriz(n2);

			matriz m = sumarMatrices(m1, m2);
			m.dibujarMatriz();

			cout << "Ingrese 1 si desea guardar la matriz en un archivo, ingrese 2 si quiere omitir este paso" << endl;
			cin >> opcion;
			ElegirSiGuarda(opcion, m);


		}
		else if (opcion == 2)
		{
			cout << "Ingrese archivo de la matriz 1" << endl;
			string n1;
			cin.clear();
			cin.ignore();
			getline(cin, n1);
			matriz m1 = leerMatriz(n1);

			cout << "Ingrese archivo de la matriz 2" << endl;
			string n2;
			getline(cin, n2);
			matriz m2 = leerMatriz(n2);

			matriz m = restarMatrices(m1, m2);
			m.dibujarMatriz();

			cin.clear();
			cout << "Ingrese 1 si desea guardar la matriz en un archivo, ingrese 2 si quiere omitir este paso" << endl;
			cin >> opcion;
			ElegirSiGuarda(opcion, m);

		}
		else if (opcion == 3)
		{
			cout << "EIngrese archivo de la matriz 1" << endl;
			string n1;
			cin.clear();
			cin.ignore();
			getline(cin, n1);
			matriz m1 = leerMatriz(n1);

			cout << "Ingrese archivo de la matriz 2" << endl;
			string n2;
			getline(cin, n2);
			matriz m2 = leerMatriz(n2);

			matriz m = multiplicarMatrices(m1, m2);
			m.dibujarMatriz();

			cout << "Ingrese 1 si desea guardar la matriz en un archivo, ingrese 2 si quiere omitir este paso" << endl;
			cin >> opcion;
			ElegirSiGuarda(opcion, m);
		}
		else if (opcion == 4)
		{
			cout << "Ingrese archivo de la matriz 1" << endl;
			string n1;
			cin.clear();
			cin.ignore();
			getline(cin, n1);

			matriz m1 = leerMatriz(n1);

			int det = GetMatrixDeterminant(m1);
			cout << "Determinante: " << det << endl;
			system("pause");
		}
		else if (opcion == 5)
		{
		  cout << "SALIENDO DEL SISTEMA";
		}

	}while (opcion != 5);

	return 0;
}