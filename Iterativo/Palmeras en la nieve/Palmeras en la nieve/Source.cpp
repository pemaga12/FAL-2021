#include <iostream>
#include <vector>

using namespace std;

// {Pre: n: 0 < n <= longitud(v) ^ p.t. i : 0 < i < n: v[i] > 0}
// Complejidad (O(n))

int mayorSegmento(vector<int> v, int peso) {	//Return ret
	int arbolesCaidos = 0, ret = 0;
	int a = 0, b = 0;
	//I: (0 <= a <= b <= n) ^ 
	//							vivas = # i : a <= i < b : # v[i] >= k ^
	//							ret = max i j: (0 <= i <= j < b) ^
	// 							valido(v, i, j, k) : j - i + 1
	// Cota: 2n - (a + b)
	// Coste: 0(n)


	while (b < v.size()) {
		if (v[b] >= peso) {
			arbolesCaidos++;
		}
		while (arbolesCaidos > 5) {
			++a;
			if (v[a] > peso) {
				arbolesCaidos--;
			}
		}
		if (ret < b - a + 1) ret = b - a + 1;
		++b;
	}
	return ret;
}

// {Post: ret = max. i j: 0 <= i <= j <n : valido(v, i, j, k) : j - i + 1 }
// Donde:
// Valido(v, a, b, k) = (# i : a <= i <= b : # v[i] >= k) <= 5 
bool resuelveCaso() {
	int peso, n, aux;
	cin >> peso >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << mayorSegmento(v, peso) << endl;
	return true;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
	return 0;
}