#include <iostream>
#include <vector>

using namespace std;

// Pre {0 < n < longitud(v) ^ ordenado(v, n)}
// Donde
// ordenado(v, n) {p.t. i : 0 <= i < n : V[i] => v[i - 1]}

int moda(vector<int> v, int n) {
	int nMax = 1, actual = 1, moda = v[0];
	int i = 1;
	while (i < n) {
		if (v[i - 1] == v[i])
			actual++;
		else
			actual = 1;				//En caso de que ya no se repita
		if (actual > nMax) {
			nMax = actual;
			moda = v[i];
		}
		++i;
	}
	return moda;
}

// {Post: frec(ret, v , n) = max i : 0 < i < n: frec(v[i], v, n)}
// Donde: 
// frec(val, v, n) = {# : 0 < i < n-1 : v[i] = val}
// # : cuenta
// Cuenta para cuantos elementos v[i] = val

int main() {
	int n, aux;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << moda(v, n) << endl;
}