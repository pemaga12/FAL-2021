#include <iostream>

using namespace std;

bool sumDivisible(int n, int &digitos, int &suma) {
	//Caso base
	if (n < 10) {
		digitos++;
		suma += n;
		return true;
	}

	//Caso recursivo

	/*
	bool res = sumDivisible(n / 10, digitos, suma); 
	digitos++; 
	suma += n % 10; 
	return res && (suma % digitos == 0);
	*/

	return sumDivisible(n / 10, digitos, suma) && (((suma += n % 10) % ++digitos) == 0);

}


bool resuelveCaso() {
	int n, digitos = 0, suma = 0;
	cin >> n;
	if (n == 0) return false;

	cout << sumDivisible(n, digitos, suma) << endl;

	return true;
}

int main() {
	while (resuelveCaso());
}