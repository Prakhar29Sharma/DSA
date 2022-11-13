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



struct bt* insert(struct bt *r, int value)
{
    struct bt *nn = getnode();
    nn->data = value;
    nn->left = NULL;
    nn->right = NULL;

    if(r == NULL)
    {
        r = nn;
    }
    else
    {
        if(value >= r->data)
        {
            r->right = insert(r->right, value);
        }
        if(value < r->data)
        {
            r->left = insert(r->left, value);
        }
    }

    return r;
}

void preorder(struct bt *r)
{
    if(r!=NULL)
    {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct bt *r)
{
    
}

int main()
{
    struct bt *root = NULL;
    root = insert(root,3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 2);
    insert(root, 8);
    preorder(root);
    return 0;
}