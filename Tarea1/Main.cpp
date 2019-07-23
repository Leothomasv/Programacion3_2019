#include <iostream>
#include <cmath>


using namespace std;

int invertir(int n);
bool esPalindromo(int n);

int main() {


	int opcion;
	do {
		cout << "=================================" << endl;
		cout << "1. Palindromo" << endl;
		cout << "2. Numero Elevado" << endl;
		cout << "3. Convertir Binario a Decimal" << endl;
		cout << "4. Salir" << endl;
		cout << "=================================" << endl;
		cout << "Ingrese opcion deseada: ";
		cin >> opcion;
		cout << "\n";

		switch (opcion)
		{
			//PALINDROMO 
		case 1:

			cout << "PALINDROMO" << endl;
			int numero;
			cout << "Ingrese numero: ";
			cin >> numero;
			int auxiliar;
			auxiliar = numero;

			int resto, invertido;
			invertido=0;
			while (numero != 0) {
				resto = numero % 10;
				numero = numero / 10;
				invertido = invertido * 10 + resto;
			}
			
			if (auxiliar == invertido) {
				cout << "es Palindromo \n"; 
			}
			else {
				cout << "No es Palindromo \n";
			}
			break;
			

			//NUMERO ELEVADO
		case 2:
			cout << "NUMERO ELEVADO" << endl;

			for (int x=0; x <= 10; x++) {

				int cuadrado = x * x;
				int cubo = x * x * x;

				printf("[Numero] %d , [Cuadrado] %d , [Cubo] %d \n", x, cuadrado, cubo);
			}

			break;

			//BINARIO A DECIMAL
		case 3:

			cout << "BINARIO A DECIMAL" << endl;
			int exponente, digito;
			double binario, decimal;
			cout << "Introducir numero: ";
			cin >> binario;
			exponente = 0;
			decimal = 0;
			while (((int)(binario / 10)) != 0)
			{
				digito = (int)binario % 10;
				decimal = decimal + digito * pow(2.0, exponente);
				exponente++;
				binario = (int)(binario / 10);
			}
			decimal = decimal + binario * pow(2.0, exponente);
			cout << endl << "Decimal: " << decimal << endl;

			break;



		default:
			break;
		}

	

	} while (opcion != 4);

}


//Clases de palindromo
//int invertir(int n) {
//	int respuesta = 0;
//
//	while (n > 0) {
//		respuesta = respuesta + n % 10;
//		respuesta = respuesta + 10;
//		n = n / 10;
//	}
//	return printf ("RESPUESTA %d \n", respuesta/10);
//
//}
//
//bool esPalindromo(int n) {
//	if (n == invertir(n)) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
