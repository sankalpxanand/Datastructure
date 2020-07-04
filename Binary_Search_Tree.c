#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct tree
{
    int data;
    struct tree*left;
    struct tree*right;
};
struct tree*root=NULL;

int main()
{
    int a,b,c,d,e;
z:
    printf ("Which operation d you want to perform ?\nPress 1 for insertion\nPress 2 for deletion\nPress 3 for searching\n");
    scanf ("%d",&a);
    switch (a)
    {
        case 1: insertion();
            break;
       case 2: deletion();
            break;
       case 3: searching();
            break;
        default : printf ("WRONG CHOICE\n");
    }

    printf ("Do you want to continue ?\nPress 1 to continue\nPress 2 to exit\n");
    scanf ("%d",&b);
    switch (b)
    {
        case 1: goto z;
            break;
        case 2: printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
    }
    printf ("Do you want to transverse the tree ?\nPress 1 to continue\nPress 2 to exit\n");
    scanf ("%d",&c);
x:
    switch (c)
    {
        case 1: printf ("Press 1 for INORDER\nPress 2 for PREORDER\nPress 3 for POSTORDER\n");
            scanf ("%d",&d);
            switch(d)
            {
                case 1: inorder(root);
                    break;
                case 2: pre_order(root);
                    break;
                case 3: post_order(root);
                    break;
                default: printf ("WRONG CHOICE\n");
            }
    
            printf ("\nDo you want to continue transversing ?\nPress 1 to continue\nPress 2 to exit\n");
            scanf ("%d",&e);
            switch(e)
            {
                    case 1: goto x;
                        break;
                    case 2: printf ("EXIT\n");
                        break;
                    default: printf ("WRONG CHOICE\n");
            }
            break;
        case 2: printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
    }
    
}

int print(struct tree* node)
{
    if(node==NULL)
        return 0;
    else
    {
        printf ("%d",node->data);
        if (node->left!=NULL)
            printf ("L:%d",node->left->data);
        if (node->right!=NULL)
            printf ("R:%d",node->right->data);
    }
    printf("\n");
    print(node->left);
    print(node->right);
    
    return 0;
}

struct tree* insertion_helper (int value,struct tree* node)
{
    struct tree *newnode=(struct tree*)malloc(sizeof(struct tree));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    if(node==NULL)
        return newnode;
    if(value<node->data)
        node->left=insertion_helper(value,node->left);
    else if (value>node->data)
        node->right=insertion_helper(value, node->right);
    return node;
}

int insertion ()
{
    int value,a;
z:
    printf("Enter the value:\n");
    scanf ("%d",&value);
    root=insertion_helper(value,root);
    printf ("Do you want to add more ?\nPress 1 to continue\nPress 2 to exit\n");
    scanf ("%d",&a);
    switch (a)
    {
        case 1: goto z;
            break;
        case 2: printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
    }
    print(root);
    return 0;
}

struct tree* deletion_helper (int value,struct tree *node)
{
    int a;
    if (node==NULL)
        return NULL;
    if(value<node->data)
    {
        node->left=deletion_helper(value, node->left);
        return node;
    }
    else if (value>node->data)
    {
        node->right=deletion_helper(value, node->right);
        return node;
    }
    else
        {
            if (node->left==NULL&&node->right==NULL)
            {
                free(node);
                return NULL;
            }
            else if (node->right==NULL)
            {
                struct tree *temp=node->left;
                node->left=NULL;
                free(node);
                return temp;
            }
            else if (node->left==NULL)
            {
                struct tree *temp=node->right;
                node->right=NULL;
                free(node);
                return temp;
            }
            else
            {
                printf ("Press 1 if you want the maximum element from left side\nPress 2 if you want the minimum element from right side\n");
                scanf ("%d",&a);
                switch(a)
                {
                    case 1: printf ("From left hand side\n");
                        struct tree* minNode=node->left;
                        while(minNode->right!=NULL)
                            minNode=minNode->right;
                        node->data=minNode->data;
                        free(minNode);
                        return node;
                        break;
                    case 2: printf("From right hand side\n");
                        struct tree* minNode1=node->right;
                        while(minNode1->left!=NULL)
                            minNode1=minNode1->left;
                        node->data=minNode1->data;
                        free(minNode1);
                        return node;
                        break;
                    default: printf ("WRONG CHOICE\n");
                }
            }
        }
    return 0;
}

int deletion ()
{
    int value,b;
    
    if (root==NULL)
    {
        printf ("Tree is empty\n");
        return 0;
    }
z:
        printf ("Which element you want to delete ?\n");
        scanf ("%d",&value);
        root=deletion_helper(value,root);
    
        printf ("Do you want to continue ?\nPress 1 to continue\nPress 2 to exit\n");
        scanf ("%d",&b);
        switch (b)
        {
            case 1: goto z;
                break;
            case 2: printf ("EXIT\n");
                break;
            default: printf ("WRONG CHOICE\n");
        }
    print(root);
    return 0;
}
bool search_helper(int value,struct tree *node)
{
    if (node==NULL)
        return false;
    if (value==node->data)
        return true;
    else
    {
        if (value<node->data)
            return search_helper(value, node->left);
        if (value>node->data)
            return search_helper(value, node->right);
    }
    if (value!=node->data)
        printf ("The element does not exist\n");
    return 0;
}
int searching ()
{
    int value,b;
    if (root==NULL)
   {
       printf ("Tree is empty\n");
       return 0;
   }
z:
    printf ("Which element you want to search\n");
    scanf ("%d",&value);
    bool result=search_helper(value,root);
    if(result)
        printf ("Value is found\n");
    else
        printf ("Valiue is not found\n");
    printf ("Do you want to continue ?\nPress 1 to continue\nPress 2 to exit\n");
    scanf ("%d",&b);
    switch (b)
    {
        case 1: goto z;
            break;
        case 2: printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
    }
    return 0;
}
int inorder(struct tree*node)
{
    if(node==NULL)
        return 0;
    inorder(node->left);
    printf("%d\t",node->data);
    inorder(node->right);
    
    return 0;
}
int pre_order(struct tree*node)
{
    if(node==NULL)
        return 0;
    printf("%d\t",node->data);
    pre_order(node->left);
    pre_order(node->right);
    
    return 0;
}
int post_order(struct tree*node)
{
    if(node==NULL)
        return 0;
    post_order(node->left);
    post_order(node->right);
    printf("%d\t",node->data);
    
    return 0;
}
