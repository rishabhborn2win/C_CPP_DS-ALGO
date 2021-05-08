//Linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node SLL;
struct Node
{
  int data;
  struct Node *next;
}*head = NULL;

//defining the set of operations
SLL *insert_end(SLL *, int);
void insert_before (SLL *, int, int);
void insert_after (SLL *, int, int);
int delete (SLL *, int);
int delete_begin (SLL *);
int delete_end (SLL *);
void Traverse_SLL(SLL *);
void search (SLL *, int);

SLL *insert_end(SLL *h, int a)
{
  SLL *new_node;
  
  //creating a node and filling the fields
  new_node = (SLL *) malloc (sizeof (SLL *));
  new_node->data = a;
  new_node->next = NULL;


  if (head == NULL)
    {
      head = new_node;
      
    }
  else
    {
      SLL *temp = head;
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->next = new_node;
      
    }
    return head;
}

// Display the elements in the list
void Traverse_SLL(SLL *h)
{
    int i;
    SLL *t;
    if (h == NULL)
        printf("\nList is empty");
    else
    {
        printf("\nThe elements in list are...\n");
        t = h;
        while (t != NULL)
        {
            printf("%d\n", t->data);
            t = t->next;
        }
    }
}

int main ()
{
  int a;
  printf ("Enter the value to be entered in the list: ");
  scanf ("%d", &a);
    head = insert_end(head, a);
    head = insert_end(head, 10);
    head = insert_end(head, 11);
  Traverse_SLL(head);
  return 0;
}
