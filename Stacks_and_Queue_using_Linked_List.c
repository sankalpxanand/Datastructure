#include<stdio.h>

int stack();
int queue();

struct node
{
    int data;
    struct node *next;
};
int ele;
int main ()
{
    int a,b;
z:
    printf ("1.STACK\n2.QUEUE\n");
    scanf ("%d",&a);
    switch(a)
    {
        case 1: stack();
            break;
        case 2: queue();
            break;
        default: printf ("WRONG CHOICE\n");
    }
    printf ("Do you want to choose again ?\nPress 1 to continue\nPress 0 to exit\n");
    scanf ("%d",&b);
    switch (b)
    {
        case 1: goto z;
            break;
        case 0: printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
                        
    }
}

void push (int ele, struct node*top);
void pop (struct node*top);
void display(int ele, struct node*top);

int stack()
{
    int a;
z:
    printf ("1.PUSH\n2.POP\n3.DISPLAY\n");
    scanf ("%d",&a);
    struct node* top=(struct node*)malloc(sizeof(struct node));
    top=NULL;
    switch(a)
    {
        case 1: push(ele,top);
            break;
        case 2: pop(top);
            break;
        case 3: display(ele,top);
            break;
        default: printf ("WRONG CHOICE\n");
    }
    return 0;
}
void push(int ele,struct node*top)
{
    printf ("Enter the element you want to push : ");
    scanf("%d",&ele);
    struct node *new=(struct node*)malloc(sizeof(struct node));
    
    new->data=ele;
    if(top==NULL)
    {
        new->next=NULL;
        top=new;
    }
    else
    {
        new->next=top;
        top=new;
    }
    
    display(ele,top);
    
}
void pop(struct node*top)
{
    int a;
    if (top==NULL)
    {
    z:
        printf ("EMPTY STACK\n");
        printf("Press 1 to push an element\nPress 0 to go to exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: push(ele,top);
                break;
            case 0: printf ("EXIT\n");
                break;
            default: printf ("WRONG CHOICE\n");
        }
    }
    else
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=top;
        top=temp->next;
        temp->next=NULL; // or free(temp)
        if(top==NULL)
            goto z;
        else
        display(ele,top);
    }
}
void display(int ele, struct node*top)
{
    int a;
    if (top==NULL)
    {
          printf ("EMPTY STACK\n");
          printf("Press 1 to push an element\nPress 0 to exit\n");
          scanf("%d",&a);
          switch(a)
            {
                case 1: push(ele, top);
                    break;
                case 0: printf ("EXIT\n");
                    break;
                default: printf ("WRONG CHOICE\n");
            }
    }
      else
      {
          struct node *temp=top;
          printf ("The stack is :\n");
          while(temp!=NULL)
          {
              printf ("%d\n",temp->data);
              temp=temp->next;
          }
      
          printf("Press 1 to push an element\nPress 2 to pop to an element\nPress 0 to exit\n");
          scanf("%d",&a);
          switch(a)
          {
              case 1: push(ele, top);
                  break;
              case 2: pop(top);
                  break;
              case 0: printf ("EXIT\n");
                  break;
              default: printf ("WRONG CHOICE\n");
          }
      }
}

void enqueue(int ele, struct node *front, struct node *rear);
void dequeue(struct node *front, struct node *rear);
void display_q(int ele,struct node *front, struct node *rear);

int queue()
{
    int a;
    printf ("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
    scanf ("%d",&a);
    struct node *front=(struct node*)malloc(sizeof(struct node));
    struct node *rear=(struct node*)malloc(sizeof(struct node));
    front=NULL;
    rear=NULL;
    switch(a)
    {
        case 1: enqueue(ele,front,rear);
            break;
        case 2: dequeue(front,rear);
            break;
        case 3 : display_q(ele,front,rear);
            break;
        default : printf ("WRONG CHOICE\n");
    }
    return 0;
}
void enqueue(int ele,struct node *front, struct node *rear)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf ("Enter the element you want to enqueue : ");
    scanf("%d",&ele);
    new->data=ele;
    new->next=NULL;
    if(rear==NULL)
    {
        front=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
    display_q(ele,front,rear);
}
void dequeue(struct node *front, struct node *rear)
{

    if(front==NULL)
    {
        printf ("EMPTY QUEUE\n");
        return ;
    }
    else
    {
        struct node *temp=front;
        front=front->next;
        temp->next=NULL; // or free(temp)
        if(front==NULL)
            printf("EMPTY QUEUE\n");
        else
        display_q(ele,front,rear);
    }
}
void display_q(int ele,struct node *front, struct node *rear)
{
    int a;
    if(front==NULL)
    {
        printf ("EMPTY QUEUE\n");
        return ;
    }
    else
    {
        struct node *temp=front;
        printf("The queue is :\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    
        printf("Press 1 to enqueue an element\nPress 2 to dequeue an element\nPress 0 to exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: enqueue(ele,front,rear);
                break;
            case 2: dequeue(front,rear);
                break;
            case 0: printf ("EXIT\n");
                break;
            default: printf ("WRONG CHOICE\n");
        }
      }
}
