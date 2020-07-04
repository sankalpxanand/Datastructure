#include<stdio.h>
int size = 10;
int top = -1;
int ele;
int stack[];
int main ()
{
    int a;
    printf ("Which operation you want to perform ?\nEnter 1 for push\nEnter 2 for pop\nEnter 3 to exit\n");
    scanf ("%d",&a);
    switch (a)
    {
        case 1: push ();
            break;
        case 2: pop();
            break;
        case 3: printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
}
int push ()
{
    int b,c;
    if (top==size-1)
    {
        printf ("OVERFLOW\n");
        display();
        printf ("Press 1 to pop out an element\nPress 2 to exit\n");
        scanf ("%d",&b);
        switch (b)
        {
            case 1: pop();
                break;
            case 2: printf ("EXIT\n");
                break;
            default : printf ("WRONG CHOICE\n");
        }
    }
    else
    {
        printf ("Enter the element :\n");
        scanf ("%d",&ele);
        top++;
        stack[top]=ele;
    
    display();
    printf ("Press 1 if you want to push more elemnts\nPress 2 to pop out an element\nPress 3 to exit\n");
    scanf ("%d",&c);
    switch (c)
    {
        case 1: push ();
            break;
        case 2: pop();
            break;
        case 3: printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
    }
    return 0;
}
int pop ()
{
    int d,e;
    if (top==-1)
    {
        printf ("UNDERFLOW\n");
        display();
           printf ("Press 1 if you want to push more elemnts\nPress 2 to exit\n");
           scanf ("%d",&d);
           switch (d)
           {
               case 1: push ();
                   break;
               case 2: printf ("EXIT\n");
                   break;
               default : printf ("WRONG CHOICE\n");
           }
    }
    else
    {
        ele=stack[top];
        top--;
        size--;
    }
    display();
    printf ("Press 1 if you want to push more elemnts\nPress 2 to pop out an element\nPress 3 to exit\n");
    scanf ("%d",&e);
    switch (e)
    {
        case 1: push ();
            break;
        case 2: pop();
            break;
        case 3: printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
    return 0;
}
int display ()
{
    int i;
    if (top==-1)
    {
        printf ("EMPTY STACK\n");
    }
    else
    {
        printf ("The stack is :\n");
                for (i=top;i>=0;i--)
                   printf ("%d\n",stack[i]);
    }
    return 0;
}

