#include <iostream>
#include <math.h>

using namespace std;

//n es la longitud de los lados actuales
//En cada nivel de cuadrados la cantidad aumenta en 4

int casoRecursivo(int n) {
	//Caso base
	if (n == 1) return 4;	//En caso de que sea el ultimo 

	//Caso recursivo
	return 4 * casoRecursivo(n / 2) + n * 4;
}

bool resuelveCaso() {
	int n;
	
	cin >> n;
	if (!cin) return false;

	cout << casoRecursivo(n) << endl;
}

int main() {
	while (resuelveCaso());
}