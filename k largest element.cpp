#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int arr[100],n;

void inser(int num, int location)
{
    int p;
    while (location > 0)
    {
        p =(location - 1)/2;
        if (num <= arr[p])
        {
            arr[location] = num;
            return;
        }
        arr[location] = arr[p];
        location = p;
    }
    arr[0] = num;
}

void display()
{
    int i;
    if (n == 0)
    {
        cout<<"Binary Heap is empty \n";
        return;
    }
    for (i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;;
}

void reheap_down(int location)
{

    int left, right, temp, p;
    left = 2 * location + 1;
    right = 2 * location + 2;

    if(right < n)
    {
        if(arr[left] > arr[right])
            p=left;
        else
            p=right;

        if(arr[location] < arr[p])
        {
            temp = arr[location];
            arr[location] = arr[p];
            arr[p] = temp;

        }

        reheap_down(p);
    }

}


void delet()
{
    int c;
    int mini=arr[0];
    cout<<mini<<endl;
    arr[0]=arr[n-1];
    n--;
    c=0;
    reheap_down(c);
}


int main()
{
    int num,k,m;
    n=0;
    cout<<"How many numbers you want ? \n";
    cin>>m;

    cout<<"Enter the element to insert : ";
    while(m--)
    {
        cin>>num;
        inser(num, n);
        n = n + 1;
    }
    display();

    cout<<"Enter the k largest element : ";
    cin>>k;
    for(int i=0; i<k ;i++)
    {
        delet();
    }

    return 0;
}
