// DLL deletion of the element of the particular entry of the element

#include <stdio.h>
#include <stdlib.h>
typedef struct Node DLL;
struct Node
{
    int value;
    DLL *prev;
    DLL *next;
} *head = NULL, *head1=NULL;

int read_no_of_nodes();
int read_element();
void insert_end(DLL **, int);
void traverse_dll(DLL *);
void setDelete(DLL *, DLL *);
void delete_x(DLL **, int);


int read_no_of_nodes()
{
    int size;
    printf("Enter No of Integers in the list: ");
    scanf("%d", &size);
    return size;
}

int read_element()
{
    int x;
    scanf("%d", &x);
    return x;
}

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
    if(newnode->value>temp->value){
    temp->next = newnode;
    newnode->prev = temp;
    }
    else{
        	while(newnode->value<temp->value)
		{
		printf("Elements Entry should be in ascending order (Enter Valid Entry):");
	    val = read_element();
		newnode->value = val;
		}
		temp->next = newnode;
    	newnode->prev = temp;
    }
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
            printf("%d ", z->value);
            z = z->next;
        }
    }
}

void setDelete( DLL *h, DLL *i){
    DLL *temp1;
    DLL *temp2;
    
    for(temp1 = h; temp1; temp1 = temp1->next){
        for(temp2 = i; temp2; temp2 =  temp2->next){
            if(temp1->value == temp2->value){
                int x = temp1->value;
                delete_x(&h, x);
            }
        }
    }
}

void delete_x(DLL **t, int x)
{
    
    if (*t == NULL)
    {
        printf("List is empty ");
        return;
    }
    struct Node *temp = *t;

    while (temp->value != x && temp != NULL)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Deletion not possible");
        return;
    }

    if (temp->prev == *t && temp->next == NULL)
    {

        *t = NULL;
        free(temp);
        return;
    }

    if (temp == *t)
    {
        *t = (*t)->next;
        (*t)->prev = NULL;
        free(temp);
        return;
    }

    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}



// intialising the main function

int main()
{

    int n, i, s, x, p;
    n = read_no_of_nodes(); 

    for (int i = 0; i < n; i++) 
    {
        s = read_element();
        insert_end(&head, s);
    }
    printf("Sorted List-1 is As Follow: \n");
    traverse_dll(head);

    printf("\n");
    
        int m, j, r;
    m = read_no_of_nodes(); 

    for (int j = 0; j < m; j++) 
    {
        r = read_element();
        insert_end(&head1, r);
    }
    printf("Sorted List-2 is As Follow: \n");
    traverse_dll(head1);


 
  
  setDelete(head, head1);
  printf("\n");
  printf("The Sorted list-1 After deleting the Matched element from List-2: ");
  traverse_dll(head);
}




