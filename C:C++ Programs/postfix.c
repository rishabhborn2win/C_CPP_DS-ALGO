// Program to evaluate Postfix expression

#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 100 //define max size of stack
#define POSTFIXSIZE 100   //define max number of entry in postfix expression

int stack[MAXSTACK];
int top = -1;   //define top -1 as first index of array is 0 

void push(int item)
{

    if (top >= MAXSTACK - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}


void EvalPostfix(char postfix[])
{

    int i, val, A, B;
    char ch;

    for (i = 0; postfix[i] != ')'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {

            A = pop();
            B = pop();

            switch (ch) 
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            
            case '%':
                val = B % A;
                break;
            }
            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

int main()
{

    int i, n, *p;
    char postfix[POSTFIXSIZE];
    printf(" \nEnter postfix expression in terms,\npress enter and type ) to evaluate expression : ");


    for (i = 0; i <= POSTFIXSIZE - 1; i++) {
        scanf("%c", &postfix[i]);

        if (postfix[i] == ')') 
        {
            break;
        }
    }

    EvalPostfix(postfix);

    return 0;
}


