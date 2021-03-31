#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void insertionSort(int *vet,int size);
void selectionSort (int *vet,int size);

int main() {
	int n = 100,k=0;
	clock_t start, end;
	double cpu_time_used;
	int* vet; 

	while( k<12){
		vet = (int*)malloc(n * sizeof(int)); 
		for(int i =0;i<n;i++){
			vet[i] = n - i;
		}
		
		printf("\n---------------------------------\n");
		start = clock();
		insertionSort(vet,n);
		end = clock();
		cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
		printf("Tamanho: %d Tempo: %f\n",n,cpu_time_used);
		n = n*2;
		free(vet);
		k++;
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