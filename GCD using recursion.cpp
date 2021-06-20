#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    if (y != 0)
       return gcd(y, x%y);
    else
       return x;
}

int main()
{
   int a, b;

    cin>>a>>b;
   cout<<gcd(a,b);
   return 0;
}


