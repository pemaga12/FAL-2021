#include <iostream>
#include <vector>


/*
Numeros entretenidos:
Son aquellos que no tienen dos digitos seguidos que no son iguales, por ejemplo, 1234 o 1872.
Dado un numero n, cuantos entretenidos menores que n hay?

Dado un numero n hay dos opciones
	1. O los numeros empiezan con una raiz, como por ejemplo el 3428:
		raiz = 342 | digito < 8
	2. O los numeros empiezan con una raiz menor y un digito que no sea el ultimo
		raiz < 342 | digito

Para el 2. usamos la recursion, diciendo cuales son todos los numeros menores que raiz que sean divertidos,
y a todos ellos les añado un digito

Para el 1 lo hacemos directamente.

*/
using namespace std;

int main() {

}

int cuantosEntretenidosMenores(int n, bool &entretenido) {
	//Caso base
	if (n < 10) return n;	//Si la raiz es menor que 10
	
	// Caso recursivo
	int raiz = n / 10;
	int k = n % 10;
	int ret = cuantosEntretenidosMenores(raiz, entretenido);
	ret *= 9;
	ret += 1;				//para mantener el 0

	if (!entretenido) {
		if (raiz % 10 < k) ret += k;
		else ret += k - 1;	
	}
	return ret;
}