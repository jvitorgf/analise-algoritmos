#include <stdio.h>

void sort(int *vet,int size);

int main()
{
	int vetor[] = {9,4,1,6,7};
	sort(vetor,5);

	for (int i = 0;i<5;i++){
		printf("%d\n",vetor[i]);
	}
	return 0;
}


void sort(int *vet,int size){
	int x,y,valor;

	for(x = 1;x<size;x++){
		valor = vet[x];

		for(y = x - 1; y>=0 && vet[y]>valor;y--){
			vet[y+1] = vet[y];
		}

		vet[y+1] = valor;
	}
}