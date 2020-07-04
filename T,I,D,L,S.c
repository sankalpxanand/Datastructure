#include<stdio.h>

int Transverse (int a[],int *size);
int Insertion (int a[],int *size);
int Deletion (int a[],int *size);
int Linear_search (int a[],int *size);
int Selection_sort(int a[],int *size);

int main ()
{
    int a[50],size,i,b,c;
    printf ("Enter the size of array : \n");
    scanf ("%d",&size);
    if (size>50)
        printf ("INVALID SIZE\n");
    else
    {
        printf ("Enter the elements of array : \n");
        for (i=0;i<size;i++)
        {
            scanf ("%d",&a[i]);
        }
    
    printf ("The array is :\n");
    for (i=0;i<size;i++)
        printf ("%d\t",a[i]);
        printf("\n");
    z:
        printf ("Which opertaion you want to perform ?:\n1.Transverse\n2.Insertion\n3.Deletion\n4.Linear search\n5.Selection sort\n");
        scanf("%d",&b);
        switch(b)
        {
            case 1: Transverse(a,&size);
                break;
            case 2: Insertion(a,&size);
                break;
           case 3: Deletion(a,&size);
                break;
            case 4: Linear_search(a,&size);
                break;
            case 5: Selection_sort(a,&size);
                break;
            default: printf("WRONG CHOICE\n");
        }
        printf ("Do you want to perform any operation again ?\nPress 1 to continue\nPress 0 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: goto z;
                break;
            case 0: printf ("EXIT\n");
                break;
            default: printf ("WRONG CHOICE\n");
        }
        return 0;
    }
}
int Transverse (int a[],int *size)
{
    int i;
    printf ("Transverse of array is :\n");
    for(i=0;i<*size;i++)
        printf("%d\t",a[i]);
    printf("\n");
    return 0;
}

int beg (int a[],int **size);
int spec(int a[],int **size);
int end (int a[],int **size);

int Insertion (int a[],int *size)
{
    int b,c;
    z:
    printf ("Where do you want to insert the element\nPress 1 for begining\nPress 2 for specific\nPress 3 for end\n");
    scanf ("%d",&b);
    switch (b)
    {
        case 1 : beg(a,&size);
            break;
        case 2 : spec(a,&size);
            break;
        case 3 : end(a,&size);
            break;
        default : printf ("WRONG CHOICE\n");
    }
    printf ("Do you want to continue ?\nPress 1 to continue\nPress 0 to exit\n");
    scanf ("%d",&c);
    switch (c)
    {
        case 1 : goto z;
            break;
        case 0 : printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
    }
    return 0;
}
int beg (int a[],int **size)
{
    int num,i;
    printf ("Enter the element you want to insert : \n");
    scanf ("%d",&num);
        printf ("The size of array is now : %d\n",(**size));
    for (i=**size-1;i>=0;i--)
        a[i+1]=a[i];
    a[0]=num;
    (**size)++;
    //printf ("The size of array is now : %d\n",size);
    //printf ("The address of size of array is now : %d\n",&size);
    //printf ("The address of size of array is now : %d\n",*size);
    printf ("The size of array is now : %d\n",(**size));
    printf ("The array is :\n");
    for (i=0;i<(**size);i++)
        printf ("%d\t",a[i]);
    printf("\n");
    return 0;
}
int spec(int a[],int **size)
{
    int num,i,pos;
    printf ("Enter the element you want to insert : \n");
    scanf ("%d",&num);
    printf ("Enter the position at which you eant to insert :\n");
    scanf ("%d",&pos);
    if (pos<=0||pos>**size)
        printf ("Invalid choice\n");
    else
    {
        for(i=**size-1;i>=pos-1;i--)
        a[i+1]=a[i];
    a[pos-1]=num;
    (**size)++;
    printf ("The size of array is now : %d\n",**size);
    printf ("The array is :\n");
      for (i=0;i<**size;i++)
          printf ("%d\t",a[i]);
        printf("\n");
    }
    return 0;
}

