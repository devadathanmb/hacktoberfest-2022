#include<stdio.h>
int main()
{
    int m,n;
    float s=0;
    printf("Enter the number of rows and columns:\n");
    scanf("%d%d",&m,&n);
    float a[m][n];
    
        printf("Enter Elements of  Matrix:\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%f",&a[i][j]);

    for(int i=0;i<m;i++)
    {    for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i==m-1||j==n-1)
                {    
                    printf("%.1f ",a[i][j]);
                    s+=a[i][j];
                }    
                else
                    printf(" *  ");
            }  
            printf("\n");              
    } 
    printf("Sum of Boundary Elements:%.2f",s);  
    return 0;

}