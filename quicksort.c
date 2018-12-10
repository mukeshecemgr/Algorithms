#include <stdio.h>
#include <stdlib.h>



int partitioning(int A[],int st,int end){
	int pivot = A[end];int i=0;
	int pIdx = st;
	for (i=st;i < end; i++) {
		if ( A[i] <= pivot ) {
			int t = A[i];
			A[i]  = A[pIdx];
			A[pIdx] = t;
			pIdx++;
		}
	}
	int k = A[pIdx];
	A[pIdx] = A[end];
	A[end] = k;
    return pIdx;
}

void quick_sort(int A[],int st,int end){
    if ( st < end ) {
		int pIdx = partitioning(A,st,end);
		quick_sort(A,st,pIdx-1);
		quick_sort(A,pIdx+1,end);
   	}
}

void test(int A[]){
	A[2]=20;
}
main() {
	int A[8]={6,2,5,7,8,3,9,4};
	int i=0;
	printf("--Before Sorting ---\n");
	for (i=0; i < sizeof(A)/sizeof(int); i++){
		printf("|%d\t",A[i]);
	}
	printf("\n");	
	quick_sort(A,0,8);
	printf("--After Sorting ---\n");
	for (i=0; i < sizeof(A)/sizeof(int); i++){
		printf("|%d\t",A[i]);
	}
	printf("\n");	
	
	
}
	
