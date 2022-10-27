#include<stdio.h>
#include<stdlib.h>
struct employee
{
    char emp_name[100];
    int emp_id;
    float emp_sal;
}e[50];
int main(){
    int i,n;
    system("cls");
    printf("Enter number of employees");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter name of employee\n");
        scanf("%s",e[i].emp_name);
        printf("Enter employee id\n");
        scanf("%d",&e[i].emp_id);
        printf("Enter salary\n");
        scanf("%f",&e[i].emp_sal);
        getchar();
    }
    printf("Employee details\n");
    for(i=0;i<n;i++){
        printf("%s\t%d\t%f\n",e[i].emp_name,e[i].emp_id,e[i].emp_sal);
    }
}
