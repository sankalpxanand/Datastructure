//
//  main.c
//  Single list - insertion
//
//  Created by Sankalp Anand on 02/03/20.
//  Copyright © 2020 Sankalp Anand. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

int value;
void print (struct node*head, struct node*tail)
{
    struct node*temp = head;
    while(temp!=tail)
    {
        printf ("\n%d",temp->data);
        temp=temp->next;
    }
    printf ("\n%d\n",temp->data);
}
void insertatbeg(struct node*head, struct node*tail,int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf ("Enter the number to be inserted : \n");
    scanf ("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    temp=head;
    newnode->next=head;
    head=newnode;
    print (head,tail);
    Singular (head,tail);
}
void insertatspec(struct node*head, struct node*tail)
{
    int i,pos;
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf ("Enter the number to be inserted : \n");
    scanf ("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    temp=head;
    printf ("At which position you what to insert ? :\n");
    scanf ("%d",&pos);
    for (i=0;i<pos-1;i++)
        temp=temp->next;
    newnode->next=temp->next;
    temp->next=newnode;
    print (head,tail);
    Singular (head,tail);
}
void insertatend (struct node* head, struct node* tail)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf ("Enter the number to be inserted : \n");
    scanf ("%d",&value);
    newNode->data=value;
    newNode->next=NULL;
    tail->next=newNode;
    tail=newNode;
    print (head,tail);
    Singular(head,tail);
}
int Singular (struct node*head, struct node*tail)
   {
       char ch1;
       printf ("At which location you want to insert the element :\n");
       printf ("Press\n'b' for beginning\n's' for specific\n'e' for end\n'x' for exit\n");
       scanf ("\n%c",&ch1);
       switch (ch1)
       {
           case 'b' : insertatbeg(head,tail,value);
           break;
           case 's' : insertatspec(head,tail);
           break;
           case 'e' : insertatend(head,tail);
           break;
           case 'x' : printf ("EXIT\n");
           break;
           default : printf ("WRONG CHOICE");
       }
       return 0;
   }
void create_single ()
{
    struct node* head=NULL;
    struct node* tail=NULL;
    char ch3;
    a:
    if (head==NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf ("Enter the number :\n");
        scanf ("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
    }
        else
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf ("Enter the number :\n");
        scanf ("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        tail->next=newnode;
        newnode->next=NULL;
        tail=newnode;
    }
        printf ("Do you want to continue ? \ny for yes\nn for no\n");
        scanf ("\n%c",&ch3);
        switch (ch3)
            {
                case 'y' : goto a;
                break;
                case 'n' : printf ("EXIT\n");
                break;
                default : printf ("WRONG CHOICE");
            }
    print (head,tail);
    Singular (head,tail);
}
   void insertatendc(struct node*head, struct node*tail)
   {
              struct node* newnode = (struct node*)malloc(sizeof(struct node));
              struct node* temp = (struct node*)malloc(sizeof(struct node));
              printf ("Enter the number to be inserted : \n");
              scanf ("%d",&value);
              newnode->data=value;
              newnode->next=NULL;
              temp=head;
              while (temp->next != NULL)
                  temp=temp->next;
              temp->next=newnode;
              newnode->next=head;
              temp=newnode;
      print (head,tail);
      Circular (head,tail);
   }

int Circular (struct node*head, struct node*tail)
{
    char ch5;
    printf ("At which location you want to insert the element :\n");
    printf ("Press\n'b' for beginning\n's' for specific\n'e' for end\n'x' for exit\n");
    scanf ("\n%c",&ch5);
    switch (ch5)
    {
        case 'b' : insertatbeg(head,tail,value);
        break;
        case 's' : insertatspec(head,tail);
        break;
        case 'e' : insertatendc(head,tail);
        break;
        case'x' : printf ("EXIT\n");
        break;
        default : printf ("WRONG CHOICE");
    }
    return 0;
}

void create_circular ()
{
    struct node* head=NULL;
    struct node* tail=NULL;
    char ch4;
    int value;
    b:
    if (head==NULL)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf ("Enter the number :\n");
        scanf ("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
    }
        else
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf ("Enter the number :\n");
        scanf ("%d",&value);
        newnode->data=value;
        newnode->next=NULL;
        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
    }
        printf ("Do you want to continue ? \ny for yes\nn for no\n");
        scanf ("\n%c",&ch4);
        switch (ch4)
            {
                case 'y' : goto b;
                break;
                case 'n' : printf ("EXIT");
                break;
                default : printf ("WRONG CHOICE");
            }
    print (head,tail);
    Circular(head,tail);
}
    
int main ()
{
    char ch;
    printf ("Which link list you want ?\n");
    printf ("Press 's' for Singular and 'c' for Circular\n");
    scanf ("%c",&ch);
    switch (ch)
    {
        case 's' : create_single();
        break;
        case 'c' : create_circular();
        break;
        default : printf ("WRONG CHOICE");
    }
}


