#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int k;
    int ar[2*n-1][2*n-1];
    int m=(2*n+1)/2;
    for(int i=0;i<n;i++)
    {
        k=n;
        for(int j=0;j<n;j++)
        {
            if(i>j)
                ar[i][j]=k--;
            else
                ar[i][j]=k;
        }
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        {
            ar[m+i-1][m+j-1]=ar[m-i-1][m-j-1];
            ar[i][m+j-1]=ar[i][m-j-1];
            ar[m+i-1][j]=ar[m-i-1][j];
        }

        for(int i=0;i<2*n-1;i++)
        {   
            for(int j=0;j<2*n-1;j++)
                printf("%d ",ar[i][j]);
            printf("\n");
        }
    return 0;
}