#include<string.h>

#include<fstream>

#include<iostream>

#include<stdlib.h>

#include<math.h>

using namespace std;


int main(int argc,char* argv[])

{

float i,precision;

precision=0.001;

double num=atoi(argv[1]);

for(i=0;i<num;i=i+precision)

{
  
if((i*i)>num)
  
{
   
i=i-precision;         
   
break;      
  
}              

}

i=roundf(i*100)/100;

cout<<i;

return 0;

}

