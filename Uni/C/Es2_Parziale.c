#include <stdio.h>

int lung_string(char *s){
    if(*s=='\0'){
        return 0;
    }else{
        return 1+lung_string(s+1);
    }
}

void inverti_stringa(char *s, int dim){
    char x;
    if(dim>1){
        x=s[0];
        s[0]=s[dim-1];
        s[dim-1]=x;
        inverti_stringa(s+1, dim-2);
    } 
}

int main(void){
    char a[100];
    scanf("%s", a);
    inverti_stringa(a, lung_string(a));
    printf("%s\n", a);
}