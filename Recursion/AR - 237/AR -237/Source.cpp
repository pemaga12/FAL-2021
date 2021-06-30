#include <iostream>
using namespace std;

bool polidivisible(long long n, int &digitos) {
	//Caso base
	if (n < 10) {
		digitos++;
		return true;
	}

	//Caso recursivo
	bool ret = polidivisible(n / 10, digitos);
	digitos++;
	return ret && (n % digitos == 0);
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;
	
	int d = 0;
	if (polidivisible(n, d)) {
		cout << "POLIDIVISIBLE" << endl;
	}
	else
		cout << "NO POLIDIVISIBLE" << endl;
	
}


int main() {
	while (resuelveCaso());
}