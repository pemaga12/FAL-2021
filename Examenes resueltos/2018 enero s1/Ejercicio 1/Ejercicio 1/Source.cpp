#include <iostream>
#include <vector>

using namespace std;

void mayorSegmento(vector<int> v, int n) {
	int a = 0, b = 1;
	int ret1 = 0, ret2 = 1;		//ret1 comienzo de la seccion mas larga ret2 longitud de la seccion ret1
	while (b < n) {
		if(v[b] != v[b - 1] + 1){	//En caso de que comience una secuencia que no sea 
			a = b;
		}
		if (b - a + 1 > ret2) {
			ret2 = b - a + 1;
			ret1 = a;
		}
		++b;
	}
	cout << ret1 << " " << ret2 << endl;
}

bool resuelveCaso() {
	int n, aux;
	cin >> n;
	if (n == 0) return false;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	mayorSegmento(v, n);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}