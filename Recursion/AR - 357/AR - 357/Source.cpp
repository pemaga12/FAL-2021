#include <iostream>
#include <vector>

using namespace std;


/*

Supongamos que n = 8, de tal forma que las cajas son [1,2,3,4,5,6,7,8]

Si cogemos la mitad de las cajas y lo hacemos de tal forma que metemos la mitad de las bolas en la mitad de la caja:

[1,2,3,4,1,2,3,4], y podemos descartar la mitad de la izquierda porque no es necesaria, de tal forma que: [1,2,3,4]

*/

int cajasYBolas(int fin) {
	//Caso base:
	if (fin == 1) return 1;

	//Caso recursivo:
	int ret = 1 + cajasYBolas(fin / 2);
	return ret;
}

bool resuelveCaso() {
	int n;
	vector<int> v;
	cin >> n;
	if (!cin) return false;

	cout << cajasYBolas(n) << endl;
	
	return true;
}


int main() {
	while (resuelveCaso());
}