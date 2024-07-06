#include <stdio.h>

void min_max(int *array, int dim, int *min, int *max){
  *min = 0; *max=0;
  for(int k=0; k<dim; k++){
    if(array[k]<array[*min]){
      *min=k;
    }
    if(array[k]>array[*max]){
      *max=k;
    }
  }

  if(dim==0){
    *min = -1; *max=-1;
  }
}

int main(){
  int N;
  scanf("%d", &N);
  int array[N];
  for(int i=0; i<N; i++){
    scanf("%d", array+i);
  }
  int min_indice, max_indice;

  min_max(&array, N, &min_indice, &max_indice);

  printf("%d %d\n", min_indice, max_indice);
}