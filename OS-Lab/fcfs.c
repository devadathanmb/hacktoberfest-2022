#include<stdio.h>
#include<string.h>

int takedetails();
void printprocess(int num);
void fcfssort(int num);
int fcfscalc();

struct process{
    int n, at, bt, ct, wt, tat, status;
}p[20],temp;

struct done{
    int n, st, ct;
}d[20];

void main(){
    int nop = takedetails();
    fcfssort(nop);
    printprocess(nop);
    int dnum = fcfscalc(nop);
    printprocess(nop);
    int k;
    printf("\n");
    for(k=0;k!=dnum;k++){
        printf("%d 		 %d  		%d\n",d[k].n, d[k].st, d[k].ct);
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
        p[i].status = 0;
    }
    return num;
}

void fcfssort(int num){
int i,j;
for(i=0;i!=num;i++){
    for(j=0;j!=num-i-1;j++){
        if(p[j].at>p[j+1].at){
            temp = p[j];
            p[j] = p[j+1];
            p[j+1] = temp;
        }
    }
}
}

int fcfscalc(int nop){

int i=0;//secs
int j=0;//currprocess
int num=0;//index in d
int idle = 0;//idle

for(i=0,j=0,num=0;j<nop;)              //Calculations
  {
    if(p[j].at<=i && p[j].status==0)
    {
      if(idle==1)
      {
        d[num].ct=i;
        num++;
        idle = 0;
      }
      d[num].n=p[j].n;
      d[num].st = i;
      d[num].ct = i + p[j].bt;
      p[j].wt = d[num].st - p[j].at;
      p[j].tat = p[j].wt + p[j].bt;
      p[j].ct = d[num].ct;
      i = d[num].ct;
      p[j].status = 1;
      j++;
      num++;

    }
    else if(idle == 0)
    {
      d[num].n=4353;
      d[num].st = i;
      i++;
      idle = 1;
    }
    else
    {
      i++;
    }
  }



}


void printprocess(int num){
    int i;
    printf("\nN  |  AT  |  BT  |  CT  |  WT  | TAT  |  Status\n");
    for(i=0;i!=num;i++){
        printf("%d  |   %d  |   %d  |   %d  |   %d  |   %d  |   %d\n",p[i].n, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat, p[i].status);       
    }
}

