#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc,char *argv[])
{
	int array[20],i=0,l,count=0,j=0,k=0,value=0,flag=0,sum=-2000,tmp=0,n;
	char *ptr;
	ptr = argv[1];
	l = strlen(ptr);
	for(i=0,k=0;i<l;i++,k++)
	{
		value=0,flag=0;
		if(*(ptr+i) == '-')
		{
			flag=1;
			i++;
		}
		while(isdigit(*(ptr+i)))
		{
			value = value*10 + (*(ptr+i)-'0');
			i++;
		}

		if(flag==1)
		array[k] = -1*value;
		else
		array[k] = value;
		count++;
	}
	for(i=0;i<count;i++)
	{
		j=i;
		n = count-1;
		while((n-j)>=1)
		{	k = j;
			tmp = 0;
			while(k<=n)
			{
				tmp += array[k];
				k++;
			}
			if(tmp>sum)
			sum = tmp;
			n--;
		}
	}
	printf("%d",sum);
	return 0;
}
