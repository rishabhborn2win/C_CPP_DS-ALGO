// code for insertion sorting

#include<stdio.h>

int main(){
    
   int i, j, k, count, set, temp, num[25];

   printf("Please define number of elements: ");
   scanf("%d",&count);

   printf("Enter %d elements:- \n", count);
   
   for(i=0; i<count; i++)
   {
      scanf("%d",&num[i]);
   }
 

// logic for the insertion sorting
   for(i=1;i<count;i++){
        set = num[i]; 
        j = i - 1; 

        while (j >= 0 && num[j] > set) { 
            num[j + 1] = num[j]; 
            j = j - 1; 
        } 
        
        num[j + 1] = set; 
            printf("Elements after %d iteration:  ",i);
             for(k=0;k<count;k++)
                printf(" %d",num[k]);
            printf("\n");
   }

   printf("\n Final Array Elements after insertion sorting: ");
   for(i=0;i<count;i++)
      printf(" %d",num[i]);

   return 0;
}


//End of the code
