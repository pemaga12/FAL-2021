#include <iostream>
using namespace std;

/*
Buscar si un vector tiene pares

*/

//Como no hacerlo
bool hayPares(int v[], int n) {
	bool encontrado = false;
	int i = 0;

	while (!encontrado && (i < n)) {
		if (v[i] % 2 == 0) encontrado;
		++i;
	}
	return encontrado;
}

//Como hacerlo

// {Pre: 0 <= n <= longitud(n)}

bool hayPares(int v[], int n) {
	bool encontrado = false;
	int i = 0;

	while ((v[i] % 2 != 0) && (i < n)) {
		++i;
	}

	return (i < n);
}

// {Post : ret = Ex i : 0 <= i < n : v[i] % 2 = 0}


/*
¿Cómo suelen ser los algoritmos interativos?
*/

// {Pre: ...}				Cosas que el algoritmo exige

// Es un entero y debe decrecer cada vuelta
// {Cota: n - i}
// Con esto obtenemos el coste O(n)
// En un comienzo la cota es n, porque tiene n posiciones. La cota se decrementa i porque la i en cada vuelta se va a haciendo más grande.

int f(int v[], int n) {		//Suele ser una función que devuelve un entero o cualquier otro tipo de variable a la que le llega el vector, el tamaño y a veces algo mas
	int i = 0;
	//Inicialización de variables locales
	
	//Invariante
	while (true) {

		//El invariante se cumple al entrar en el bucle, y también la condición del bucle;
		//Código ++i;
		//El invariante se cumple también al final del bucle
	}
	//El invariante se cumple al salir del bucle (I pero no la condición)
}

// {Post: ...}				Cosas que el algoritmo promete que hará