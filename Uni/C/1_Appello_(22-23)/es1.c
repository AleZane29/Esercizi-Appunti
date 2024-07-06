#include <stdio.h>


int array_stesso_ordine(int* A, int N, int* B, int M){
    int found=0;
    int ver=1;
    int n=0;
    for(int i=0; i<N && ver==1; i++){
        for(n; n<M && found==0; n++){
            if(A[i]==B[n] || A[i]==B[n]*-1){
                found=1;
            }
        }
        if(found==0){
            ver=0;
        }else{
            found=0;
        }
    }
    return ver;
}

void main(){
    int N;
    int M;
    
    scanf("%d", &N);
    int A[N];
    for(int i=0; i<N; i++){
        scanf("%d", A+i);
    }
    
    scanf("%d", &M);
    int B[M];
    for(int i=0; i<M; i++){
        scanf("%d", B+i);
    }
    printf("%d\n", array_stesso_ordine(A,N,B,M));
}

