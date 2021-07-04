#include <iostream>
#include <math.h>

using namespace std;

unsigned int imagenEspecular(unsigned int n, int &longitud) {
	//Caso base
	if (n < 10) {
		++longitud;
		return n;
	}
	//Caso recursivo
	unsigned int ret = imagenEspecular(n / 10, longitud);
	int unidad = n % 10;
	int dcha = unidad * pow(10, longitud);
	ret = dcha + ret;
	++longitud;
	return ret;
	
}


bool resuelveCaso() {
	unsigned int n;
	cin >> n;
	if (n == 0) return false;
	int longitud = 0;
	cout << imagenEspecular(n, longitud) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}