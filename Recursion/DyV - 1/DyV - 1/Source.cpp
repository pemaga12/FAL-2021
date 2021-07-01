//Dada una base y un exponente se pide calcular la potencia de ese numero
#include <iostream>
using namespace std;

/*
 Complejidad
 
 a = 1			(1 llamada)
 b = 2			(Por cuanto divido)	
 k = 0			(Coste constante)

 O(logn)

*/


int calculaPotencia(int b, int e) {
	//Caso base
	if (e == 1) return b;

	//Caso recursivo
	int iz, ret;
	iz = calculaPotencia(b, e / 2);
	ret = iz * iz;

	if (e % 2 == 1) ret *= b;

	return ret;
}


bool resuelveCaso() {
	int b, e;
	cin >> b >> e;

	if (!cin) return false;

	cout << calculaPotencia(b, e) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}