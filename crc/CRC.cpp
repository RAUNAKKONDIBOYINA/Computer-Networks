#include <iostream>
using namespace std;


int main()
{


    int i,j,k,l;

    //Get Frame
    int ms;
    cout<<"\n Enter Msg size: ";
    cin>>ms;

    int f[20];

    cout<<"\n Enter Msg:";
    for(i=0;i<ms;i++)
    {
        cin>>f[i];
    }

    //Get Generator
    int gs;
    cout<<"\n Enter Generator size: ";
    cin>>gs;

    int g[20];

    cout<<"\n Enter Generator:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];
    }

    cout<<"\n Sender Side:";
   /* cout<<"\n Msg: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n Generator :";
    for(i=0;i<gs;i++)
    {
        cout<<g[i];
    }*/

    //Append 0's
    int rs=gs-1;
    cout<<"\n Number of 0's to be appended: "<<rs;
    for (i=ms;i<ms+rs;i++)
    {
        f[i]=0;
    }

    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }

    cout<<"\n Msg after appending 0's :";
    for(i=0; i<ms+rs;i++)
    {
        cout<<temp[i];
    }

    //Division
    for(i=0;i<ms;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }

    //CRC
    int crc[15];
    for(i=0,j=ms;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }

    cout<<"\n CRC bits: ";
    for(i=0;i<rs;i++)
    {
        cout<<crc[i];
    }

    cout<<"\n Transmitted Msg: ";
    int tf[15];
    for(i=0;i<ms;i++)
    {
        tf[i]=f[i];
    }
    for(i=ms,j=0;i<ms+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<ms+rs;i++)
    {
        cout<<tf[i];
    }

    cout<<"\n Receiver side : ";
    cout<<"\n Received Msg: ";
    for(i=0;i<ms+rs;i++)
    {
        cout<<tf[i];
    }

    for(i=0;i<ms+rs;i++)
    {
        temp[i]=tf[i];
    }

    //Division
    for(i=0;i<ms+rs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }

    cout<<"\n Remainder: ";
    int rrem[15];
    for (i=ms,j=0;i<ms+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }

    int flag=0;
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }

    if(flag==0)
    {
        cout<<"\n  Remainder Is 0, Message Transmitted Is Correct";
    }
    else
    {
        cout<<"\n  Remainder Is Not 0, Message Transmitted Contains Error";
    }



}
