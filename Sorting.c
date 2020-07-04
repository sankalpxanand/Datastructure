#include<stdio.h>

int Bubble (int arr[],int size);
int Insertion (int arr[],int size);
int Selection (int arr[],int size);
int Quick(int arr[],int lb,int ub,int size);
int Merge(int arr[],int lb,int ub,int size);
int Shell (int arr[],int size);

int main ()
{
    int arr[10],size,i,a,b,c,lb = 0,ub = 0;
    printf ("Enter the size of the array :\n");
    scanf("%d",&size);
    if(size>10)
        printf("INCORRECT SIZE\n");
    else
    {
        printf ("Enter the elements of the array :\n");
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("The array is :\n");
        for(i=0;i<size;i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");
        lb=0;
        ub=size-1;
    }
    printf ("Do you want to sort the array ?\nPress 1 to continue\nPress 0 to exit\n");
    scanf ("%d",&a);
z:
    switch (a)
    {
        case 1: printf ("1.BUBBLE SORT\n2.INSERTION SORT\n3.SELECTION SORT\n4.QUICK SORT\n5.MERGE SORT\n6.SHELL SORT\n7.HEAP SORT\n");
            scanf("%d",&b);
            switch(b)
            {
                case 1: Bubble(arr,size);
                    break;
                case 2: Insertion(arr,size);
                    break;
                case 3: Selection(arr,size);
                    break;
                case 4: Quick(arr,lb,ub,size);
                    break;
                case 5 :Merge(arr,lb,ub,size);
                    break;
                case 6:Shell(arr,size);
                    break;
                //case 7:Heap(arr,size);
                    break;
                default:printf ("WRONG CHOICE\n");
            }
   
    printf ("Do you want to sort the array again?\nPtrss 1 to continue\nPress 0 to exit\n");
    scanf ("%d",&c);
    switch (c)
    {
        case 1: goto z;
            break;
        case 0: printf ("EXIT\n");
            break;
        default: printf ("WRONG CHOICE\n");
    }
             break;
            case 0: printf ("EXIT\n");
                break;
            default: printf ("WRONG CHOICE\n");
    }
            
    return 0;
}

int print (int arr[],int size)
{
    int i;
    printf ("The sorted array is :\n");
    for(i=0;i<size;i++)
    {
        printf ("%d\t",arr[i]);
    }
    printf ("\n");
    return 0;
}

int Bubble (int arr[],int size)
{
    int i,j,flag,temp;
    
    for(i=0;i<size-1;i++)
    {
        flag=0;
        for(j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    print(arr,size);
    return 0;
}
int Insertion (int arr[],int size)
{
    int i,j,temp=0;
    for(i=1;i<size;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    print(arr,size);
    return 0;
}
int Selection (int arr[],int size)
{
    int i,j,min=0,temp=0;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    print(arr,size);
    return 0;
}
int partition(int arr[],int lb,int ub);

int Quick(int arr[],int lb,int ub,int size)
{
    int loc=0;
    if(lb<ub)
        {
            loc=partition(arr,lb,ub);
            Quick(arr,lb,loc-1,size);
            Quick(arr,loc+1,ub,size);
           // printf ("%d\n",loc);
            if (lb==0&&ub==size-1)
            print (arr,size);
        }
    return 0;
}

int partition(int arr[],int lb,int ub)
{
    int pivot,start,end,temp=0,temp1=0;
    pivot=arr[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
            start++;
        //printf ("%d\n",start);
        while(arr[end]>pivot)
            end--;
         //printf ("%d\n",end);
        if(start<end)
            {
                temp=arr[start];
                arr[start]=arr[end];
                arr[end]=temp;
            }
        //printf ("%d,%d\n",start,end);
    }
    temp1=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp1;
              
    return end;
}

int Mergeing(int arr[],int lb,int mid,int ub,int size);

int Merge(int arr[],int lb,int ub,int size)
{
    int mid;
    //printf("%d,%d\n",lb,ub);
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        Merge(arr,lb,mid,size);
        Merge(arr,mid+1,ub,size);
        Mergeing(arr,lb,mid,ub,size);
        if(lb==0&&ub==size-1)
            print(arr,size);
    }
    return 0;
}
int Mergeing(int arr[],int lb,int mid,int ub,int size)
{
    int i,j,k,b[size];
    i=lb;
    j=mid+1;
    k=lb;
    //printf("%d,%d,%d\n",lb,mid,ub);
    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if (j>ub)
    {
        while(i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    else
    {
        while(j<=ub)
            {
                b[k]=arr[j];
                j++;
                k++;
            }
    }
    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
    return 0;
}
int Shell (int arr[],int size)
{
    int i,j,gap,temp;
    temp=0;
    
    for(gap=size/2;gap>=1;gap=gap/2)
    {
        for(j=gap;j<size;j++)
        {
            for(i=j-gap;i>=0;i=i-gap)
            {
                if(arr[i+gap]>arr[i])
                {
                    break;
                }
                else
                {
                    temp=arr[i+gap];
                    arr[i+gap]=arr[i];
                    arr[i]=temp;
                }
            }
        }
    }
    print(arr,size);
    return 0;
}
