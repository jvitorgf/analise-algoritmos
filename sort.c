#include <stdio.h>
#include <stdlib.h> 


void insertionSort(int *vet,int size);
void selectionSort (int *vet,int size);

int main() {
	int n = 5;
	int* vet = (int*)malloc(n * sizeof(int)); 


	if(vet == NULL){
		exit(0);
	}else{
		vet =  (int[5]){9,4,7,6,1};
		printf("Antes: ");
		for (int i = 0;i<n;i++) {
			if(i != 4) {
				printf("%d, ",vet[i]);	
			}else{
				printf("%d ",vet[i]);
			}
		}
		printf("\n---------------------------------\n");
		printf("Depois: ");
		selectionSort(vet,n);
		for (int i = 0;i<n;i++) {
			if(i != 4) {
				printf("%d, ",vet[i]);	
			}else{
				printf("%d ",vet[i]);
			}
		}
	}
	return 0;
}


void insertionSort(int *vet,int size){
	int x,y,valor;

	for(x = 1;x<size;x++){
		valor = vet[x];

		for(y = x - 1; y>=0 && vet[y]>valor;y--){
			vet[y+1] = vet[y];
		}

		vet[y+1] = valor;
	}
}

void selectionSort (int *vet,int size){
	int x,j,z,valor;
	for(z=0;z<size-1;z++){
		j = z;
		valor = vet[z];
		for(x = z;x<size-1;x++){
			if(vet[x+1] < valor){
				valor = vet[x+1];
				j = x+1;	
			}
		}
		vet[j] = vet[z];
		vet[z] = valor;
	}

}