/*
 Dado un k, obtener todos los numeros entre 0 y k - 1 tal que cada uno de los numeros
 no tiene unos.
 El numero que dan puede ser hasta 10^18

 Parecido a examen de Enero de 2020
*/
#include<iostream>

using namespace std;

/*

 Dado un k, que será del tipo:

	k = xxxxxx | y			donde y = es igual a el ultimo digito de k
 
 Tenemos que los números pueden ser
    xxxxxx | z				donde: z < y
	xxxxxx | x				donde: xxxxxx es menor estricto que la raiz
	
	Habrá que calcular los digitos de estas dos formas
*/

bool tieneUnos(long long raiz) {
	//Encargada de averiguar si la raiz tiene unos
	return true;
}

long long cuantosSinUnos(int k) {
	long long ret = 0;
	int d = k % 10;
	long long raiz = k / 10;
	
	if (!tieneUnos(raiz)) {
		ret += d;
		if (d > 1) {
			ret--;			//Porque he sumado uno de mas
		}
	}
	ret += 9 * cuantosSinUnos(raiz);
}

void resuelveCaso() {
	long long int k;
	cin >> k;

}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}