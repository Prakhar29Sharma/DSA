struct bst 
{
    int data;
    struct bst *left;
    struct bst *right;
};

struct bst* getnode()
{
    return (struct bst*) malloc(sizeof(struct bst));
}

struct bst* insert(struct bst *q, int val)
{
    struct bst* temp = NULL;
    if(q == NULL)
    {
        temp = getnode();
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        q = temp;
    }
    else
    {
        if(val < q->data) 
        {
            q->left = insert(q->left, val);
        }
        else
        {
            q->right = insert(q->right, val);
        }
    }
    return q;
}

struct bst* search(struct bst *p, int key, struct bst **y)
{
    struct bst *temp = NULL;
    if(p == NULL)
    {
        return NULL;
    }
    temp = p;
    *y = NULL;
    while(temp!=NULL)
    {
        if(temp->data == key)
            return (temp);
        else 
        {
            *y = temp;
            if(temp->data > key)
                temp = temp->left;
            else 
                temp = temp->right;
        }
    }
    return (NULL);
}
