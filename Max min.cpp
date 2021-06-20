#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int arr[100],n,l,arr1[100];

void inser1(int num, int location)
{
    int p;
    while (location > 0)
    {
        p =(location - 1)/2;
        if (num >= arr[p])
        {
            arr[location] = num;
            return;
        }
        arr[location] = arr[p];
        location = p;
    }
    arr[0] = num;
}

void display1()
{
    int i;
    if (n == 0)
    {
        cout<<"Binary Heap is empty \n";
        return;
    }
    cout<<arr[0]<<" ";
    cout<<endl<<endl;
}

void inser2(int num, int location)
{
    int p;
    while (location > 0)
    {
        p =(location - 1)/2;
        if (num <= arr1[p])
        {
            arr1[location] = num;
            return;
        }
        arr1[location] = arr1[p];
        location = p;
    }
    arr1[0] = num;
}
void display2()
{
    int i;
    if (n == 0)
    {
        cout<<"Binary Heap is empty \n";
        return;
    }
    cout<<arr1[0]<<" ";
    cout<<endl<<endl;
}


int main()
{
    int num,k,m,h;
    n=0;
    l=0;
    cout<<"How many numbers you want ? \n";
    cin>>m;
    h=m;
    cout<<"Enter the element to insert : ";
    while(m--)
    {
        cin>>num;
        inser1(num, n);
        n = n + 1;
    }
    cout<<endl<<"Min: ";
    display1();
    for(int i=0; i < h ; i++)
    {
        k=arr[i];
        inser2(k, l);
        l = l + 1;
    }
    cout<<"Max: ";
    display2();



    return 0;
}

