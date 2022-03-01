#include <stdio.h>
#include <stdlib.h>
int main(){
    int t,b,max = 0,min = 1000000;
    scanf("%d",&t);
    int* a;
    a = (int*)malloc(sizeof(int) * t);
    for(int i = 0; i< t; i++){
        scanf("%d",&a[i]);
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    printf("%d",max * min);
    
} 

