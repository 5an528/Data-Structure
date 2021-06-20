#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

int i=1;

void delt(node *pre, node *nex, int n)
{
    if(nex != NULL)
    {
        i++;
        if(n == 1)
        {
            node *temp;
            temp=head;
            head= pre->next;
            delete temp;
        }
        else if(i == n )
        {
            node *temp;
            temp=nex;
            pre->next=nex->next;
            delete temp;
        }
        else
            delt(nex,nex->next,n);

    }
}

void create_list()
{
    struct node *curr,*tail;

    int i,n=0;
    cout<<"\nHow Many Node You Want : \n";
    cin>>n;


    cout<<"enter elements : \n";

    for(i=0; i<n; i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        cin>>curr->data;
        curr->next=NULL;

        if(head==NULL)
        {
            head=curr;
            tail=curr;
        }
        else
        {
            tail->next=curr;
            tail=curr;
        }
    }
}

void display()
{
    struct node *temp;


    temp=head;
    cout<<"\noperation completed  : \n";

    while(temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
}


int main()
{
    create_list();
    display();
    struct node *temp;
    temp=head;
    int pos;
    cout<<endl<<"Enter the position you want to delete --> ";
    cin>>pos;
    delt(temp , temp->next , pos);
    display();

    return 0;
}
