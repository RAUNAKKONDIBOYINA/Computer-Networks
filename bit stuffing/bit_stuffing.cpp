#include<iostream>
using namespace std;

int bitstuff(int input[], int sent[],int framesize)
{
    int sentsize=0;
    int count=0;
    for(int i=0;i<framesize;i++)
    {
        if(input[i]==1)
        {
            count++;
        }
        if(input[i]==0)
        {
            count=0;
        }
        if(count==5)
        {
            sent[sentsize]=input[i];
            sent[sentsize+1]=0;

            sentsize++;

            sentsize+=1;
            count=0;
        }
        else
        {
            sent[sentsize]=input[i];
            sentsize++;
        }
    }
    return sentsize;

}

void original(int sent[],int sentsize,int output[])
{
    int olen=0;
    int count=0;
    for(int i=0;i<sentsize;i++)
    {
        if(sent[i]==1)
        {
            count++;
        }
        if(sent[i]==0)
        {
            count=0;
        }
        if(count==5)
        {
            output[olen]=sent[i];
            i++;
            olen++;
        }
        else
        {
            output[olen]=sent[i];
            olen++;

        }
    }

}

int main()
{


    int framesize;
    cout<<"enter frame size"<<endl;
    cin>>framesize;

    int input[30],output[30],sent[40];

    cout<<"enter data to be sent"<<endl;
    for(int i=0;i<framesize;i++)
    {
        cin>>input[i];
    }
    cout<<endl;

    int sentsize=bitstuff(input,sent,framesize);

    cout<<"data sent is"<<endl;
    for(int i=0;i<sentsize;i++)
    {
       cout<<sent[i];
    }
    cout<<endl;

    original(sent,sentsize,output);

    cout<<"data received is"<<endl;
    for(int i=0;i<framesize;i++)
    {
       cout<<output[i];
    }

    cout<<"This is Shivansh's File"<<endl;

}
