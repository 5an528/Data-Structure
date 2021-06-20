#include<stdio.h>
int grp[50][50];

void create_graph(int size)
{
    int row,col;
    int x,y;

    for(row=0; row<size; row++)
    {
        for(col=0; col<size; col++)
        {
            grp[row][col]=0;
        }
    }

    for(row=0; row>=0; row++)
    {
        printf("\nInsert X and Y : \n");
        scanf("%d",&x);
        if(x==-1)
        {
            break;
        }
        scanf("%d",&y);

        grp[x][y]=1;
        grp[y][x]=1;

    }
}

void display(int size)
{
    int row,col;
    printf("\nOperation completed__________\n\n");
    for(row=0; row<size; row++)
    {
        for(col=0; col<size; col++)
        {
            printf("%d\t",grp[row][col]);
        }
        printf("\n");
    }
}
void add_newnode(int size)
{
    int i,x;
    for(i=0; i<size; i++)
    {
        printf("\nInput X : \n");
        scanf("%d",&x);
        if(x==-1)
        {
            break;
        }

        grp[size-1][x]=1;
        grp[x][size-1]=1;
    }
}
int remove_data(int size,int node)
{
    int i,j;
    for(i=node; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            grp[i][j]=grp[i+1][j];
        }
    }

    for(j=node; j<size; j++)
    {
        for(i=0; i<size; i++)
        {
            grp[i][j]=grp[i][j+1];
        }
    }
    size--;
    return size;
}
int main()
{
    int sel,order,ver;
    while(1)
    {
        printf("\n_____________ Graph_ADT________________\n\n");
        printf("1. Create Graph ");
        printf("\n2. Display Graph  ");
        printf("\n3. ADD New vertex into Graph");
        printf("\n4. Delete vertex from Graph");
        printf("\n5. Traverse the Graph");

        printf("\nSelect Option : ");
        scanf("%d",&sel);


        switch(sel)
        {
        case 1:
            printf("PLease enter the order of matrix : ");
            scanf("%d",&order);
            printf("\nenter vertex : \n");
            create_graph(order);

            break;
        case 2:
            display(order);
            break;
        case 3:
            order=order+1;
            add_newnode(order);
            break;
        case 4:
            printf("\nWhat vertex you want to remove : \n");
            scanf("%d",&ver);
            order=remove_data(order,ver);
            break;
        default:
            printf("\n__________invalid option____________");
        }
    }
}
