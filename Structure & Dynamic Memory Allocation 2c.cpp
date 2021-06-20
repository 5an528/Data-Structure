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
    char n1[10];
    float sum=0.00,sum1=0.00,sum2=0.00;
    Shop *S;

    S=(Shop*)malloc(2*sizeof(Shop));
    int n;
    cout<<"How many Products --> \n";
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
        cin.ignore();
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
            cout<<endl;
            sum2=sum2+(S+i)->price*(S+i)->quantity;
    }
    cout<<"Total asset of that particular type --> "<<sum2<<"tk"<<endl;
}


