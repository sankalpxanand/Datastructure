#include<stdio.h>
#include<stdlib.h>
int value;
struct node
{
    int data;
    struct node* next;
};

void print(struct node* head,struct node* tail)
{
    struct node* temp=head;
    while(temp!=tail)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
    printf("\n%d\n",temp->data);
}

void Singular (struct node*head, struct node*tail)
{
    int i,pos,count=0;
    char ch4;
      struct node* temp=head;
    for(count=0;temp!=NULL;count++)
        temp=temp->next;
    if (head->next==NULL)
    printf ("EMPTY LIST\n");
    else
    {
        printf ("From which position you want to delete the elemment ?\nPress 'b' for beginning\nPress 's' for specefication position\nPress 'e' for end\nPress 'x' to exit from programe\n");
    scanf ("\n%c",&ch4);
    switch (ch4)
    {
        case 'b' : printf ("From beginning\n");
            struct node* temp1=head;
            temp1=head->next;
            head=temp1;
            free(temp);
             print (head,tail);
            Singular (head,tail);
            break;
        case 's' : printf ("From specific position\n");
            printf ("From which specefic position you want to delet it ?;\n");
            scanf ("%d",&pos);
            if (pos>count)
                printf ("WRONG CHOICE\n");
            else
            {
                for (i=0;i<pos-1;i++)
                temp=temp->next;
            struct node* temp2=temp->next;
            temp->next=temp->next->next;
                temp2->next=NULL;
            free(temp2);
             print (head,tail);
            Singular (head,tail);
            }
            break;
        case 'e' : printf ("From end position");
            while (temp->next!=tail)
                temp=temp->next;
            free(tail);
            tail=temp;
            tail->next=NULL;
             print (head,tail);
            Singular (head,tail);
            break;
        case 'x' : printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
    }
}

void Circular (struct node*head, struct node*tail)
{
    int i,pos,count=0;
    char ch5;
    struct node* temp=head;
    for(count=0;temp!=NULL;count++)
           temp=temp->next;
    
    printf ("From which position you want to delete the elemment ?\nPress 'b' for beginning\nPress 's' for specefication position\nPress 'e' for end\nPress 'x' to exit from programe\n");
    scanf ("\n%c",&ch5);
    switch (ch5)
    {
        case 'b' : printf ("From beginning\n");
            temp=head->next;
            tail->next=temp;
            free(head);
            head=temp;
            print (head,tail);
            Circular (head,tail);
            break;
        case 's' : printf ("From specific position\n");
            printf ("From which specefic position you want to delet it ?;\n");
            scanf ("%d",&pos);
            if (pos>count)
                printf ("WRONG CHOICE\n");
            else
            {
                for (i=0;i<pos-1;i++)
                temp=temp->next;
                struct node* temp2=temp->next;
                temp->next=temp->next->next;
                free(temp2);
            }
            print (head,tail);
            Circular (head,tail);
            break;
        case 'e' : printf ("From end position");
            while (temp->next!=tail)
                temp=temp->next;
            free(tail);
            tail=temp;
            tail->next=head;
            print (head,tail);
            Circular (head,tail);
            break;
        case 'x' : printf ("EXIT\n");
            break;
        default : printf ("WRONG CHOICE\n");
    }
}

void create_singular ()
{
    struct node* head=NULL;
    struct node* tail=NULL;
    
    char ch3;
    b:
    if (head==NULL)
    {
        printf ("Enter the number : \n");
        scanf ("%d",&value);
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        head=temp;
        tail=temp;
    }
    else
    {
        printf ("Enter the number : \n");
        scanf ("%d",&value);
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
    printf ("Do you want to continue ?\ny for yes\nn for no\n");
    scanf ("\n%c",&ch3);
    switch (ch3)
    {
            case 'y' : goto b;
            break;
            case 'n' : printf ("EXIT\n");
            break;
            default : printf ("WRONG CHOICE");
    }
    print (head,tail);
    Singular (head,tail);
}

void create_circular ()
{
    struct node* head = NULL;
    struct node* tail = NULL;
    
    char ch2;
    a:
    if (head==NULL)
    {
        printf ("Enter the number :\n");
        scanf ("%d",&value);
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        head=temp;
        tail=temp;
    }
    else
    {
        printf ("Enter the number :\n");
        scanf ("%d",&value);
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
        tail->next=head;
    }
    printf ("Do you want to continue ?\ny for yes\nn for no\n");
    scanf ("\n%c",&ch2);
    switch (ch2)
    {
            case 'y' : goto a;
            break;
            case 'n' : printf ("EXIT\n");
            break;
            default : printf ("WRONG CHOICE\n");
    }
    print (head,tail);
    Circular (head,tail);
}

int main ()
{
    char ch1;
    printf ("Which list you want :\nPress 's' for singular\nPress 'c' for circular\n");
    scanf ("\n%c",&ch1);
    switch (ch1)
    {
            case 's' : create_singular ();
            break;
            case'c' : create_circular ();
            break;
            default : printf ("WRONG CHOICE");
    }
}
