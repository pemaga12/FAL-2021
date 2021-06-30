//Dado un número borra todos los elementos de un
//vector que contengan ese numero
#include <iostream>
#include <vector>

using namespace std;

vector<int> borraElemento(vector<int> v, int &n, int k) {
	int elementosActuales = n - 1;
	int i = 0;
	while (i < elementosActuales) {
		if (v[i] == k) {
			v[i] = v[elementosActuales];
			v.erase(v.begin() + elementosActuales);
			--elementosActuales;
		}
		else ++i;
	}
	n = elementosActuales;
	return v;
}

void resuelveCaso() {
	vector<int> v;
	int n, aux, k;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	v = borraElemento(v, n, k);
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}