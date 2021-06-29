#include<stdio.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
void main()
{
	int a[20],n,i;
	printf("how many values\n");
	scanf("%d",&n);
	printf("give values:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf("The sorted values are:\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	
}
void quicksort(int *a, int s,int e)
{
	int p;
	if (s<e)
	{
	p=partition(a,s,e);
	quicksort(a,s,p-1);
	quicksort(a,p+1,e);
	}
}
int partition(int *a,int s,int e)
{
	int pivot,r,l,t;
	pivot=s;
	r=s+1;
	l=e;
	while (r<=l)
	{
		while (a[r]<a[pivot] && r<=e)
		r=r+1;
		while (a[l]>a[pivot])
		l=l-1;
		if (r<=l)
		{
			t=a[r];
			a[r]=a[l];
			a[l]=t;
			r=r+1;
			l=l-1;
		}
		
	}
			t=a[pivot];
			a[pivot]=a[l];
			a[l]=t;
	return l;
	
}
