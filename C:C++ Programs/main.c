// Declaring CSLL to sort the list entry according to ascending order

#include <stdio.h>
#include <stdlib.h>
typedef struct Node CSLL;
struct Node
{
  int value;
  CSLL *next;
};


// declaring all the function
int Read_No_Of_Nodes ();
int Read_Element ();
void insert_end (CSLL **, int);
void traverse_csll (CSLL *);
void Merge (CSLL *, CSLL *);
void Sort (CSLL **);
void Swap (CSLL * a, CSLL * b);


int
Read_No_Of_Nodes ()
{
  int length;
  scanf ("%d", &length);
  return length;
}

int
Read_Element ()
{
  int element;
  scanf ("%d", &element);
  return element;
}

void
insert_end (CSLL ** h, int val)
{
  CSLL *newnode, *temp;
  newnode = (struct Node *) malloc (sizeof (CSLL *));
  newnode->value = val;
  newnode->next = NULL;

  if (*h == NULL)
    {
      *h = newnode;
      newnode->next = newnode;
      return;
    }
  temp = *h;
  while (temp->next != *h)
    {
      temp = temp->next;
    }
  if (newnode->value > temp->value)
    {
      temp->next = newnode;
      newnode->next = *h;
    }
  else
    {
      while (newnode->value < temp->value)
	{
	  printf
	    ("Elements Entry should be in ascending order (Enter Valid Entry):");
	  val = Read_Element ();
	  newnode->value = val;
	}
      temp->next = newnode;
      newnode->next = *h;
    }
}

void
traverse_csll (CSLL * h)
{

  int i;
  CSLL *z;
  if (h == NULL)
    printf ("\nList is empty");
  else
    {
      z = h;
      printf ("%d ", z->value);
      z = z->next;
      while (z != h)
	{
	  printf ("%d ", z->value);
	  z = z->next;
	}
    }
}


void
merge (CSLL ** h1, CSLL ** h2)	//used to merge the two lists
{
  CSLL *temp1, *temp2;
  temp1 = *h1;
  temp2 = *h2;
  while (temp1->next != *h1)
    {
      temp1 = temp1->next;
    }
  while (temp2->next != *h2)
    {
      temp2 = temp2->next;
    }
  temp1->next = *h2;
  temp2->next = *h1;
}

void
sort (CSLL ** h)		//function to sort the merged list 
{
  int swapped;
  CSLL *ptr1;
  CSLL *ptr2 = *h;

  // Checking for empty list 
  if (*h == NULL)
    return;

  do
    {
      swapped = 0;
      ptr1 = *h;

      while (ptr1->next != ptr2)
	{
	  if (ptr1->value > ptr1->next->value)
	    {
	      Swap (ptr1, ptr1->next);
	      swapped = 1;
	    }
	  ptr1 = ptr1->next;
	}
      ptr2 = ptr1;
    }
  while (swapped);
}


void
Swap (CSLL * x, CSLL * y)
{
  int temp = x->value;
  x->value = y->value;
  y->value = temp;
}

// main function
int
main ()
{
  struct Node *head1 = NULL, *head2 = NULL;
  int n, i, s, x;
  // Saving the ascending elements in list 1
  printf ("Enter the number of Elements: ");
  n = Read_No_Of_Nodes ();
  printf ("Enter the elements:\n");
  for (int i = 0; i < n; i++)
    {
      s = Read_Element ();
      insert_end (&head1, s);
    }
  printf ("List 1 elements:\n");
  traverse_csll (head1);
  printf ("\n");


  // saving the ascending elements in list 2
  printf ("Enter the number of Elements: ");
  n = Read_No_Of_Nodes ();
  printf ("Enter the elements:\n");
  for (int i = 0; i < n; i++)
    {
      s = Read_Element ();
      insert_end (&head2, s);
    }
  printf ("List 2 elements:\n");
  traverse_csll (head2);


//      merging both the list in ascending order
  merge (&head1, &head2);
  sort (&head1);
  printf ("\nSorted Merge list of above two list is as follow:\n");
  traverse_csll (head1);


}
