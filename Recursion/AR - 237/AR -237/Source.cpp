#include <iostream>
using namespace std;


/*
Complejidad de recursión por substracción
	d = número de dígitos (tamaño de los datos)

	a = 1			(Sólo una llamada recursiva)
	b = 1			(Esto es debido a que el numero de digitos se reduce 1 a 1)
	k = 0			(El coste es constante)

	O(n^(k+1)) = O(n^1) = O(n)
	El coste es lineal
*/

/*
 Complejidad de recursión por división
 Tam: n
	
	a = 1
	b = 10
	k = 0

	a = b^k; O(n^k logn) = O(n^0 log n) = O(log n)

*/

bool polidivisible(long long n, int &digitos) {
	//Caso base
	if (n < 10) {
		digitos++;
		return true;
	}

	//Caso recursivo
	bool ret = polidivisible(n / 10, digitos);
	digitos++;
	return ret && (n % digitos == 0);
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;
	
	int d = 0;
	if (polidivisible(n, d)) {
		cout << "POLIDIVISIBLE" << endl;
	}
	else
		cout << "NO POLIDIVISIBLE" << endl;
	
}


int main() {
	while (resuelveCaso());
}