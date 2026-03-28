#include<stdio.h>


int main(){
    int i, n;

    printf("enter a number: ");
    scanf("%d" , &n);

    for(i=2, i<n; i++){
       if(n%i == 0){
        printf("not a prime");
        return 0;
       }

    }
  if(n>1)
    printf("prime number");
  else
    printf ("not a prime number") 



}