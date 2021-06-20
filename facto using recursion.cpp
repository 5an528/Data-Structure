#include<iostream>

using namespace std;

int fact(int n)
{
    int temp;
    if (n<=1)
        temp=1;
    else
        temp=n*fact(n-1);
    return temp;
}

int main()
{
    int n1;
    cin>>n1;
    cout<<fact(n1);
}
