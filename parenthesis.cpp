#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
ofstream fout;
void nested(char *str,int res);

int res=0;
int main(int argc,char *argv[])
{
ifstream read1(argv[1]);
fout.open(argv[2]);
string str;
while (getline(read1, str, '\n'))
{
	res=strlen(str.c_str());
	char mytxt[res];
	strcpy(mytxt, str.c_str());
	nested(mytxt,res);
	fout<<"\n";
}
return 0;
}

void nested(char *str,int res)
{
	int i=0,len=0,count=0,j=0;
	while(i!=res)
	{
		if(str[i]=='(' || str[i]==')')
		len++;
	i++;
	}
	int arr[len];
	i=0;
	while(i!=res)
	{
		if(str[i]=='(')
		{	
		count++;
		arr[j]=count;
		j++;
		}
		else if(str[i]==')')
		{	
		count--;
		arr[j]=count;
		j++;
		}
		i++;
	}
	int maximum=arr[0];
	for(i=0;i<len;i++)
	{
		if(maximum<arr[i])
			maximum=arr[i];
	}
	if(count==0)
	fout<<maximum;
	else
	fout<<"-1";
}
