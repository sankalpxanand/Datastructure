#include<stdio.h>

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
               printf ("Which opertaion you want to perform ?:\n1.Linear search\n2.Selection sort\n");
               scanf("%d",&b);
               switch(b)
               {
                   case 1: Linear_search(a,&size);
                       break;
                   case 2: Selection_sort(a,&size);
                       break;
                   default: printf ("WRONG CHOICE\n");
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

