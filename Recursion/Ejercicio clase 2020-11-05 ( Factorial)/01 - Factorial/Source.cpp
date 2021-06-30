//Dado un numero calcula el factorial
#include <iostream>

using namespace std;

int casoRecursivo(int n) {
	//Caso base
	if (n == 0) {
		return 1;
	}

	//Caso recursivo
	return n * casoRecursivo(n - 1);
}

void resuelveCaso() {
	int n;
	cin >> n;
	cout << casoRecursivo(n) << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}
}