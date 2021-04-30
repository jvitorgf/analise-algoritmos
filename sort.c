#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void insertionSort(int *vet,int size);
void selectionSort (int *vet,int size);
void intercala(int *A, int p, int q, int r);
void mergeSort2(int *A,int p, int r);
void maxHeapfy(int *A, int m, int i);
void buildMaxHeap(int *A,int n);
void heapSort2(int *A,int n);
int particiona(int *A,int p, int r);
void quickSort2(int *A,int p,int r);

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
		//insertionSort(vet,n);
		//mergeSort2(vet,0,n-1);
		//heapSort2(vet,n);
		quickSort2(vet,0,n-1);

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


void intercala(int *A, int p, int q, int r){
	int i,j, k;
	int *B = malloc(sizeof(int)*(r-p+1));

	j=0;
	for(i = p;i <=q; i++){
		B[j++] = A[i];
	}

	for(i = r;i >=q+1; i--){
		B[j++] = A[i];
	}

	i = 0;
	j = r-p;

	for(k=p;k<=r;k++){
		if(B[i]<B[j]){
			A[k] = B[i];
			i = i+1;
		}else {
			A[k] = B[j];
			j = j - 1;
		}
	}

	free(B);
	B=NULL;
}

void mergeSort2(int *A,int p, int r){
	int q;
	if(p<r){
		q = (p+r)/2;
		mergeSort2(A,p,q);
		mergeSort2(A,q+1,r);
		intercala(A,p,q,r);
	}
}

void maxHeapfy(int *A, int m, int i){
	int e = 2 * i;
	int d = 2 * i +1;
	int aux,maior;

	if(e <= m && A[e]>A[i]){
		maior= e;
	}else{
		maior = i;
	}

	if(d <= m && A[d] > A[maior]){
		maior = d;
	}

	if(maior  != i){
		aux = A[i];
		A[i] = A[maior];
		A[maior] = aux;
		maxHeapfy(A, m , maior);
	}
}

void buildMaxHeap(int *A,int n){
	int i;
	for(i=n/2;i>=0;i--){
		maxHeapfy(A,n,i);
	}
}

void heapSort2(int *A,int n){
	int m,i,aux;
	buildMaxHeap(A,n-1);
	m = n-1;
	for(i=n-1;i>=1;i--){
		aux = A[0];
		A[0] = A[i];
		A[i] = aux;
		m = m - 1;
		maxHeapfy(A,m,0);
	}
}

int particiona(int *A,int p, int r){
	int i = p -1;
	int x = A[r];
	int j,aux;

	for(j =p;j <= r-1;j++){
		if(A[j] <= x){
			i = i+1;
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}
	}

	aux = A[i+1];
	A[i+1] = A[r];
	A[r] = aux;
	return i+1;
}

void quickSort2(int *A,int p,int r){
	int q;
	if(p<r){
		q= particiona(A,p,r);
		quickSort2(A,p,q-1);
		quickSort2(A,q+1,r);
	}
}