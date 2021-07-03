#include <iostream>
#include <vector>

using namespace std;

int encuentraMasCercano(vector<int> v, int n, int x, int ini, int fin) {
	//Caso base
	if (ini >= fin) return v[ini];

	int m = (ini + fin) / 2;
	int sol;
	if (v[m] - x == 0) return v[m];
	if (abs(x - v[m]) <= abs(x - v[m + 1])) return encuentraMasCercano(v, n, x, ini, m);
	else return encuentraMasCercano(v, n, x, m + 1, fin);
}

void resuelveCaso() {
	int x, n, aux;
	vector<int> v;

	cin >> x >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	
	cout << encuentraMasCercano(v, n, x, 0, n - 1) << endl;

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}