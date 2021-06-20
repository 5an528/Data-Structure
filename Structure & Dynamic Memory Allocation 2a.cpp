#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Shop
{
    int id,quantity;
    float price;
    char name[10],brandname[10],type[10];

};

int main()
{
    int n;
    char n1[10];
    Shop *S;

    S=(Shop*)malloc(2*sizeof(Shop));

    cout<<"How many Products --> \n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Product ID --> \n";

        scanf("%d", &(S+i)->id);
        cout<<"Product Name --> \n";
        cin.ignore();
        scanf("%s", &(S+i)->name);
        cout<<"Product Brand Name --> \n";
        cin.ignore();
        scanf("%s", &(S+i)->brandname);
        cout<<"Product Type --> \n";
        cin.ignore();
        scanf("%s", &(S+i)->type);
        cout<<"Product Quantity --> \n";
        cin.ignore();
        scanf("%d", &(S+i)->quantity);
        cout<<"Product Price --> \n";
        cin.ignore();
        scanf("%f", &(S+i)->price);
        cout<<endl;

    }
    cout<<"Search Product Brand name --> \n";
    scanf("%s", &n1);
    for(int i=0;i<n;i++)
    {
        if(strcmp(S->brandname,n1)==0)
        {
            cout<<endl;
            cout<<"Product Name --> "<<(S+i)->name<<endl;
            cout<<"Product Price --> "<<(S+i)->price<<"tk"<<endl;
        }
    }
}


