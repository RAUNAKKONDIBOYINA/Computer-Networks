#include<iostream>

using namespace std;

int main() {
    int data[14];


    cout<<"Enter 8 bits of data one by one\n";
    cin>>data[3];
    cin>>data[5];
    cin>>data[6];
    cin>>data[7];
    cin>>data[9];
    cin>>data[10];
    cin>>data[11];
    cin>>data[12];

    //Calculation of even parity
    int p1=data[3]^data[5]^data[7]^data[9]^data[11];
    int p2=data[3]^data[6]^data[7]^data[10]^data[11];
    int p3=data[5]^data[6]^data[7]^data[12];
    int p4=data[9]^data[10]^data[11]^data[12];
    data[1]=p1;
    data[2]=p2;
    data[4]=p3;
    data[8]=p4;

    data[13]=data[1]^data[2]^data[3]^data[4]^data[5]^data[6]^data[7]^data[8]^data[9]^data[10]^data[11]^data[12];

    cout<<"sent data"<<endl;
    for(int i=1;i<14;i++)
    {
        cout<<data[i];
    }

    cout<<endl;
    cout<<"enter error"<<endl;
    for(int i=1;i<14;i++)
    {
        cin>>data[i];
    }


    int c1=data[1]^data[3]^data[5]^data[7]^data[9]^data[11];
    int c2=data[2]^data[3]^data[6]^data[7]^data[10]^data[11];
    int c4=data[4]^data[5]^data[6]^data[7]^data[12];
    int c8=data[8]^data[9]^data[10]^data[11]^data[12];

    int p=data[13];
    int c=c8*8+c4*4+c2*2+c1*1;
    if(c==0 && p==0)
    {
        cout<<"no error"<<endl;
    }
    else if(c!=0 && p==1)
    {

        cout<<"single error and can be corrected"<<endl;
        cout<<"error at"<<c<<endl;
    }
    else if(c!=0 && p==0)
    {
        cout<<"double error"<<endl;
    }
    else
    {
        cout<<"error at data 13"<<endl;
    }
  

    return 0;
}
