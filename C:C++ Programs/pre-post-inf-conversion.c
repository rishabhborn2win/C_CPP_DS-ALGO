//Code For Conversion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
char data;
struct tree *left;
struct tree *right;
}*new1;

new1 stack[30];

int top=-1;

//functions

new1 newnode(char b)
{
    new1 temp;
    temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=b;
    temp->left=NULL;
    temp->right=NULL;
    return(temp);
}


void push(new1 temp)
{
    stack[++top]=temp;
}


new1 pop()
{
    new1 p;
    p=stack[top--];
    return(p);
}

//Function to convert it into inorder
void inorder(new1 t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%c",t->data);
        inorder(t->right);
    }
}

//Function to convert in preorder
void preorder(new1 t)
{
    if(t!=NULL)
    {
        printf("%c",t->data);
        preorder(t->left);
        inorder(t->right);
    }
}

//Function to convert in the post order
void postorder(new1 t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%c",t->data);
    }
}

//intialising the main function
void main()
{
    char arr[20];
    new1 temp,t;int j,i;
    
    printf("\nPLease Input Postfix Expression : ");
    gets(arr);
    
    
    for(i=0 ; arr[i]!='\0' ; i++ )
    {
        if(arr[i]=='*' || arr[i]=='/' || arr[i]=='+' || arr[i]=='-')
        {
            temp=newnode(arr[i]);
            temp->right=pop();
            temp->left=pop();
            push(temp);
        }
        else
        {
            temp=newnode(arr[i]);
            push(temp);
        }
    }
    
    printf("\n InOrder : ");
    inorder(temp);
    printf("\n PreOrder : ");
    preorder(temp);
    printf("\n PostOrder : ");
    postorder(temp);

}