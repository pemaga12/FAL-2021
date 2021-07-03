//8 0 0 1 0 0 1 0 1 2
//4 1 0 1 0 1

#include <iostream>
#include <vector>

using namespace std;

int menorSegmento(vector<bool> v, int n, int k) {
	int a = 0, b = 0;							//Limites de la ventana
	int ret = INT_MAX;								//Inicializo a n el mayor segmento posible 
	int trueEncontrado = 0;

	while(b < n){
		if (v[b] == true) ++trueEncontrado;	
		if (trueEncontrado == k && ret > (b - a + 1)) {
			ret = b - a + 1;
		}
		while (trueEncontrado >= k) {			//En caso de que hayan mas trues de los que deben se avanza k hasta que ya no hayan mas true
			++a;
			if (v[a] == true) { trueEncontrado--; }
		}
		++b;
		if (trueEncontrado == 0) ++a;
	}
	return ret;
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	int aux, k;
	vector<bool> v;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	cin >> k;

	cout << menorSegmento(v, n, k) << endl;

	return true;
}


int main() {
	while (resuelveCaso());
}