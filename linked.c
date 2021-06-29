#include<stdio.h>
#define N 10
struct node{
			int info;
			int next;
			};
typedef struct node node1;

void initlist(node1*a,int *list,int *avail)
{
	int i;
	*list=-1;
	*avail=0;
	for(i=0;i<N-1;i++)
	a[i].next=i+1;
	a[N-1].next=-1;
	
}
void enterlist(node1 *a,int *list,int *avail,int x)
{
	int l,back,q;
	l=*avail;
	*avail=a[*avail].next;
	a[l].info=x;
	if (*list==-1 || x<a[*list].info)
	{
		a[l].next=*list;
		*list=l;
	}
	else
	{
		back=*list;
		q=*list;
		while(q!=-1 && a[q].info<x)
		{
			back=q;
			q=a[q].next;
		}
		a[back].next=l;
		a[l].next=q;
	}
}
void deletelist(node1 *a,int *list,int *avail,int x)
{
	int l,back;
	l=*list;
	while (l!=-1 && a[l].info<x)
	{
		back=l;
		l=a[l].next;
	}
	if (l!=-1 && a[l].info==x)
	{
		if (l==*list)
		{
			*list=a[l].next;
		}
		else
		{
			a[back].next=a[l].next;
		}
		a[l].next=*avail;
		*avail=l;
	}
	else
	printf("value not present in the list\n");
}
int searchlist(node1 *a,int list,int x)
{
	while(list!=-1 && a[list].info<x)
	list=a[list].next;
	if (a[list].info==x)
	return 1;
	else
	return 0;
}
void traverselist(node1 *a,int list)
{
	while(list!=-1)
	{
		printf("%d. %d--> ",list,a[list].info);
		list=a[list].next;
	}
	printf("\n");
}
int emptylist(int list)
{
	if (list==-1)
	return 1;
	else 
    return 0;
}
int fulllist(int avail)
{
	if (avail==-1)
	return 1;
	else
	return 0;
}
int main()
{
  	node1 a[N];
  	int list,avail;
	int choice,v,i;
	initlist(a,&list,&avail);
	do{
		printf("1. Enter a value in list\n");
		printf("2. Delete a value from list\n");
		printf("3. Search in list\n");
		printf("4. Traverse the list\n");
		printf("5. EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Give value to enter: ");
				scanf("%d",&v);
				if (fulllist(avail)==0)
				enterlist(a,&list,&avail,v);
				else
				printf("list full, cannot enter\n");
				break;
		case 2:
				printf("Give value to delete: ");
				scanf("%d",&v);
				if (emptylist(list)==0)
				deletelist(a,&list,&avail,v);
				else
				printf("list empty, cannot delete\n");
				break;
		case 3:
				printf("Give value to search: ");
				scanf("%d",&v);
				if (searchlist(a,list,v)==1)
				printf("Value found in list\n");
				else
				printf("value not found in list\n");
				break;
		case 4:
				printf("The Avail(%d)-->",avail);
				traverselist(a,avail);
				printf("\n");
				printf("The List(%d)-->",list);
				traverselist(a,list);
				printf("\n");
				break;
		case 5:
				printf("Thank you, BYE\n");
				break;
		default:
				printf("invalid choice, enter again\n");
		}
	} while(choice!=5);	
}
