#include<fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX 256
using namespace std;
ofstream fout; 

struct charFrequency {
    char c;
    int f;
};
 
void swap(charFrequency *x, charFrequency *y) {
    charFrequency z = *x;
    *x = *y;
    *y = z;
}
 
void maxHeapify(charFrequency frequency[], int i, int heap_size)
{
    int l = i*2 + 1;
    int r = i*2 + 2;
    int largest = i;
    if (l < heap_size && frequency[l].f > frequency[i].f)
        largest = l;
    if (r < heap_size && frequency[r].f > frequency[largest].f)
        largest = r;
    if (largest != i)
    {
        swap(&frequency[i], &frequency[largest]);
        maxHeapify(frequency, largest, heap_size);
    }
}
 
void buildHeap(charFrequency frequency[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        maxHeapify(frequency, i, n);
        i--;
    }
}
 
charFrequency extractMax(charFrequency frequency[], int heap_size)
{
    charFrequency root = frequency[0];
    if (heap_size > 1)
    {
        frequency[0] = frequency[heap_size-1];
        maxHeapify(frequency, 0, heap_size-1);
    }
    return root;
}
 
int rearrange(char str[], int d)
{
    int n = strlen(str);
 
    charFrequency frequency[MAX] = {{0, 0}};
 
    int m = 0; 
 
    for (int i = 0; i < n; i++)
    {        
        int x =(int) str[i];
 	
        if (frequency[x].c == 0)
            frequency[x].c = x, m++;
 
        (frequency[x].f)++;
        str[i] = '\0';   
    }
 
    buildHeap(frequency, MAX);
 
    for (int i = 0; i < m; i++)
    {
        charFrequency x = extractMax(frequency, MAX-i);
 
        int p = i;
        while (str[p] != '\0')
            p++;
 
        for (int k = 0; k < x.f; k++)
        {
            if (p + d*k >= n)
            {
               return 5; 
            }
            str[p + d*k] = x.c;
        }
    }
return 0;
}
 
int main(int argc,char *argv[])
{
	int countt=0,i;
ifstream read(argv[1]);
ifstream read3(argv[1]);
fout.open(argv[2]);
string line;
         while (getline(read, line))
              countt++;
read.close();
int z;
string str;
for(i=0;i<countt;i++)
{
while (getline(read3, str, '\n'))
{
		z=strlen(str.c_str());
		char ar[z];
		strcpy(ar, str.c_str());


		int i,d=ar[0]-48,f=0,b=z-1;

	char input[b];
	for(i=0;i<z;i++)
	{
		if(isalpha(ar[i]))
		{
			input[f]=ar[i];
			f++;
		}	
	}
    input[f]='\0';
    int g=rearrange(input, d);
	if(g==5)
	fout<<"cannot be rearranged";
	else
    		fout<<input;
	fout<<"\n";
}
}
return 0;
}
