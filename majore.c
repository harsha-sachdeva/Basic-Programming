#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
void majorElement(int arr[],int n)
{
	int count=1,i,j,tmp,res=0,flag=0;
	int brk=0;
if((n%2)==0)
{
n=n;
}
else
{
n=n+1;
}
for(i=0;i<n;i++)
	{
		tmp=arr[i];
		for(j=i+1;(brk==0)&&(j<n);j++)
		{
			if(tmp==arr[j])
			count++;
			if(count>=n/2)
			{
				brk=1;
				break;
			}
		}
		if(count>=(n/2))
		{
		res=tmp;
		flag=1;
		}
		count=1;
	}
	if(flag==1)
	printf("%d",res);
	else
	printf("NONE");
}
int main(int argc,char *argv[])
{
int array[20],i=0,length,count=0,j=0,k=0,val=0;
char *ptr;
ptr = argv[1];
length = strlen(ptr);
for(i=0,k=0;i<length;i++,k++)
{
	j=0,val=0;
	while(isdigit(*(ptr+i)))
	{
		val = val*10 + (*(ptr+i)-'0');
		i++;
	}
	array[k] = val;
	count++;
}
majorElement(array,count);
return 0;
}
