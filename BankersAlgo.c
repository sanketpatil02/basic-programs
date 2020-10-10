#include<stdio.h>
#include<stdlib.h>
int validity(int *a,int *b,int num){
	int i,flag=1;
	for(i=0;i<num;i++){
		if(a[i]>b[i]){
			flag=0;
			break;
		}
	}
	return flag;
}

int condition(int *flag,int n){
	int i,temp=1;
	for(i=0;i<n;i++){
		if(flag[i]==0){
		temp=0;
		break;	}
	}
	return temp;
}

int main(){

	int num,proc,i,j,count=0;

	printf("\n----------------------------");
	printf("\nenter number of resources:");
	scanf("%d",&num);

	printf("\n----------------------------");
	printf("\nenter number of processes:");
	scanf("%d",&proc);

	int allocated[proc][num],max[proc][num],need[proc][num],resources[num],flag[proc],available[num];

	for(i=0;i<num;i++){
		printf("\n----------------------------");
		printf("\nenter number of resources in resource no_%d:",(i+1));
		scanf("%d",&resources[i]);
		available[i]=resources[i];

		}

	for(i=0;i<proc;i++){
		for(j=0;j<num;j++){
			printf("\n----------------------------");
			printf("\nenter number of allocated and maximum required resources for %d and %d:",i,j);
			scanf("%d %d",&allocated[i][j],&max[i][j]);
			available[j]-=allocated[i][j];
			need[i][j]=max[i][j]-allocated[i][j];
			}
			flag[i]=0;
		}
		printf("execution sequence:");
	while(243){
		for(i=0;i<proc;i++){
			count++;
			if(validity(need[i],available,num)&&(flag[i]!=1)){
				flag[i]=1;
				printf("-->p%d",i);
				for(j=0;j<num;j++){
					available[j]+=allocated[i][j];
				}
			}
		}
		if(count==proc+1){
			printf("\ndeadlock occured");
			break;
		}
		if(condition(flag,proc)){
			break;
		}
	}
}
