/*
 De nuevo, dada una escalera ordenada del tipo [1,1,1,2,3,3,3,4,5]
 Se pregunta saber si es creciente por los pelos, es decir, si la diferencia entre 
 cada escalón es como mucho 1

 [2,2,3,3,4,5]
 Como maximo podrá haber 6 de diferencia

*/

#include <iostream>
#include <vector>

using namespace std;

/*
	De nuevo el resultado dependerá de la cantidad de escalones que hayan
*/

bool crecientePorLosPelos(vector<int> v, int ini, int fin) {
	if (ini > fin) return true;
	if (v[ini] >= v[fin] - 1) return true;
	if (v[fin] - v[ini] > fin - ini) return false;
	if ((ini - fin == 1) && (v[fin] > v[ini] + 1)) return false;
	
	//Caso recursivo
	int m = (ini + fin) / 2;
	bool izda = crecientePorLosPelos(v, ini, m);
	bool dcha = crecientePorLosPelos(v, m + 1, fin);

	return (v[m] - v[m + 1] <= 1) && izda && dcha;
}

void resuelveCaso() {
	int n, aux;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << crecientePorLosPelos(v, 0, n - 1) << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}

