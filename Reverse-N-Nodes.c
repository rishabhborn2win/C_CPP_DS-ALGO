#include <stdio.h>
#include <stdlib.h>
typedef struct Node SLL;
struct Node{
    int data;
    SLL *next;
}*head = NULL;

//to view the list
void traverse(SLL *h){
    if(h==NULL){
        printf("List is empty...");
    }else{
        printf("Elements in the list are: ");
        SLL *temp;
        temp =h;
        while(temp){
            printf("%d\n", temp->data);
            temp= temp->next;
        }
    }
}

//to insert element in the list
void insert_end(SLL **h, int m){
    SLL *new_node;
    new_node=(SLL *)malloc(sizeof(SLL *));
    new_node->data=m;
    if(*h==NULL){
        *h=new_node;
        new_node->next=NULL;
    }else {
        SLL *temp;
        temp =*h;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next= new_node;
        new_node->next=NULL;
    }
}

//to reverse the node
void reverse_nodes(SLL **h, int m){
    SLL *prev = NULL, *current = *h, *ahead = NULL, *firstNode = *h;
    for (int i = 0; i < m; i++)
    {
        ahead = current->next;
        current->next = prev;
        prev = current;
        current = ahead;
    }
    firstNode->next = current;
    *h = prev;
}

int main(){
    int a;
    printf("Enter number of elements in the list: ");
    scanf("%d", &a);
    for(int i=0; i<a; i++){
        int m;
        scanf("%d", &m);
        insert_end(&head, m);
    }
    traverse(head);
    printf("Enter the number of node You want to reverse: ");
    int k;
    scanf("%d", &k);
    if(k>0 && k<=a){
    reverse_nodes(&head, k);
    }else{
        printf("Out Of RANGE...");
    }
    traverse(head);
    return 0;
}

