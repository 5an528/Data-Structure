#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct NODE
{
    struct NODE *pRt,*pLf;
    string sWord,sMeaning;
} NODE;

string arr[100];
struct NODE* *pQ[20];
int iF,iR,i=1,j=0;
struct NODE *pRoot;

struct NODE* fCreate(string word,string meaning)
{
    struct NODE *pNn,*pCn,*pParent;
    char cCh;

    pNn=new struct NODE;
    pNn->pLf=pNn->pRt=NULL;

    pNn->sWord=word;
    pNn->sMeaning=meaning;

    if(pRoot==NULL)
        pRoot=pNn;
    else
    {
        pCn=pRoot;
        while(pCn)
        {
            pParent=pCn;
            if(pCn->sWord<pNn->sWord)
                pCn=pCn->pRt;
            else
                pCn=pCn->pLf;

        }
        if(pParent->sWord<pNn->sWord)
            pParent->pRt=pNn;
        else
            pParent->pLf=pNn;

    }

    return pRoot;
}

void CreateDic()
{
    pRoot=NULL;
    ifstream myfile ("word.txt");
    string word;
    string meaning;
    if (myfile.is_open())
    {
        while (myfile>>word>>meaning)
        {
            pRoot=fCreate(word,meaning);
        }
        myfile.close();
    }
}
bool Search(string searchword)
{
    struct NODE *pCn;

    pCn=pRoot;
    while(pCn)
    {
        if(pCn->sWord==searchword)
        {
            cout<<"Word Found : "<<searchword<<" \n";
            string mean;
            mean=pCn->sMeaning;
            std::replace( mean.begin(), mean.end(), '_', ' ');
            cout<<"Meaning : "<<mean<<" \n";
            return true;

        }
        else
        {
            if(pCn->sWord<searchword)
                pCn=pCn->pRt;
            else
                pCn=pCn->pLf;
        }

    }
    cout<<"Word not found!\n";
    return false;

}
void SearchSimilarNew(struct NODE *ptemp,string searchword)
{
    searchword[0] = toupper(searchword[0]);
    if(ptemp !=NULL)
    {
        if(ptemp->sWord[0]==searchword[0] && ptemp->sWord[1]==searchword[1] &&ptemp->sWord[2]==searchword[2])
        {
            if(i==1)
            {
                cout<<"Did You Mean : ";
                i++;
            }
            arr[j]=ptemp->sWord;
            j++;
            SearchSimilarNew(ptemp->pLf,searchword);
            SearchSimilarNew(ptemp->pRt,searchword);
        }
        else
        {
            SearchSimilarNew(ptemp->pLf,searchword);
            SearchSimilarNew(ptemp->pRt,searchword);
        }
    }
}
void AddNewWord()
{
    ofstream addword("word.txt",ofstream::app);
    string wordtext;
    cout<<"Word : ";
    cin>>wordtext;
    string meaningtxt;
    cout<<"Mean : ";
    cin>>meaningtxt;
    addword<<wordtext<<" "<<meaningtxt<<"\n";
}

void deleteWord(string dltword)
{
    ifstream myfile ("word.txt");
    string word;
    string meaning;
    string word1[500];
    string meaning1[500];
    int i=0;
    if (myfile.is_open())
    {
        while (myfile>>word>>meaning )
        {
            if(word!=dltword)
            {
                word1[i]=word;
                meaning1[i]=meaning;
                i++;
            }


        }
        myfile.close();
    }
    ofstream addword("word.txt");
    for(int j=0; j<i; j++)
    {
        addword<<word1[j]<<" "<<meaning1[j]<<"\n";
    }

}
int main()
{
    string searchword;
    char cCh;
    int iCh;
    cout<<"\t\t\t\t********************************************************\n";
    cout<<"\t\t\t\t*                                                      *\n";
    cout<<"\t\t\t\t*                                                      *\n";
    cout<<"\t\t\t\t*                   WORD DICTIONARY                    *\n";
    cout<<"\t\t\t\t*                                                      *\n";
    cout<<"\t\t\t\t*                                                      *\n";
    cout<<"\t\t\t\t********************************************************\n";
    cout<<"\n [1] Search Word. \n";
    cout<<"\n [2] Add New Word. \n";
    cout<<"\n [3] Delete Word. \n";
    do
    {
        CreateDic();
        string searchword,dltword;
        cout<<"\n\nEnter your Choice : ";
        cin>>iCh;
        if(iCh==1)
        {
            i=1;
            cout<<"Enter word to Search : ";
            cin>>searchword;
            bool searchst=Search(searchword);
            if(searchst==false)
            {
                SearchSimilarNew(pRoot,searchword);
                for(int k=0; k<j; k++)
                {
                    if(k==j-1)
                    {
                        cout<<arr[k]<<".";
                    }
                    else
                        cout<<arr[k]<<",";
                }
                j=0;
            }
        }


        else if(iCh==2)
        {
            cout<<"Enter new Word and meaning to dictionary : \n";
            AddNewWord();
            CreateDic();
        }

        else if(iCh==3)
        {
            cout<<"Enter The word you want to delete : ";
            cin>>dltword;
            deleteWord(dltword);
            cout<<"\n\nSelected Word Has Been Deleted.\n";
            CreateDic();
        }
        cout<<"\npress 1 for Continue and 2 to exit ";
        cin>>cCh;

    }
    while(cCh=='1');

    return 0;
}




