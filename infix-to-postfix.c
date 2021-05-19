//infix to postfix conversion
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char *, int, char );
char pop(char *, int);
int prio(char );

int prio(char ch){
    if(ch == '+' || ch =='-'){
        return 1;
    }else if(ch=='*' || ch =='/' || ch == '%'){
        return 2;
    }else if(ch=='('){
        return 0;
    }else{
        printf("Wrong Operator");
        exit(0);
    }
}

void push(char *stack, int top, char ch){
    if(top==MAX-1){
        printf("Stack Overflow!");
    }else{
        stack[++top] = ch;
    }
}

char pop(char *stack, int top){
    if(top==-1){
        printf("Stack Underflow");
    }else{
         return stack[--top];
    }
}

int main(){
    char ie[100], pe[100];
    int i,j=0;
    printf("Enter Infix expression");
    gets(ie);
    for(i=0; ie[i] != '\0'; i++){
        if(ie[i] == '('){
            push(stack, top, ie[i]);
        }else if((ie[i] >= 'a' && ie[i] <= 'z') || (ie[i] >='A' && ie[i] <='Z')){
            pe[j++]=ie[i];
        }else if(ie[i] == ')'){
            while(stack[top] != '('){
                pe[j++] = pop(stack, top);
                pop(stack, top);
            }
        }else{
            while(top > -1 && (prio(stack[top]) >=))
        }
    }
    return 0;
}