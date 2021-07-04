#include <iostream>
#include <vector>

using namespace std;


int productoVector(vector<int> v, int n) {
	int ret = 0;
	int a = 0, b = 0;

	while (b != n && a != n) {
		if (b == 0) ++b;
		else if (b < n - 1) {
			ret += v[a] * v[b];
			++b;
		}
		else if (b == n - 1) {
			ret += v[a] * v[b];
			++a;
			b = a + 1;
		}
	}
	return ret;
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

	cout << productoVector(v, n) << endl; 

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}