#include <iostream>
#include <vector>

using namespace std;

bool detectaCadena(vector<int> v, int n, int ini, int fin) {
	//Caso base
	if (ini >= fin) {
		return true;
	}
	//Caso recursivo
	bool ret;
	int m = (ini + fin) / 2;
	if (v[fin] - v[m] > fin - m) return false;			//En caso de que no sea posible dar el salto
	if (v[m] - v[fin] > m - ini) return false;
	if (m != 0 && v[m] > v[m - 1] + 1) return false;
	bool izda = detectaCadena(v, n, ini, m);
	bool dcha = detectaCadena(v, n, m + 1, fin);

	return izda && dcha;
}

bool resuelveCaso() {
	int n, aux;
	cin >> n;

	if (n == 0) return false;

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}

	if (detectaCadena(v, n, 0, n - 1)) cout << "SI" << endl;
	else cout << "NO" << endl;
	return true;
}


int main() {
	while (resuelveCaso());
}