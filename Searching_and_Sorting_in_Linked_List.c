#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int value;

void print(struct node *head, struct node *tail)
{
    struct node *temp=head;
    printf ("The list is :\n");
    while(temp!=tail)
    {
        printf ("%d\n",temp->data);
        temp=temp->next;
    }
    printf ("%d\n",temp->data);
}

void linear_search(struct node *head, struct node *tail)
{
    int b,e;
    int flag=0;
    printf ("Which element you want to search ?\n");
    scanf ("%d",&b);
    
    if (head==NULL)
        printf ("EMPTY LIST\n");
    else
    {
        struct node *temp=head;
        while (temp!=NULL)
        {
            if (temp->data==b)
            {
                printf ("ELEMENT FOUND\n");
                flag=1;
                break;
            }
                temp=temp->next;
        }
        if (flag==0)
        printf ("ELEMENT NOT FOUND\n");
    }
    printf ("Which operation you want to perform ?\nPress 1 for searching\nPress 2 for sorting\nPress 3 to exit from programe\n");
    scanf ("%d",&e);
    
    switch (e)
    {
        case 1 :  linear_search (head,tail);
            break;
        case 2 : selction_sort (head,tail);
            break;
        case 3 : printf ("EXIT\n");

            break;
        default : printf ("WRONG CHOICE\n");
    }

}

int selction_sort (struct node* head, struct node* tail)
{
    int d;
    struct node *temp=head;
    struct node *min;
    int j;
    while (temp->next!=NULL)
    {
        struct node *temp1=temp;
        min=temp1;
        while(temp1!=NULL)
        {
            if (min->data>temp1->data)
                min=temp1;
            temp1=temp1->next;
        }
        j=temp->data;
        temp->data=min->data;
        min->data=j;
        temp=temp->next;
    }
    print (head,tail);
    printf ("Which operation you want to perform ?\nPress 1 for searching\nPress 2 for sorting\nPress 3 to exit from programe\n");
    scanf ("%d",&d);
    
    switch (d)
    {
        case 1 :  linear_search (head,tail);
            break;
        case 2 : selction_sort (head,tail);
            break;
        case 3 : printf ("EXIT\n");

            break;
        default : printf ("WRONG CHOICE\n");
    }
    return 0;
}

void create ()
{
    int c;
    char ch1;
    struct node *head=NULL;
    struct node *tail=NULL;
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
    printf ("Do you want to continue ?\nPress y for yes\nPress n to exit\n");
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
    printf ("Which operation you want to perform ?\nPress 1 for searching\nPress 2 for sorting\nPress 3 to exit from programe\n");
    scanf ("\n%d",&c);
    
    switch (c)
    {
        case 1 :  linear_search (head,tail);
            break;
        case 2 : selction_sort (head,tail);
            break;
        case 3 : printf ("EXIT\n");

            break;
        default : printf ("WRONG CHOICE\n");
    }
}

int main ()
{
    create();
    return 0;
}
