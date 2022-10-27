#include<stdio.h>

struct process {
    int n, at, bt, pt, ct, wt, tat; 
}p[10], temp;

void sort(int num);
int takedetails();
void printprocess(int num);
void swap(int i, int j);
void priority(int num);

void main(){
    int num = takedetails();
    printprocess(num);
    sort(num);
    printprocess(num);
    priority(num);
    printprocess(num);
}

void priority(int num){
    int ct, i, j, flag;
    ct = p[0].at + p[0].bt;
    for(i=1;i<num;i++){
        if(p[i].at < ct){
            for(j=i+1;j<num;j++){
                if(p[j].at<ct && p[i].pt>p[j].pt){
                    swap(i,j);                    
                }
                flag=1;
            }
        }
        if(flag==1){
            ct = ct + p[i].bt;
        }
        else{
            ct = p[i].bt + p[i].at;
        }
    }
    p[0].ct = p[0].at + p[0].bt;
    ct = p[0].ct;
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    for(i = 1;i<num;i++){
        ct = ct + p[i].bt;
        p[i].ct = ct;
        p[i].tat = ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

int takedetails(){
    int i, num;
    printf("Enter the number of processes: ");
    scanf("%d",&num);
    for(i=0;i!=num;i++){
        printf("Enter the details for process: P%d\n",i);
        p[i].n = i;
        printf("Enter the AT of process P%d: ",i);       
        scanf("%d",&p[i].at);
        printf("Enter the BT of process P%d: ",i);       
        scanf("%d",&p[i].bt);
        printf("Enter the PRIORITY of process P%d: ",i);       
        scanf("%d",&p[i].pt);
    }
    return num;
}

void sort(int num){
    int i=0, j=0;
    for(i=0;i<num;i++){
        for(j=0;j<num-i-1;j++){
            if(p[j].at>p[j+1].at)
                swap(j,j+1);
            if(p[j].at == p[j+1].at && p[j].pt>p[j+1].pt)
                swap(j,j+1);
        }
    }
}

void swap(int i, int j){
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}

void printprocess(int num){
    int i;
    printf("\nN  |  AT  |  BT  |  CT  |  WT  | TAT  |  Priority\n");
    for(i=0;i!=num;i++){
        printf("%d  |   %d  |   %d  |   %d  |   %d  |   %d  |   %d\n",p[i].n, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat, p[i].pt);       
    }
}
