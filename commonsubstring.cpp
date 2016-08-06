#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char* longestStr(char *,char *,int &);
int main(int argc,char *argv[])
{
	
	int result;
	char n='\n';
	char c,ch;
	int len=0,len1=0;
	ifstream infile(argv[1]);
	infile.get(c);	
	while(c!=n)
	{
		
		len++;
		infile.get(c);
		
	}
	infile.get(c);
	while(c!=n)
	{		
			infile.get(c);
			len1++;
	}
	char arr1[len],arr2[len1];
	int i=0,j=0;
	ifstream in(argv[1]);
	in.get(ch);
	while(ch!=n)
	{
		
			arr1[i]=ch;
			in.get(ch);
			i++;
	}
	in.get(ch);
	while(ch!=n)
	{
			
			arr2[j]=ch;
			in.get(ch);
			j++;
	}

	ofstream fout(argv[2]);
	
	char *p=longestStr(arr1,arr2,result);
	fout<<p<<" "<<result;
	return 0;
}

char* longestStr(char *str1,char *str2,int &result)
{

int m = strlen(str1);

int n = strlen(str2);

int lcs[m+1][n+1];

int i,j;

result = 0;

int index_i = 0;

for(i=0;i<=m;i++)

{

for(j=0;j<=n;j++)

{

if(i==0 || j==0)

lcs[i][j] = 0;

else if(str1[i-1] == str2[j-1])

{

lcs[i][j] = lcs[i-1][j-1] + 1;

if(lcs[i][j] > result)

{

result = lcs[i][j];

index_i = i;


}

}

else

lcs[i][j] = 0;

}

}

 int k= result;
char *output=new char[result]; 

output[result] = '\0';



while(k>0)

{

output[k-1] = str1[index_i-1];

index_i--;

k--;

}
return output;
}

