#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int value;
struct node *head=NULL;
struct node *tail=NULL;

void print1 (struct node *head1,struct node *tail1)
{
    struct node *temp =head1;
    while(temp->next!=NULL)
    {
        printf ("%d\n",temp->data);
        temp=temp->next;
    }
    printf ("%d\n",temp->data);
}
void print2 (struct node *head2,struct node *tail2)
{
    struct node *temp =head2;
    while(temp->next!=NULL)
    {
        printf ("%d\n",temp->data);
        temp=temp->next;
    }
    printf ("%d\n",temp->data);
}
void print (struct node *merge_head,struct node *merge_tail)
{
    struct node *temp=merge_head;
    while(temp!=merge_tail)
    {
        printf ("%d\n",temp->data);
        temp=temp->next;
    }
    printf ("%d\n",temp->data);
}

void merge (struct node *head1, struct node *tail1, struct node *head2, struct node *tail2)
{
    struct node *merge_head=NULL;
    struct node *merge_tail=NULL;
    struct node *temp1=head1;
    struct node *temp2=head2;
    
    if (temp1->data<temp2->data)
    {
        merge_head=temp1;
        merge_tail=temp1;
        temp1=temp1->next;
    }
    else
    {
        merge_head=temp2;
        merge_tail=temp2;
        temp2=temp2->next;
    }
    
    while(temp1!=NULL&&temp2!=NULL)
    {
        if (temp1->data<temp2->data)
        {
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data=temp1->data;
            merge_tail->next=temp;
            merge_tail=temp;
            temp1=temp1->next;
        }
        else
        {
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data=temp2->data;
            merge_tail->next=temp;
            merge_tail=temp;
            temp2=temp2->next;
        }
    }
a:
    if (temp1!=NULL)
    {
        merge_tail->next=temp1;
        merge_tail=temp1;
        temp1=temp1->next;
        goto a;
    }

    else if(temp2!=NULL)
    {
        merge_tail->next=temp2;
        merge_tail=temp2;
        temp2=temp2->next;
        goto a;
    }
    
    printf ("After merging the linked list is :\n");
    print (merge_head,merge_tail);
}

void create ()
{
    char ch1;
a:
    if (head==NULL)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf ("Enter the value :\n");
        scanf ("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf ("Enter the value :\n");
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
        case 'n' : return;
            break;
        default: printf ("WRONG CHOICE\n");
    }
}

int main ()
{
    printf ("Enter two sorted linked list\n");
    struct node *head1,*tail1,*head2,*tail2;
    printf ("Enter the values of 1st list :\n");
    create ();
    head1=head;
    tail1=tail;
    printf ("1st linked list :\n");
    print1 (head1,tail1);
    head=NULL;
    tail=NULL;
    printf ("Enter the values of 2nd list :\n");
    create ();
    head2=head;
    tail2=tail;
    printf ("2nd linked list :\n");
    print2 (head2,tail2);
    merge (head1,tail1,head2,tail2);
    return 0;
}
