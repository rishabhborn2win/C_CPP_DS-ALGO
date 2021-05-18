//infix to postfix conversion
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
typedef struct Node Stack;
struct Node {
    int data;
    Stack *next;
};

int main(){
    Stack *top = NULL;
    char exp[100], pexp[100];
    printf("Enter the infinix expression: ");
    gets(exp);
    for(int i=0; exp[i]!= '\0'; i++){
        
        
    }
    return 0;

}