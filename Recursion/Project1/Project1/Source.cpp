#include <iostream>
#include <vector>

using namespace std;

bool detectaNumero(vector<int> v, int n, int d) {
	int b = 1, a = 0;
	int repeticiones = 0;
	bool ret = true;
	while (b < n) {
		if (v[b] == v[b - 1]) {
			++repeticiones;
			if (repeticiones > d) {
				ret = false;
				b = n + 1;
			}
			++b;
			
		}
		else if (v[b] > v[b - 1]) {
			if (v[b] != v[b - 1] + 1) {
				ret = false;
				b = n + 1;
			}
			++b;
			repeticiones = 0;
		}
		else { ret = false; b = n + 1; }
	}
	return ret;
}

bool resuelveCaso() {
	int n, d, aux;
	cin >> d >> n;
	if (d == 0 && n == 0) return false;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}

	if (detectaNumero(v, n, d)) {
		cout << "SI" << endl;
	}
	else cout << "NO" << endl;
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}