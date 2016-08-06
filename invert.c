#include<stdio.h>

int main(int argc,char* argv[])
{
	FILE *input,*output; 
	int arr[50];
	input=fopen(argv[1],"r");
	int i=1,j,n=0;
	fscanf(input,"%d",&arr[0]);
	int ch=getc(input);
	while(ch!= EOF)
	{
		fscanf(input,"%d",&arr[i]);
		i++;
		n++;
		ch=getc(input);
	}

	output=fopen(argv[2],"w+");

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j]) 
			{
				fprintf(output,"%d,%d\n",arr[i],arr[j]);
			}
		}
	}
	return 0;
}

