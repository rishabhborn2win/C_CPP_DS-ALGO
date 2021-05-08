// code for bubble sorting

#include<stdio.h>

int main(){
    
   int i, j, k, count, temp, num[25];

   printf("Please define number of elements: ");
   scanf("%d",&count);

   printf("Enter %d elements:- \n", count);
   
   for(i=0; i<count; i++)
   {
      scanf("%d",&num[i]);
   }
 

   for(i=0;i<count-1;i++){
       
      for(j=0; j<count-i-1; j++){
          
        //   swapping after selecting the elements
         if(num[j] > num[j+1]){
            temp=num[j];
            num[j]=num[j+1];
            num[j+1]=temp;
            
         }
      }
      printf("Elements after %d iteration:  ",i+1);
             for(k=0;k<count;k++)
                printf(" %d",num[k]);
        printf("\n");
   }

   printf("\n Final Array Elements after bubble sorting: ");
   for(i=0;i<count;i++)
      printf(" %d",num[i]);

   return 0;
}


//End of the code
