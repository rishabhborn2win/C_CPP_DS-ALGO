/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int main()
{
   int a[10], b[10], c[10], i, j,k;
   printf("Enter 5 elements in array 1: \n");
   for(i=0; i<5; i++){
       printf("Store element in a[%d]: ", i);
       scanf("%d", &a[i]);
   }
   printf("Enter 5 elements in array 2: \n");
   for(j=0; j<5; j++){
       printf("Store element in b[%d]: ", j);
       scanf("%d", &b[j]);
   }
   int m=0,n=0,p=0;
   while(m<5 && n<5){
       if(a[m]<b[n]) {
          c[p]=a[m];
          p++;
          m++;
       }else{
           c[p]=b[n];
           p++;
           n++;
       }
   }
   while(m<5){
       c[p]=a[m];
       m++;
       p++;
   }
    while(n<5){
       c[p]=b[n];
       n++;
       p++;
   }
   
   for(k=0; k<10; k++){
       printf("%d ", c[k]);
   }


    return 0;
}
