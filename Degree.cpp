#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int arr[100][100]= {0},number,x,y,coun[100]= {0},ma=0;

    cout<<"Enter The Nodes :";
    cin>>number;
    cout<<endl;

    cout<<"Connect The Nodes."<<endl;
    for(int i=1; i<=number*number; i++)
    {
        cout<<"From :";
        cin>>x;
        if(x==-1)
            break;
        cout<<"To :";
        cin>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }

    for(int i=1; i<=number; i++)
    {
        for(int j=1; j<=number; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=number; i++)
    {
        for(int j=1; j<=number; j++)
        {
            if(arr[i][j]==1)
                coun[i]++;
        }
    }

    for(int i=1; i<=number; i++)
    {
        if (coun[i]>ma)
            ma=coun[i];
    }

    cout<<endl<<"Degree is "<<ma<<endl;
}
