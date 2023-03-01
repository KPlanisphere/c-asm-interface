#include <stdio.h>

extern int half();
int main() {
	int count,x,y;
	count=0;
	printf("Entra un numero: ");
	scanf("%d",&x);
	while(x!=1)
	{
		count=count+1;
		y=half(x);
		printf("\n devuelve %d \n",y);
		if(y!=0)
			x=y;
		else
			x=x* 3+1;
			printf("\n X=%d",x);
	}
	printf("\n hay %d iteracciones. \n\n", count);
}
