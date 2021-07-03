#include <iostream>
#include <vector>

using namespace std;

int segmentoOptimo(vector<int> v, int n, int k, int sumaTotal) {
	int a = 0, b = 0;
	int ret = sumaTotal;
	int sumaActual = 0;
	while (b < n || sumaActual > k) {
		if (sumaActual >= k) {
			ret = min(ret, sumaActual);
			sumaActual -= v[a];
			++a;
		}
		else {
			sumaActual += v[b];
			++b;
		}
		
	}


	return ret;
}

bool resuelveCaso() {
	int n, k, aux, sumaTotal = 0;
	cin >> n >> k;
	vector<int> v;
	if (n == 0 && k == 0) return false;

	for (int i = 0; i < n; ++i) {
		cin >> aux;
		sumaTotal += aux;
		v.push_back(aux);
	}

	cout << segmentoOptimo(v, n, k, sumaTotal) << endl;

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}