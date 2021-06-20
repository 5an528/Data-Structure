#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int arr[100][100]= {0},number,x,y,dis;

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

    cout<<"Disjoint Vertex: ";
    cin>>dis;

    for(int i=1; i<=number; i++)
    {
        arr[i][dis]=0;
        arr[dis][i]=0;
    }

    for(int i=1; i<=number; i++)
    {
        for(int j=1; j<=number; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
