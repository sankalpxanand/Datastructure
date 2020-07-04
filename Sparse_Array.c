#include<stdio.h>

int main ()
{
    int a[10][10],spa[100][3],m,n,i,j,k=0,r,zeros=0,nonz=0;
    printf ("How many rows you want ?\n");
    scanf ("%d",&m);
    printf ("How many columns you want ?\n");
    scanf ("%d",&n);
    if(m>10&&n>10)
        printf ("INVALID SIZE\n");
    else
    {
        printf ("Enter the element :\n");
        for(i=0;i<m;i++)
        {
            for (j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==0)
                    zeros++;
                else
                    nonz++;
            }
        }
        printf ("The array is :\n");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                printf("%d\t",a[i][j]);
            printf("\n");
        }
        printf ("Number of elements which are zero : %d\n",zeros);
        printf ("Number of elements which are non zero : %d\n",nonz);
        if(nonz>(m*n)/4)
        {
            printf("Sparse array is not possible\n");
        }
        else if(zeros==(m*n))
        {
            printf ("Sparse array is not possible\n");
        }
        else
        {
            r=nonz+1;
            spa[k][0]=m;
            spa[k][1]=n;
            spa[k][2]=nonz;
            
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(a[i][j]!=0)
                    {
                        k++;
                        spa[k][0]=i+1;
                        spa[k][1]=j+1;
                        spa[k][2]=a[i][j];
                    }
                }
            }
        
            printf("The sparse array is :\n");
            for(i=0;i<r;i++)
            {
                for(j=0;j<3;j++)
                    printf("%d\t",spa[i][j]);
                printf("\n");
            }
        }
    }
}
