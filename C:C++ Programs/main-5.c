// Selection sort for the arrays

#include<stdio.h>

int main(){
    
   int i, j, count, temp, num[25];

   printf("Please define number of elements: ");
   scanf("%d",&count);

   printf("Enter %d elements:- \n", count);
   
   for(i=0; i<count; i++)
   {
      scanf("%d",&num[i]);
   }
 

   for(i=0;i<count;i++){
       
      for(j=i+1;j<count;j++){
          
        //   swapping after selecting the elements
         if(num[i]>num[j]){
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
            
         }
      }
      printf("Elements after %d iteration:  ",i+1);
             for(int k=0;k<count;k++)
                printf(" %d",num[k]);
        printf("\n");

   }

   printf("Elements after sorting: ");
   for(i=0;i<count;i++)
      printf(" %d",num[i]);

   return 0;
}
