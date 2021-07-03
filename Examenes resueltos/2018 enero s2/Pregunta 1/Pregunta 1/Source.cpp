#include <iostream>
#include <vector>

using namespace std;

int mayorSegmento(vector<int> v, int n) {
	int a = 0, b = 1;
	int ret = 0;
	while (b < n) {
		if (v[b] > v[b - 1]) {
			a = b;
		}
		if (b - a + 1 > ret) ret = b - a + 1;
		++b;
	}
	return ret;
}

bool resuelveCaso() {
	int n, aux;
	cin >> n;
	vector<int> v;
	
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << mayorSegmento(v, n) << endl;
	return true;
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}