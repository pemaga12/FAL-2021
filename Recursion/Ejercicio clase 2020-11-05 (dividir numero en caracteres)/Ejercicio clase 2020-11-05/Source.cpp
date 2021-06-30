/*
Dado un numero n se debe escribir los digitos de ese numero separados por , y sumar el valor de los digitos
*/
#include <iostream>

using namespace std;

int casoRecursivo(int n) {
	//Caso base
	if (n < 10) {
		cout << n << " , ";
		return n;
	}

	//Caso Recursivo
	int suma = casoRecursivo(n / 10);
	cout << n % 10 << " , ";
	suma += n % 10;
	return suma;
}

bool resuelveCaso() {
	int n, i = 10;
	cin >> n;
	if (!cin) return false;
	
	cout << endl << "suma:" << casoRecursivo(n) << endl;
	
	return true;
}

int main() {
	while (resuelveCaso());
}