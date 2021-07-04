//NO FUNCIONA

#include <iostream>
#include <vector>

using namespace std;

/*
{Pre: 0 < n <= longitud(v)}
*/

int encuentraSucesion(vector<int> v, int n) {
	int a = 0;
	int b = 0;
	int ret = 0;
	int suma = 0;

	while (b < n) {

		if (b - a < 2) {
			suma += v[b];
			++b;
		}

		else if (suma == v[b]) {
			suma -= v[b - 2];
			suma += v[b];
			++b;
		}

		else {
			suma -= v[a];
			++a;
		}

		ret = max(ret, b - a);
	}

	return ret;
}

bool resuelveCaso() {
	int n, aux;
	cin >> n;
	vector<int> v;

	if (n == 0) return false;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << encuentraSucesion(v, n) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
}