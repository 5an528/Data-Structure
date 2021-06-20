#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right_child;
    struct node *left_child;
};

int search(struct node *root, int x)
{
    if(root!=NULL)
    {
        if(root->data==x)
         return 1;
        else if(x>=root->data)
         return search(root->right_child, x);
        else if(x<root->data)
         return search(root->left_child,x);
        else
        {

             return 0;
        }

    }
}

int  find_minimum(struct node *root)
{

     if(root->left_child != NULL)
        return find_minimum(root->left_child);
    return root->data;

}

int  find_maximum(struct node *root)
{

     if(root->right_child != NULL)
        return find_maximum(root->right_child);
    return root->data;

}

struct node* insert(struct node *root, int x)
{

    if(root==NULL)
    {

         root =(struct node*) malloc(sizeof(struct node));
         root->data = x;
         root->left_child = NULL;
         root->right_child = NULL;
    }
    else if(x>=root->data)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child,x);
    return root;
}


struct node* delete(struct node *root, int x)
{

    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {

        postorder(root->left_child);
        postorder(root->right_child);
        printf(" %d ", root->data);
    }
}
int main()
{
    struct node *root= NULL;
    int search1;
    int n,i,d;
    printf("\n Enter number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter node:");
        scanf("%d",&d);
        root = insert(root, d);
    }
    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");
  //  root = delete(root, 1);
    printf("\n");
    search1= search(root,4);
    if(search1==1)
     printf("Found ");
    else
     printf("Not Found ");
    int min= find_minimum(root);
     printf("\n Minimum: %d", min);
    int max= find_maximum(root);
     printf("\n Maximum: %d", max);
    return 0;
}
