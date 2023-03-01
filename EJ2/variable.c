#include <stdio.h>

int extern suma(int v1,int v2);

int main() {
	int v1,v2, sum;
	printf("Dame un dato para sumar\n");
	scanf("%d", &v1); 
	printf("Dame otro numero para sumar\n");
	scanf("%d", &v2);
	sum = suma(v1,v2);
	printf("El resultado de la suma es = %d",sum);
	return 0; 
}
