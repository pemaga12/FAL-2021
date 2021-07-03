/*
Dado un vector, creciente con elementos repetidos, se considera que un escalon
esta formado por elementos repetidos del vector. Se pide:

1. Escalón mas largo
2. Primer escalon
3. Segundo escalon


*/
#include <iostream>
#include <vector>
using namespace std;

void escalones(vector<int> v, int a, int b, int& ancho, int& aDerecho, int& aIzquierdo) {
	//Caso base
	//Aprovecharse de la precondicion de que todos los elementos estan agregados y si el primero y el ultimo elemento son los mismos contestar directamente

	//Llamadas recursivas
	int m = (a + b) / 2;
	int a1, i1, d1;
	int a2, i2, d2;
	escalones(v, a, m, a1, i1, d1);
	escalones(v, m + 1, b, a2, i2, d2);
	
	aDerecho = d2;
	aIzquierdo = i2;
	if (v[a] == v[m + 1]) aIzquierdo += i2;
	if (v[m] == v[b]) aDerecho += d1;

	ancho = max(a1, a2);
	if (v[m] == v[m + 1]) ancho = max(ancho, d1 + i2);

}