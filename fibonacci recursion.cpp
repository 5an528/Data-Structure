#include<iostream>

using namespace std;

int sum=0;

int fibo(int n)
{
    int n1;
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else
    {
        return (fibo(n-1) + fibo(n-2));
    }

}

int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cout<<fibo(i)<<endl;
        sum=sum+fibo(i);
    }
    cout<<endl<<sum;

}
