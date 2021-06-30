#include <iostream>
#include <vector>
using namespace std;

/*
	Recursión por división:
	a = 2
	b = 2
	k = 1

	O(n^k log n); O(nlogn)

*/

void mezcla(vector<int>& v, int ini, int med, int fin) {
	/*
	Va mezclando los dos vectores, usando el algoritmo que
	dimos en el iterativo
	*/
}

void mergeShort(vector<int> v, int ini, int fin) {
	if (ini >= fin) {		//En caso de que no haya nada que ordenar, o solo sea 1
		return;
	}
	//caso recursivo
	int m = (ini + fin) / 2;
	mergeShort(v, ini, m - 1);
	mergeShort(v, m, fin);

	mezcla(v, ini, m, fin);			//Mezcla los dos vectores, de ini a m y de m a b
}

void resuelveCaso() {
	int n, aux;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	mergeShort(v, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}
}