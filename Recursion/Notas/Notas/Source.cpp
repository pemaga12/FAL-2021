/*
Complejidad de un algoritmo recursivo por sustracción

Si el tamaño de los datos es menor o igual que el caso base
T(n) = C0

En caso de que esté en el caso recursivo:
T(n) = T(n - b) -> Esto lo tendré que hacer más de una vez, por lo que
T(n) = a*T(n - b) + El coste de combinar, es decir, el coste que no sea las llamadas recursivas

T(n) = a*T(n-b) + c * n^k, donde k es el equivalente del coste 

Complejidad del algoritmo recursivo POR SUBSTRACCIÓN:

	| O(n^(k + 1)			Si a = 1
	|
	| O(a^(n/b))			Si a > 1

	a: Numero de llamadas recursivas dentro de la función
	b: Tamaño de los datos (cuanto decrece en cada iteración)
	k: Complejidad de lo que no son llamadas recursivas


Complejidad en el factorial:

	a = 1
	b = 1
	k = 0 (cte)

	| O(n^(1))	= O(n)			Si a = 1

Complejidad en el fibonacci
	
	a = 2
	b = 1
	k = 0 (cte)

	| O(2^n)

*/

/*

Recursión por división

Si el tamaño de los datos es menor o igual que el caso base
T(n) = C0
En caso de que esté en el caso recursivo:
T(n) = T(n / b) + c * n^k
 
 - O(n^k)			si a < b^k
 - O(n^k log n)		si a = b^k
 - O(n^(log_b a))	si a > b^k 

*/