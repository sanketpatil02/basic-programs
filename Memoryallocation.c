#include<stdio.h>
#include<stdlib.h>

typedef struct MemoryNode
{
    int BlockId;
    int DataSize;
    int Data;
    struct MemoryNode * addr;
}node;

node * start;
int count=1;

node * CreateList(node * start)
{
    start=NULL;
}

node * CreateNode(int BlockId,int DataSize,int Data)
{
    node * new;
    new=(node*)malloc(sizeof(node));
    
    if(new==NULL)
    {
        printf("\nNode is not avilable");
    }
    else
    {
        new->Data=Data;
        new->DataSize=DataSize;
        new->BlockId=count;
        new->addr=NULL;
    }
return new;
}

node * InsertEnd(node * start,int BlockId,int DataSize,int Data)
{
    node * new=CreateNode(BlockId,DataSize,Data);
    if(start==NULL)
    {
        count++;
        start=new;
    }
    else
    {
        node * temp=start;
        while(temp->addr!=NULL)
        {
            temp=temp->addr;
        }
        count++;    
        temp->addr=new;
    }
return start;
}

node * InsertPos(node * start,int BlockId,int DataSize,int Data)
{
    node * new=CreateNode(BlockId,DataSize,Data);
    if(start==NULL || BlockId>count)
    {
        printf("\nPosition not found");
        return start;
    }
    else if(BlockId==1)
    {
        start->Data=Data;
    }
    else
    {
        node * temp=start;
        int i;
        for(i=1;i<BlockId;i++)
        {
            temp=temp->addr;
        }
        //new->addr=temp->addr;
        temp->Data=Data;
        count++;
    }
return start;

}

node * DelPos(node * start,int BlockId)
{
    node * temp=start,*ptr;
    if(start==NULL || BlockId>count)
    {
        printf("\nPosition not found");
        return start;        
    }
    else if(BlockId==1)
    {
        temp->Data=NULL;
        //start=start->addr;
        //free(temp);
        //count--;
    }
    else
    {
        int i;
        for(i=1;i<BlockId;i++)
        {
            ptr=temp;
            temp=temp->addr;
        }    
        temp->Data=NULL;
        //ptr->addr=temp->addr;
        //free(temp);
        //count--;
    }
return start;
}

void traverse(node * start)
{
    node * temp=start;
    printf("\n");
    printf("Address\t\t   Block Id\t   Data Size\t\tData");
    printf("\n");
    for(temp=start;temp->addr!=NULL;temp=temp->addr)
    {
        printf("%p\t\t%d\t\t%d\t\t%d",temp,temp->BlockId,temp->DataSize,temp->Data);
        printf("\n");
    }
    printf("%p\t\t%d\t\t%d\t\t%d",temp,temp->BlockId,temp->DataSize,temp->Data);
    printf("\n");
}

int main()
{
    int numbers=0;
    CreateList(start);
    //printf("\nEnter total number of blocks:");
    //scanf("%d",&numbers);
    start=InsertEnd(start,count,16,0);
    start=InsertEnd(start,count,16,0);
    start=InsertEnd(start,count,16,0);
    start=InsertEnd(start,count,16,0);
    printf("\nAvailable memory blocks are:");
    traverse(start);    
    printf("\nHere data=0 means there is no data\n");
/*    start=DelPos(start,2);
    traverse(start);
    start=InsertPos(start,2,16,4);
    traverse(start);
*/
    int i=0;
    int BlockId=0, Data=0;
    do
    {
    int choice=0;
    printf("\nEnter the any operation from below:\n1.Insert Data\n2.Delete Data\n3.Display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\nEnter the BlockId: ");
                scanf("%d",&BlockId);
                printf("\nEnter the Data: ");
                scanf("%d",&Data);
                start=InsertPos(start,BlockId,16,Data);
        break;
        
        case 2: printf("\nEnter the BlockId: ");
                scanf("%d",&BlockId);
                start=DelPos(start,BlockId);
        break;

        case 3: traverse(start);
        break;

        default :printf("\nYou have enter wrong choice");
    }
    printf("\nIf you want to continue enter 1 : ");
    scanf("%d",&i);
    }
    while(i==1);

    return 0;
}


