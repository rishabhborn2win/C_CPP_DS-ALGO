//infix to postfix conversion
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX], top=-1;

void push(){
    int m;
    scanf("%d", &m);
    if(top == MAX-1){
        printf("Stack Overflow...");
    }else{
        top++;
        stack[top]=m;
        printf("Inserted");
    }
}

void pop(){
    if(top==-1){
        printf("Stack Underflow...");
    }else{
        printf("Popped %d", stack[top]);
        top--;
        
    }
}

void peek(){
    if(top==-1){
        printf("Stack Underflow");
    }else{
        printf("%d", stack[top]);
    }
}

void traverse(){
    if(top==-1){
        printf("Stack is empty");
    }else{
        printf("Element in the stack are: ");
        for(int i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
    int ch=0;
    while(ch<6){
    printf("\n 1) Push\n 2) Pop\n 3) Peak\n 4) Traverse\n 5) Exit\n Enter Your Choice: ");
    scanf("%d", &ch);
    switch(ch){
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3:peek();
            break;
        case 4: traverse();
            break;
        case 5: ch=7;
            break;
        default: ch=0; printf("Invalid Choice!\n");
    }
    }
    return 0;

}
