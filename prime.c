#include<stdio.h>
int main()
{
    int n,flag=0;
    printf("Enter the number:");
    scanf("%d",&n);
    if(n==0 || n==1)
        printf("Neither Prime nor Composite Number");
    else    
    {   for(int i=2;i<=n/2;i++)
        {
            if(n%i==0)
            {   
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("Composite Number");
        else
            printf("Prime Number");    
    }        
    return 0;   
}