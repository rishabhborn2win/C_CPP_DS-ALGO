
// Application Of DLL for converting Decimal to binary c program

#include <stdio.h>
#include <stdlib.h>
typedef struct Node DLL;
struct Node
{
    int value;
    DLL *prev;
    DLL *next;
} *head = NULL;

void insert_end(DLL **, int);
void traverse_dll(DLL *);
void reverse(DLL **);


void insert_end(DLL **h, int val)
{
    DLL *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(DLL *));
    newnode->value = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (*h == NULL)
    {
        *h = newnode;
        return;
    }

    temp = *h;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void traverse_dll(DLL *h)
{

    DLL *z; 
    if (h == NULL)
        printf("\nList is empty");
    else
    {
        
        z = h;
        while (z != NULL)
        {
            printf("%d", z->value);
            z = z->next;
        }
    }
}
void reverse(struct Node **head_ref) 
{ 
     struct Node *temp = NULL;   
     struct Node *current = *head_ref; 
       
   //using DLL property to update prev and next
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     //empty list or not
     if(temp != NULL ) 
        *head_ref = temp->prev; 
}      

// initializing the main function

int main()
{
    int no, j;
    printf("Enter how many number you want to convert: ");
    scanf("%d", &no);
    for(j=1;j<=no;j++){
    
 int n,i;
 printf("\n\nEnter The decimal Number: ");
 scanf("%d", &n);
 for(i=0;n>0;i++)    
{ 
  int s = n%2;
  insert_end(&head, s);
  n=n/2;    
}
reverse(&head);
printf("The binary of the given decimal number is: ");
 traverse_dll(head);
head=NULL;
    }

}

//End of the code 
