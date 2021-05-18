#include <stdio.h>
#include <stdlib.h>
typedef struct Node Stack;
struct Node{
    int data;
    Stack *next;
} *top = NULL;

int read_element(){
    int a;
    scanf("%d", &a);
    return a;
}


void push(Stack **h){
    int m = read_element();
    Stack *new_node;
    new_node= (Stack *)malloc(sizeof(Stack *));
    new_node->data=m;
    if(*h==NULL){
        *h = new_node;
        new_node->next=NULL;
    }else{
        new_node->next = *h;
        *h = new_node;
    }
}

void pop(Stack **h){
    if(*h==NULL){
        printf("Stack Underflow..");
    }else{
        Stack *temp =*h, *firstNode=*h;
        *h = temp->next;
        free(firstNode);
        printf("Popped Out!");
    }
}

//to view the topmost element of the stack
void peak(Stack **h){
    if(*h==NULL){
        printf("Stack Underflow!");
    }else{
        Stack *temp = *h;
        printf("%d", temp->data);
    }
}

void traverse(Stack *h){
    if(h==NULL){
        printf("Stack is empty...\n");
    }else{
        printf("\nElement in the stack are: \n");
        Stack *temp = h;
        while(temp){
            printf("%d\n", temp->data);
            temp= temp->next;
        }
    }
}


int main(){
    int ch=0;
    while(ch<6){
    printf("\n 1) Push\n 2) Pop\n 3) Peak\n 4) Traverse\n 5) Exit\n Enter Your Choice: ");
    scanf("%d", &ch);
    switch(ch){
        case 1: push(&top);
            break;
        case 2: pop(&top);
            break;
        case 3:peak(&top);
            break;
        case 4: traverse(top);
            break;
        case 5: ch=7;
            break;
        default: ch=0; printf("Invalid Choice!\n");
    }
    }
    return 0;

}