#include<string.h>
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{

int i=0,j=0,n,pos;
char a[20],b[50],ch;
cout<<"Enter string : ";
cin>>a;
n=strlen(a);
b[0]='d';
b[1]='l';
b[2]='e';
b[3]='s';
b[4]='t';
b[5]='x';
j=6;
while(i<n)
{
if(a[i]=='d' && a[i+1]=='l' && a[i+2]=='e')
{
b[j]='d';
b[j+1]='l';
b[j+2]='e';
j=j+3;
}

b[j]=a[i];
i++;
j++;
}
b[j]='d';
b[j+1]='l';
b[j+2]='e';
b[j+3]='e';
b[j+4]='t';
b[j+5]='x';
b[j+6]='\0';
cout<<"Frame after stuffing : "<<b;
cout<<endl;
cout<<"this is shivansh's File"<<endl;
getch();
}
