#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *llink;
    struct node *rlink;
}node;
int main()
{
    int i,num,key,state=-1;
    node *header,*ptr,*new,*temp1,*temp2;
    header=(node*)malloc(sizeof(node));
    header->data=0;
    header->rlink=NULL;  
    while(state!=0)
    {
        printf("Select Operation:\nInsertion\n1)Front\t2)Any Position\t3)End\nDeletion\n4)Front\t5)Any Postion\t6)End\n7)Display Elements\nPress 0 to Exit:");
        scanf("%d",&state);
        switch(state)
        {
            case 0:
                state=0;
                break;
            case 1:
                printf("Enter Element to Insert:");
                scanf("%d",&num);
                ptr=header->rlink;
                new=(node*)malloc(sizeof(node));
                if(new!=NULL)
                {
                    new->data=num;
                    new->llink=header;
                    header->rlink=new;
                    new->rlink=ptr;
                    if(new->rlink!=NULL)
                        ptr->llink=new;    
                }
                else
                    printf("Memory Full");
                break;
            case 2:
                printf("Enter Element to Insert:");
                scanf("%d",&num);               
                printf("Enter the value of key:");
                scanf("%d",&key);
                ptr=header;
                while(ptr->data!=key&&ptr!=NULL)
                    ptr=ptr->rlink;
                new=(node*)malloc(sizeof(node));
                if(new!=NULL)
                {
                    new->data=num;
                    if(ptr->rlink==NULL)
                    {
                        new->rlink=NULL;
                        new->llink=ptr;
                        ptr->rlink=new;
                    }
                    else
                    {
                        temp1=ptr->rlink;
                        new->rlink=temp1;
                        temp1->llink=new;
                        new->llink=ptr;
                        ptr->rlink=new;
                    }   
                }
                else
                    printf("Memory Full");
                break;
            case 3:
                printf("Enter Element to Insert:");
                scanf("%d",&num);
                ptr=header;
                while(ptr->rlink!=NULL)
                    ptr=ptr->rlink;
                new=(node*)malloc(sizeof(node));
                if(new!=NULL)
                {
                    new->data=num;
                    new->rlink=NULL;
                    new->llink=ptr;
                    ptr->rlink=new;
                }
                else
                    printf("Memory Full");
                break;
            case 4:
                ptr=header->rlink;
                if(ptr==NULL)
                    printf("List Empty");
                else
                {
                    temp1=ptr->rlink;
                    header->rlink=temp1;
                    if(temp1!=NULL)
                        temp1->llink=header;
                    free(ptr);
                }
                break;
            case 5:
                ptr=header->rlink;
                printf("Enter the value of key:");
                scanf("%d",&key);
                if(ptr==NULL)
                    printf("List Empty");
                else
                {
                    while(ptr->data!=key&&ptr!=NULL)
                        ptr=ptr->rlink;
                    if(ptr->data==key)
                    {
                        temp1=ptr->llink;
                        temp2=ptr->rlink;
                        temp1->rlink=temp2;
                        if(temp2!=NULL)
                            temp2->llink=temp1;
                        free(ptr);    
                    }
                    else
                        printf("Key not found");

                }
                break;
            case 6:
                ptr=header;
                while(ptr->rlink!=NULL)
                        ptr=ptr->rlink;
                if(ptr==header)
                    printf("List Empty");
                else
                {   
                    temp1=ptr->llink;
                    temp1->rlink=NULL;
                    free(ptr);
                }             
                break;
            case 7:
                ptr=header;
                while(ptr->rlink!=NULL)
                {
                    ptr=ptr->rlink;
                    printf("%d ",ptr->data);
                }
                printf("\n");
                break;
            default:
                printf("Invalid Input");

        }
    }
    return 0;
}    
    
    
