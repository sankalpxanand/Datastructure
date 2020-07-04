#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
int value;

void print (struct node *head, struct node *tail)
{
    struct node*temp=head;
        while(temp!=tail)
        {
            printf ("\n%d",temp->data);
            temp=temp->next;
        }
        printf ("\n%d\n",temp->data);
    }



int count (struct node*head, struct node*tail)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp=head;
    int count=0;
 while(temp!=NULL)
  {
      count++;
      temp=temp->next;
  }
  printf ("Number of nodes are : %d\n",count);
    return 0;
}

int reverse (struct node* head, struct node* tail)
{
    struct node *forward,*current,*prev=NULL;
    current=head;
    while (current!=NULL)
    {
        forward=current->next;
        current->next=prev;
        prev=current;
        current=forward;
    }
    tail=head;
    head=prev;
    print (head,tail);
    return 0;
}

void create ()
{

    struct node*head = NULL;
    struct node*tail = NULL;
    char ch1;
a:
  
    if (head==NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
          printf ("Enter the value : \n");
          scanf ("%d",&value);
          newnode->data=value;
          newnode->next=NULL;
          head=newnode;
          tail=newnode;
    }
    else
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
          printf ("Enter the value : \n");
          scanf ("%d",&value);
          newnode->data=value;
          newnode->next=NULL;
          tail->next=newnode;
          tail=newnode;
    }
    printf ("Do you want to continue ?\nPress y to continue\nPress n to exit\n");
    scanf ("\n%c",&ch1);
    
    switch (ch1)
    {
        case 'y' : goto a;
            break;
        case 'n' : printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
    print(head,tail);
    count(head,tail);
    reverse(head,tail);
}

int main ()
{
    create();
    return 0;
}