int end (int a[],int **size)
{
    int num,i,b;
    printf ("Enter the element you want to insert : \n");
    scanf ("%d",&num);
    b=**size;
    a[b]=num;
    (**size)++;
    printf ("The size of array is now : %d\n",**size);
        for (i=0;i<**size;i++)
            printf ("%d\t",a[i]);
    printf ("\n");
      return 0;
}
int beg_d (int a[],int **size);
int spec_d (int a[],int **size);
int end_d (int a[],int **size);

int Deletion (int a[],int *size)
{
    int b,c;
    z:
        printf ("From where do you want to delete the element\nPress 1 for begining\nPress 2 for specific\nPress 3 for end\n");
        scanf ("%d",&b);
        switch (b)
        {
            case 1 : beg_d(a,&size);
                break;
            case 2 : spec_d(a,&size);
                break;
            case 3 : end_d(a,&size);
                break;
            default : printf ("WRONG CHOICE\n");
        }
            if (size==0)
                printf ("EXIT\n");
            else
            {
                printf ("Do you want to continue ?\nPress 1 to continue\nPress 0 to exit\n");
                scanf ("%d",&c);
                switch (c)
                {
                    case 1 : goto z;
                        break;
                    case 0 : printf ("EXIT\n");
                        break;
                    default: printf ("WRONG CHOICE\n");
                }
            }
    return 0;
}
int beg_d (int a[],int **size)
{
    int i;
    for(i=0;i<**size-1;i++)
        a[i]=a[i+1];
    (**size)--;
    if (**size==0)
        printf ("The array is empty\n");
    else
    {
        printf ("The array is :\n");
       for (i=0;i<**size;i++)
           printf ("%d\t",a[i]);
        printf("\n");
    }
    return 0;
}
int spec_d (int a[],int **size)
{
    int pos,i;
    printf ("From which position you want to delet the element ? \n");
    scanf ("%d",&pos);
    if (pos<0||pos>**size)
        printf ("Invalid choice\n");
    else
    {
        for(i=pos-1;i<**size-1;i++)
        a[i]=a[i+1];
    (**size)--;
        if (**size==0)
            printf ("The array is empty\n");
        else
        {
            printf ("The array is :\n");
            for (i=0;i<**size;i++)
            printf ("%d\t",a[i]);
            printf("\n");
        }
        
    }
    return 0;
}
int end_d (int a[],int **size)
{
    int i;
    (**size)--;
    if (**size==0)
        printf ("The array is empty\n");
    else
    {
        printf ("The array is :\n");
        for (i=0;i<**size;i++)
        printf ("%d\t",a[i]);
        printf("\n");
    }
    return 0;
}
int Linear_search (int a[],int *size)
{
    int num,i,b,count=0;
z:
    printf ("Enter the element you want to linear search :\n");
    scanf ("%d",&num);
    for(i=0;i<*size;i++)
    {
        if(a[i]==num)
        {
            count++;
        }
    }
    if(count==1)
    {
        printf("ELEMENT FOUND\n");
        count=0;
    }
    else
        printf("ELEMENT NOT FOUND\n");
    printf ("Do you want to linear search any another element?\nPress 1 to continue\nPress 0 to exit\n");
    scanf("%d",&b);
    switch(b)
    {
        case 1: goto z;
            break;
        case 0: printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
    }
    return 0;
}
int Selection_sort(int a[],int *size)
{
    {
        int i,j,min=0,temp=0;
        for(i=0;i<*size-1;i++)
        {
            min=i;
            for(j=i+1;j<*size;j++)
            {
                if(a[j]<a[min])
                    min=j;
            }
            if(min!=i)
            {
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }
        }
        printf ("The sorted array is :\n");
        for(i=0;i<*size;i++)
        {
            printf ("%d\t",a[i]);
        }
        printf ("\n");
        return 0;
    }
}
