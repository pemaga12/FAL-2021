/*
	Dado un vector todos los numeros que son iguales están juntos.
	El orden de los vectores es creciente. 
	¿Cuántos números distintos hay?
*/

#include <iostream>
#include <vector>

using namespace std;

/*
La complejidad depende de la salida, ya que el tiempo que tardamos depende de la cantidad de 
escalones que haya que contar
*/


int nEscalones(vector<int> v, int ini, int fin) {
	if (ini > fin) {
		return 0;
	}
	if (v[ini] == v[fin]) return 1;
	
	int m = (ini + fin) / 2;
	int izda = nEscalones(v, ini, m);
	int dcha = nEscalones(v, m + 1, fin);

	return izda + dcha;
}

void resuelveCaso() {
	int tam, aux;
	vector<int> v;
	cin >> tam;

	for (int i = 0; i < tam; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << nEscalones(v, 0, tam - 1) << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}