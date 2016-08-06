#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

int longestStr(char *txt);
int z=0,flag=0;
ofstream of;
int main(int argc,char *argv[])
{
ifstream read ( argv[1] );
of.open(argv[2]);
string str;
ifstream read2(argv[1]);
while (getline(read2, str, '\n')) 
        {
		z=strlen(str.c_str());
   		char txt[z];
		strcpy(txt, str.c_str());
		int b=longestStr(txt);
		of<<" "<<b<<"\n";

        }
return 0;
}
void printString(char* str, int low, int high)
{
    for( int i = low; i <= high; ++i )
        of<< str[i];
}
int longestStr(char *str)
{
    int maxLen = 1;  
 
    int start = 0;
    int len = strlen(str);
 
    int low, high;
 
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLen)
            {
                start = low;
                maxLen = high - low + 1;
            }
            --low;
            ++high;
        }
 
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLen)
            {
                start = low;
                maxLen = high - low + 1;
            }
            --low;
            ++high;
        }
    }

    printString(str, start, start + maxLen - 1);
 
    return maxLen;
}
