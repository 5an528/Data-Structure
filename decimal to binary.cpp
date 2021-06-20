#include<iostream>

using namespace std;

int conv(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {

        return (n%2+10*conv(n/2));
    }
}

int main()
{
    int number;
    cin>>number;
    cout<<conv(number);
}
