#include <iostream>
#include <vector>

using namespace std;

/*
int secuenciaMasLarga(vector<int> v, int n, int m) {
	int a= 0, i = 0;
	int segmentoActual = 0;
	int sigPosicion = i + 1;	//Por si acaso el primer elemento es 0
	int ret = 0;
	int cerosActuales = 0;
	
	while (i < n) {
		if (v[i] == 0) {
			
			cerosActuales++;
			if (cerosActuales == 1) {
				sigPosicion = i + 1;
			}
			if (cerosActuales > m) {	//En caso de que se haya llegado al maximo de 0
				a = sigPosicion;
				cerosActuales--;
			}
			 
		}
		
		if (i - a + 1 > ret) ret = i - a + 1;
		++i;
		
	}
	return ret;
}
*/


int secuenciaMasLarga(vector<int> v, int n, int m) {
	int a = 0, i = 0;
	int segmentoActual = 0;
	int sigPosicion = i + 1;				//Por si acaso el primer elemento es 0
	int ret = 0;
	int cerosActuales = 0;
	bool siguienteCero = false;

	while (i < n) {
		//if (i - a + 1 > ret) ret = i - a + 1;
		if (v[i] == 0) {
			cerosActuales++;
		}

		while (cerosActuales > m) {					//Encontramos el sigiuente 0
			if (v[a] == 0) cerosActuales--;
			++a;
		}
		
		if (i - a + 1 > ret) ret = i - a + 1; 
		++i;
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