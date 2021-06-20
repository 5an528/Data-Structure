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
    cout<<endl;
}

void delet(int num)
{
    int left, right, i, temp, p;

    for (i = 0; i < num; i++)
    {
        if (num == arr[i])
            break;
    }
    if (num != arr[i])
    {
        cout<<num<<" not found in heap list\n";
        return;
    }
    arr[i] = arr[n - 1];
    n = n - 1;
    p =(i - 1) / 2;
    if (arr[i] > arr[p])
    {
        inser(arr[i], i);
        return;
    }
    left = 2 * i + 1;
    right = 2 * i + 2;
    while (right < n)
    {
        if (arr[i] >= arr[left] && arr[i] >= arr[right])
            return;
        if (arr[right] <= arr[left])
        {
            temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            i = left;
        }
        else
        {
            temp = arr[i];
            arr[i] = arr[right];
            arr[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == n - 1 && arr[i])
    {
        temp = arr[i];
        arr[i] = arr[left];
        arr[left] = temp;
    }
}

main()
{
    int choice, num;
    n=0;
    cout<<"            *****************************************************"<<endl;
    cout<<"            *                                                   *"<<endl;
    cout<<"            *                                                   *"<<endl;
    cout<<"            *                    WELCOME TO HEAP                *"<<endl;
    cout<<"            *                                                   *"<<endl;
    cout<<"            *                         ADT                       *"<<endl;
    cout<<"            *                                                   *"<<endl;
    cout<<"            *                                                   *"<<endl;
    cout<<"            *****************************************************"<<endl;
    while(1)
    {
        cout<<"1.Insertion (for one element at a time) \n";
        cout<<"2.Deletion \n";
        cout<<"3.Displaying Elements \n";
        cout<<"4.Quit \n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to insert : ";
            cin>>num;
            inser(num, n);
            n = n + 1;
            break;
        case 2:
            cout<<"Enter the element to delete : ";
            cin>>num;
            delet(num);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout<<"Invalid choice. \n";
        }
    }

    return 0;
}




