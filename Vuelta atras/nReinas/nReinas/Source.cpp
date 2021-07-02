/*
Dado un tablero de nxn se pide averiguar de que forma se pueden colocar n reinas
(Version poco optima, ya que se recorre la solución con cada vuelta, pero funciona)
*/

#include<iostream>
#include<vector>

using namespace std;

bool filaNoUsada(vector<int> v, int posibilidad, int pos) {
	bool ret = true;
	int distancia;
	//Misma fila
	for (int i = 0; i < pos; i++) {
		if (v[i] == posibilidad) return false;
		distancia = pos - i;
		if (v[i] == (posibilidad - distancia)) return false;
		if (v[i] == (posibilidad + distancia)) return false;
	}
	return true;
}

int nReinas(vector<int> v, int n, int pos) {
	//Caso base
	int ret = 0;
	if (pos == n) { 
		 
		for (int i = 0; i < n; i++) cout << v[i] << " ";
		cout << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (pos == 0 || filaNoUsada(v, i, pos)) { 
			v[pos] = i; 
			ret += nReinas(v, n, pos + 1);
		}
	}
	return ret;
}

bool resuelveCaso() {
	int n, pos = 0;

	vector<int> v(100);
	cin >> n;
	if (!cin) return false;
	cout << nReinas(v, n, pos) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
