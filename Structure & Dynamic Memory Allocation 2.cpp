
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
    Shop *S;

    S=(Shop*)malloc(2*sizeof(Shop));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Product ID --> \n";
        //cin.ignore();
        scanf("%d", &(S+i)->id);
        cout<<"Product Name --> \n";
        cin.ignore();
        scanf("%s", &(S+i)->name);
        cout<<"Product Brand Name --> \n";
        //cin.ignore();
        scanf("%s", &(S+i)->brandname);
        cout<<"Product Type --> \n";
        //cin.ignore();
        scanf("%s", &(S+i)->type);
        cout<<"Product Quantity --> \n";
        //cin.ignore();
        scanf("%d", &(S+i)->quantity);
        cout<<"Product Price --> \n";
        //cin.ignore();
        scanf("%f", &(S+i)->price);
        cout<<endl;

    }

    for(int i=0;i<n;i++)
    {
        if((S+i)->price>40)
        {
            cout<<endl;
            cout<<"Product Name --> "<<(S+i)->name<<endl;
            cout<<"Product Price --> "<<(S+i)->price<<"tk"<<endl;
        }
    }
}

