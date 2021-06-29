#include <iostream>
using namespace std;

/*
Buscar si un vector tiene pares

*/

//Como no hacerlo
bool hayPares(int v[], int n) {
	bool encontrado = false;
	int i = 0;

	while (!encontrado && (i < n)) {
		if (v[i] % 2 == 0) encontrado;
		++i;
	}
	return encontrado;
}

//Como hacerlo

// {Pre: 0 <= n <= longitud(n)}

bool hayPares(int v[], int n) {
	bool encontrado = false;
	int i = 0;

	while ((v[i] % 2 != 0) && (i < n)) {
		++i;
	}

	return (i < n);
}

// {Post : ret = Ex i : 0 <= i < n : v[i] % 2 = 0}
