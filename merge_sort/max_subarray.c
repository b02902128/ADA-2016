#include <stdio.h>

#define MIN -2147483647

int Maxsubarray(int *a, int src, int des){
	if(src == des) return a[src];
	int mid = (src + des) / 2;
	int i;
	//
	printf("L: ");
	for(i = src; i <= mid; i++)
		printf("%d ", a[i]);
	printf("R: ");
	for(i = mid + 1 ; i <= des; i++)
		printf("%d ", a[i]);
	printf("\n");
	// 
	int L = Maxsubarray(a, src, mid);
	int R = Maxsubarray(a, mid + 1, des);
	int cross = Maxsubcross(a, src, mid, des);
	if(L > R && L > cross){
		des = mid;
		return L;
	}
	else if (R > L && R > cross){
		src = mid + 1;		
		return R;
	}
	else
		return cross;
}

int Maxsubcross(int *a, int src, int mid, int des){
	int i;
	int L = MIN;
	int L_sum = 0, L_max;
	for(i = mid; i >= src; i--){
		L_sum += a[i];
		if(L_sum > L){
			L = L_sum;
			L_max = i;
		}
	}
	int R = MIN;
	int R_sum = 0, R_max;
	for (i = mid + 1; i <= des; ++i){
		R_sum += a[i];
		if(R_sum > R){
			R = R_sum;
			R_max = i;
		}
	}
	src = L_max;
	des = R_max;
	return R + L;
}

int main(){
	int ary[] = {-20, 3, -4, 2, 7, -2, 3, 8, -10};
	int n = (sizeof(ary)/ sizeof(int));
	int src = 0, des = n - 1;
	printf("%d\n", Maxsubarray(ary, src, des));
	return 0;
}