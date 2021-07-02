#include <iostream>
#include <vector>

using namespace std;


int secuenciaMasLarga(vector<int> v, int n, int m) {
	int a = 0, b = 0;
	int segmentoActual = 0;
	int sigPosicion = b + 1;				//Por si acaso el primer elemento es 0
	int ret = 0;
	int cerosActuales = 0;
	bool siguienteCero = false;

	while (b < n) {
		//if (i - a + 1 > ret) ret = i - a + 1;
		if (v[b] == 0) {
			cerosActuales++;
		}

		while (cerosActuales > m) {					//Encontramos el sigiuente 0
			if (v[a] == 0) cerosActuales--;
			++a;
		}
		
		if (b - a + 1 > ret) ret = b - a + 1; 
		++b;
	}
	return ret;
}



bool resuelveCaso() {
	int n, m, aux;
	vector<int> v;
	cin >> n;
	if (n == 0) return false;
	cin >> m;

	for (int i = 0; i < 5; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << secuenciaMasLarga(v, n ,m) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}