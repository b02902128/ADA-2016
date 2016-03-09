#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;

void Mergesort(int y[], int src, int des){
	int i;
	if(src == des)
		return;
	int mid = (src + des - 1) / 2;
	//
	printf("l: ");
	for(i = src -1; i < mid; i++)
		printf("%d ", y[i]);
	printf("r: ");
	for(i = mid; i < des; i++)
		printf("%d ", y[i]);
	printf("\n");
	//
	Mergesort(y, src, mid);
	Mergesort(y, mid + 1, des);
	Merge(y, src - 1, mid + 1 - 1, mid , des);
}

void Merge(int z[], int L_start, int R_start, int L_end, int R_end){
	int *a = malloc(R_end * sizeof(int));
	int index = L_start;
	int i = L_start;
	while(L_start < L_end && R_start < R_end)
		if(z[L_start] > z[R_start])	a[index++] = z[R_start++];
		else a[index++] = z[L_start++];
	while(L_start < L_end) a[index++] = z[L_start++];
	while(R_start < R_end) a[index++] = z[R_start++];	
	for(; i < R_end; i++){
		z[i] = a[i];
		printf("%d ", a[i]);
	}
	printf("\n");
	
	free(a);
}

void randomm(int x[]){
	int i, num, temp;
	srand(time(NULL));
	for(i = 0; i < n; i ++){
		num = rand() % (i + 1);
		temp = x[num];
		x[num] = x[i];
		x[i] = temp;
	}
	printf("Shuffle over : ");
	for(i = 0; i < n; i++)
		if(i + 1 == n)
			printf("%d.\n", x[i]);
		else
			printf("%d, ", x[i]);
}

int main(){
	int i, j;
	printf("input array size: ");
	scanf("%d", &n);
	int ary[n];
	for(i = 0; i < n; i++){
		ary[i] = i + 1;
	}
	randomm(ary);
	Mergesort(ary, 1, n);
	printf("Merge result : ");
	for(i = 0; i < n; i++)
		if(i + 1 == n)
			printf("%d. \n", ary[i]);
		else
			printf("%d, ", ary[i]);
	return 0;
}