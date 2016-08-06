#include <stdio.h>
int main(int argc,char *argv[])
{
FILE *fs,*ft;
int arr[10];
int i,j,k=0,num;
 if(argc!=3)
 {
  printf("invalid arg");
 }
 fs=fopen(argv[1],"r");
 if(fs==NULL)
 {
 printf("\nfile not found");
 }
while((fscanf(fs,"%d",&arr[k]))==1)
{
k++;
}
num=k-1;
ft=fopen(argv[2],"w");
for(i=0;i<num;i++)
{
for(j=i+1;j<num;j++)
{
if(arr[i]+arr[j]==arr[num])
{
fprintf(ft,"%d,%d",arr[i],arr[j]);
fprintf(ft,"\n");
}
}
}
 fclose(fs);
fclose(ft);
 return 0;
}