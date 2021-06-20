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

void insert_beg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nwhat data you want to set in first : \n");
    scanf("%d",&(newnode->data));
    newnode->next=head;
    head=newnode;
}

void replac()
{
    struct node *temp, *temp1, *temp2;
    temp=head;
    temp2=head;
    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            temp1=temp;
        }
        temp=temp->next;
    }

    head->data=temp1->data;


}
int main()
{
    create_list();
    display();
    insert_beg();
    display();
    replac();
    display();
}
