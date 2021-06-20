
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Shop
{
    int id,quantity;
    float price;
    string name,brandname,type;

};

int main()
{
    Shop S[10];

    for(int i=0;i<2;i++)
    {
        cout<<"Product ID --> ";
        //cin.ignore();
        scanf("%d", &S[i]);
        cout<<"Product Name --> ";
        cin.ignore();
        getline(cin,S[i].name);
        cout<<"Product Brand Name --> ";
        cin.ignore();
        getline(cin,S[i].brandname);
        cout<<"Product Type --> ";
        cin.ignore();
        getline(cin,S[i].type);
        cout<<"Product Quantity --> ";
        //cin.ignore();
        scanf("%d", &S[i].quantity);
        cout<<"Product Price --> ";
        //cin.ignore();
        scanf("%f", &S[i].price);
        cout<<endl;

    }

    for(int i=0;i<2;i++)
    {
        if(S[i].price>40)
        {
            cout<<endl;
            cout<<"Product Name --> "<<S[i].name<<endl;
            cout<<"Product Price --> "<<S[i].price<<"tk"<<endl;
        }
    }
}
