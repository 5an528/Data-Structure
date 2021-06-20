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
    printf("what data you want to set in first : \n");
    scanf("%d",&(newnode->data));
    newnode->next=head;
    head=newnode;
}
void search()
{

    int data,count=0;
    cout<<"\nenter data you want to search :\n";
    cin>>data;
    struct node *tail;
    tail=head;

    while(tail!=NULL)
    {
        if(tail->data==data)
        {
            count=1;
            cout<<"\nData exist";
            break;
        }
        else
        {
            tail=tail->next;
        }
    }
    if(count==0)
    {
        cout<<"data cannot found";
    }
}
void insert_any()
{
   int pos,n,i,count=0;
   struct node *curr,*temp1,*temp;
   temp=head;
   curr=(struct node*)malloc(sizeof(struct node));
   cout<<"\nenter data you want to add : \n";
   cin>>curr->data;
   cout<<"\nenter position : \n";
   cin>>pos;
   while(temp!=NULL)
   {
       count++;
       temp=temp->next;
   }
   if(pos>count)
   {
       cout<<"\ncant insert \n";
   }
   else{
    if(pos==1)
    {
        insert_beg();
    }
    else
    {
        for(i=0; i<pos-1; i++)
   {
       temp1=temp;
       temp=temp->next;
       temp1->next=curr;
       curr->next=temp;
   }
    }
   }

   //display();
}
void remove_beg()
{
    struct node *temp;
    temp=head;
    temp=(struct node*)malloc(sizeof(struct node));
    head=head->next;
    free(temp);
}
void remove_last()
{
    struct node *temp,*temp1;
    temp=head;
    //temp=(struct node*)malloc(sizeof(struct node));
    while(temp->next != NULL)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    free(temp);
}
void remove_any()
{
    struct node *temp,*temp1;
    int pos,i;
    temp=head;
    cout<<"\nenter position you want to remove: \n";
    cin>>pos;
    if(pos==1)
    {
        remove_beg();
    }
    for(i=0; i<pos-1; i++)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;
    free(temp);

}
void reverse()
{
    struct node *prev,*curr,*next;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}
int main()
{
    int select;
    while(1)
    {
        cout<<"\n                        ############### LIST_ADT ################\n\n";
        cout<<"                                     1. creating list : ";
        cout<<"\n2. Insert node at first : ";
        cout<<"\n3. insert node at any position : ";
        cout<<"\n4. remove node from first : ";
        cout<<"\n5. remove node from any position : ";
        cout<<"\n6. remove node from last : ";
        cout<<"\n7. Display list : ";
        cout<<"\n8. search node : ";
        cout<<"\n9. reverse the list : ";
        cout<<"\n\nplease select : ";
        cin>>select;

        if(head==NULL)
        {
            if(select != 1)
            {
                cout<<"\nError : list empty";
                break;
            }
        }
        switch(select)
        {
        case 1:
            create_list();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_any();
            break;
        case 4:
            remove_beg();
            break;
        case 5:
            remove_any();
            break;
        case 6:
            remove_last();
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        case 9:
            reverse();
            break;
        default:
            cout<<"\nInvalid option";
        }
    }

    //create_list(n);
    //display();

    getch();
}
