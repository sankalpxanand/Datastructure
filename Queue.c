#include<stdio.h>
int front=-1;
int rear=-1;
int size = 10;
int queue[];
int ele;
int main ()
{
    int a;
    printf ("Which operation you want to perform ?\nPress 1 for Enqueue\nPress 2 for Dequeue\nPress 3 to exit from programe\n");
    scanf ("%d",&a);
    switch (a)
    {
        case 1: enqueue();
            break;
        case 2: dequeue();
            break;
        case 3 : printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
}
int enqueue ()
{
    int b,c;
    if (rear>=size-1)
    {
        printf ("Queue is full\n");
        printf ("Press 1 to dequeue an element\nPress 2 to exit from programe\n");
          scanf ("%d",&b);
          switch (b)
          {
            
              case 1: dequeue ();
                  break;
              case 2: printf ("EXIT\n");
                  break;
              default : printf ("WRONG CHOICE\n");
          }
    }
    else
    {
           if (front==-1&&rear==-1)
           {
               front++;
               rear++;
           }
        else
            rear++;
        printf ("Enter the element : \n");
            scanf ("%d",&ele);
        queue[rear]=ele;
        display();
    
    printf ("Press 1 to enqueue another element\nPress 2 to dequeue an element\nPress 3 to exit from programe\n");
    scanf ("%d",&c);
    switch (c)
    {
        case 1: enqueue ();
            break;
        case 2: dequeue ();
            break;
        case 3: printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
    }
    return 0;
}
int dequeue ()
{
    int d,e;
    if (front>=rear)
    {
        printf ("EMPTY QUEUE\n");
        printf ("Press 1 to enqueue an element\nPress 2 to exit from programe\n");
           scanf ("%d",&d);
           switch (d)
           {
               case 1: enqueue ();
                   break;
               case 2: printf ("EXIT\n");
                   break;
               default : printf ("WRONG CHOICE\n");
           }
    }
    else
    {
        ele=queue[front];
        front++;
        display ();
        printf ("Press 1 to enqueue an element\nPress 2 to dequeue an element\nPress 3 to exit from programe\n");
           scanf ("%d",&e);
           switch (e)
           {
               case 1: enqueue ();
                   break;
               case 2: dequeue ();
                   break;
               case 3: printf ("EXIT\n");
                   break;
               default : printf ("WRONG CHOICE\n");
           }
    }
    return 0;
}
int display()
{
    int i;
    if (front>rear)
    printf ("EMPTY QUEUE\n");
    else
    {
        printf ("The queue is :\n");
        for(i=front;i<=rear;i++)
            printf ("%d\n",queue[i]);
    }
    return 0;
}
