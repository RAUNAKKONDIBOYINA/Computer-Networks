#include<iostream>
using namespace std;

int main()
{

    bool a[20],b[20],parity=0;
    int size;
    cout<<"Enter size : ";
    cin>>size;
    cout<<"Enter input stream : ";
    for(int i=0;i<size;i++)
        cin>>a[i];
    for(int i=0;i<size;i++)
        parity=parity^a[i];
    a[size]=parity;
    cout<<"Data stream sent : ";
    for(int i=0;i<=size;i++)
        cout<<a[i]<<" ";
    cout<<"\nEnter received data stream : ";
    for(int i=0;i<=size;i++)
        cin>>b[i];
    parity=0;
    for(int i=0;i<=size;i++)
        parity=parity^b[i];
    if(parity==0)
        cout<<"No error.";
    else
        cout<<"Error generated.";


}

