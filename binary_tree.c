#include<stdio.h>
#include<stdlib.h>

struct bt 
{
    int data;
    struct bt *left;
    struct bt *right;
};

struct bt* getnode()
{
    return (struct bt*) malloc(sizeof(struct bt));
}

void insert(struct bt *q, int val, char dir) 
{
    struct bt *temp;
    temp = getnode();
    temp->data = val;
    temp->left = temp->right = NULL;
    if(dir == 'l') 
    {
        q->left = temp;    
    }
    else 
    {
        q->right = temp;
    }
    return;
}

void preorder(struct bt *root) 
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct bt *root) 
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct bt *root) 
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    // Code Here
    struct bt *root = getnode();
    root->data = -1;
    root->left = root->right = NULL;
    insert(root, 5, 'l');
    insert(root, 6, 'r');
    insert(root->left, 7, 'l');
    insert(root->left, 8, 'r');
    printf("\npre-order traversal : \n");
    preorder(root);
    
    printf("\nin-order traversal : \n");
    inorder(root);
    
    printf("\npost-order traversal : \n");
    postorder(root);
    
    
    return 0;
}
