#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
///create stack
void push()///insert at begening in linklist
{
    struct stack *curr;
    int n,i;

    printf("\nHow many data you keep in stack : \n");
    scanf("%d",&n);
    printf("\nenter elements : \n");

    for(i=0; i<n; i++)
    {
        curr=(struct stack*)malloc(sizeof(struct stack));
        scanf("%d",&curr->data);
        curr->next=top;
        top=curr;
    }
}

void pop()///delete from last in linklist
{
    struct stack *temp;
    temp=top;
    top=top->next;
    free(temp);
}

void display()
{
    struct stack *temp;
    temp=top;
    printf("\noperation completed : \n\n");
    while(temp != NULL)
    {
        printf("%d--->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int select;

    while(1)
    {
        printf("\n########## Stack_Menu ############\n\n");
        printf("1. Create Stack(PUSH) : ");
        printf("\n2. Display stack : ");
        printf("\n3. POP from stack : ");
        printf("\nplease select option : ");
        scanf("%d",&select);

        if(top==NULL)
        {
            if(select != 1)
            {
                printf("\nstack is empty.........\n");
                break;
            }
        }
        switch(select)
        {
        case 1:
            push();
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        default:
            printf("\ninvalid option ........\n");
        }
    }
    getch();
}
