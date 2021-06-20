#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int arr[100][100]= {0}, number, x, y, source, destination;

int path(int s, int d)
{
    for(int i=s;i<=number;i++)
    {
        for(int j=1;j<=number;j++)
        {
            if(arr[i][j]==1)
                return path(j,number);
            else
                cout<<"No path found.";
        }
    }
}

int main()
{
    int arr[100][100]= {0},number,x,y,source,destination;

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

    cout<<"Source and Destination: ";
    cin>>source>>destination;

    path(source,destination);
}

