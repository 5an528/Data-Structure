#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};
struct Node *head= NULL,*tail;

void print()
{
    struct Node *list= head;
    printf("\n linked list :" );
    while(list != NULL)
    {
      printf(" %d   ", list->data);
      list = list->next;
    }
}

void addbeg()
{
    struct Node *item;
    item = (struct Node*) malloc(sizeof(struct Node));
    cout<<"\n enter new data to add beginning:";
    cin>>item->data;
    item->prev = item-> next = NULL;
    item->next = head;
    head = item;
}
void addlast()
{
    struct Node *ne,*list= head;
    ne = (struct Node*)malloc(sizeof(struct Node));
    cout<<"\n enter new data to add last:";
    cin>>ne->data;
    ne -> prev = ne->next = NULL;

    while (list->next!= NULL)
    {

        list = list->next;
    }
    list->next = ne;

}
void create()    //Confusing Part of this CODE
{
          struct Node *item;
          char ch1,ch;
          cout<<"\n \t\t\t Create Linked List\n";
          while(ch1 != 'n')
          {
            cout<<"\n Enter Data:";
            item = (struct Node*)malloc(sizeof(struct Node));
            cin>>item->data;
            item->next = item -> prev = NULL;
            if (head == NULL)
            {
              head = item;
              tail = item;
            }
            else
            {
              tail->next = item;
              tail = item;
            }
            cout<<"\n Do you want to enter number again ?(y/n)";
            ch1= getche();
          }
}
void addanypos()
{
    int pos,i;
    struct Node *temp= head, *temp1,*item;
    cout<<"\n Enter position number: ";
    cin>>pos;
    cout<<"\n Enter Data:";
    item = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d", &item->data);
    item->next = item->prev = NULL;
    for(i=1;i<pos;i++)
    {
        temp1= temp;
        temp= temp->next;
    }
    temp1->next= item;
    item->prev= temp1;
    item->next = temp;
    temp->prev = item;
}
void deletefrombeg()
{
    struct Node * temp = head;
    head=head->next;
    free(temp);
}

void deletefromlast()
{
    struct Node *list= head,*list1;
    while (list->next != NULL)
    {
        list1= list;
        list = list->next;
    }
    list1->next = NULL;
    free(list);
}
void deletefrommidpos()
{
    int pos,i;
    struct Node *temp= head, *temp1;
    cout<<"\n Enter position number: ";
    cin>>pos;
    for(i=1;i<pos;i++)
    {
        temp1= temp;
        temp= temp->next;
    }
    temp1->next= temp->next;
    temp->next->prev = temp1;
    free(temp);
}
int main()
{
            int l=2;
            create();
            while(--l)
            {
            cout<<"\n 1. Insert At Beginning \n 2. Insert At last \n 3. Insert At any Middle Position \n 4. Delete from Beginning";
            cout<<"\n 5. Delete from last \n 6. Delete  from any Middle Position \n 7. Display \n 8. Exit";
            int option;
            cout<<"\n Enter Option ";
            cin>>option;
            if(option==1)
               addbeg();
            else if(option==2)
                addlast();
            else if(option==3)
                addanypos();
            else if(option==4)
                deletefrombeg();
            else if(option==5)
                deletefromlast();
            else if(option==6)
                deletefrommidpos();
            else if(option==7)
                print();
            else if(option==8)
                break;
         }
  return 0;
}
