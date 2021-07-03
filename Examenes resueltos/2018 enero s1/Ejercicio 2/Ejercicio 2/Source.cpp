#include <iostream>
#include <vector>

using namespace std;

int encuentraImpar(vector<int> v, int ini, int fin) {
	//Caso base
	if (ini >= fin)return v[ini];

	//Caso recursivo
	int m = (ini + fin) / 2;
	int valorMedio = (v[ini] + v[fin]) / 2;

	if (v[m] % 2 != 1) return v[m];
	if (v[m] == valorMedio) encuentraImpar(v, m + 1, fin);
	else encuentraImpar(v, ini, m);

}

bool resuelveCaso() {
	int n, aux;
	vector<int> v;
	cin >> n;
	if (n == 0) return false;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << encuentraImpar(v, 0, n - 1);
}

int main() {
	while (resuelveCaso());
}