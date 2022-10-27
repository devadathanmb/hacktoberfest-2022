#include<stdio.h>

void main(){
    int p=0,r=0,i=0,j=0;
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    printf("Enter the number of resources: ");
    scanf("%d",&r);
    int allocation[p][r], max[p][r], need[p][r], available[r];
    int answer[p];
    
    //TAKING INPUTS
    printf("\n");    
    for(i=0;i!=p;i++){
        printf("Enter the current ALLOCATION for P%d: ",i);
        for(j=0;j!=r;j++)
            scanf("%d",&allocation[i][j]);
    }
    printf("\n");
    for(i=0;i!=p;i++){
        printf("Enter the MAX allocation for P%d: ",i);
        for(j=0;j!=r;j++)
            scanf("%d",&max[i][j]);
    }
    printf("\n");
    printf("Enter the AVAILABLE resources: ");
    for(j=0;j!=r;j++)
        scanf("%d",&available[j]);
    printf("\n");

    //LOGIC PART
    //need matrix
    for(i=0;i!=p;i++)
        for(j=0;j!=r;j++)
            need[i][j] = max[i][j] - allocation[i][j];

    for(i=0;i!=p;i++)
        answer[i] = 0;

    int k=0, l=0, count=0, flag;
    
    while(count != p){
        // printf("inside while\n");
        for(j=0; j!=p; j++){
            // printf("inside 1st loop\n");
            if(answer[j]==0){
                flag=1;
                for(i=0;i!=r;i++){
                    // printf("checking need nd availability\n");
                    if(need[j][i] <= available[i])
                        flag=1;
                    else{
                        // printf("flag is 0\n");
                        flag=0;
                        break;
                    }                    
                }
                if(flag==0)
                    continue;
                else if(flag==1){
                    // printf("flag is 1\n");
                    answer[j]=1;
                    for(l=0;l!=r;l++)
                        available[l]+=allocation[k][l];
                    k++;
                    printf("P%d ",j);
                }
            }                
        }
        count++;
    }

}