// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     int lthread;
//     int rthread;
//     struct node* left;
//     struct node* right;
// }NODE;

// NODE*createnode(int data)
// {
//     NODE*nn = (NODE*)malloc(sizeof(NODE));
//     nn->data = data;
//     return nn;
// }

// NODE*insertnode(NODE*root,int data)
// {
//     NODE*t = root;
//     NODE*parent,*nn;
//     nn = createnode(data);
//     if(t==NULL)
//     {
//         nn->lthread = 1;
//         nn->rthread = 1;
//         nn->left = NULL;
//         nn->right = NULL;
//         root = nn;
//         return root;
//     }

//     while(t!=NULL)
//     {
//         parent = t;
//         if(data<t->data)
//         {
//             if(t->lthread==0)
//             {
//                 t = t->left;
//             }
//             else
//             break;
//         }
//         else if(data>t->data)
//         {
//             if(t->rthread==0)
//             {
//                 t = t->right;
//             }
//             else
//             break;
//         }
//         else{
//             printf("DUPLICATE KEY");
//             return root;
//         }

//         if(data<parent->data)
//         {
//             nn->lthread=1;
//             nn->rthread = 1;
//             nn->right = parent;
//             nn->left = parent->left;
//             parent->left = nn;
//             parent->lthread = 0;
//         }
//         else
//         {
//             nn->lthread=1;
//             nn->rthread = 1;
//             nn->right = parent->right;
//             nn->left = parent;
//             parent->right = nn;
//             parent->rthread = 0;
//         }
//         return root;
//     }
// }
// NODE* inorderSuccessor(NODE *t){
//     if(t->rthread==1)//if it doesn't has a right child
//         return t->right;//inorder successor link is present in the right link
//     //if(t->rthread==0)//if it has a right child
//     t=t->right;
//     while(t->lthread==0)
//         t=t->left;
//     return t;
// }
// void inorder(NODE *root){
//     NODE *t=root;
//     if(root!=NULL){
//         while(t->lthread==0)//t->left!=NULL
//             t=t->left;
//         while(t!=NULL){
//             printf("%d ",t->data);
//             t=inorderSuccessor(t);
//         }
//     }
// }


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int rthread;
    int lthread;
    struct node *left;
    struct node *right;
    int data;
}NODE;

NODE*createnode(int data)
{
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    return newnode;
}

NODE*insertnode(NODE*root,int data)
{
    NODE*t = root;
    NODE*parent = t;
    NODE*nn = createnode(data);
    if(t=NULL)
    {
        nn->lthread = 1;
        nn->rthread = 1;
        nn->left = NULL;
        nn->right = NULL;
        root = nn;
        return root;
    }
    while(t!=NULL)
    {
        parent = t;
        if(data<t->data)
        {
            if(t->lthread==0)
            {
                t=t->left;
            }
            else
            break;
        }

        else if(data>t->data)
        {
            if(t->rthread==0)
            {
                t=t->right;
            }
            else
            break;
        }

        if(data<parent->data)
        {
            nn->lthread =1;
            nn->rthread =1;
            nn->left = parent->left;
            nn->right = parent;
            parent->left = nn;
            parent->lthread =0;
        }

        if(data>parent->data)
        {
            nn->lthread =1;
            nn->rthread =1;
            nn->left = parent;
            nn->right = parent->right;
            parent->right = nn;
            parent->rthread =0;
        }
        return root;




    }
}

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int rthread;
    int lthread;
    struct node *left;
    struct node *right;
    int data;
}NODE;

NODE*createnode(int data)
{
    NODE*nn = (NODE*)malloc(sizeof(NODE));
    nn->data = data;
    return nn;
}

void insert(NODE*root,int data)
{
    NODE*t = root;
    NODE*parent = t;
    NODE*nn = createnode(data);

    if(t==NULL)
    {
        nn->lthread = 1;
        nn->rthread = 1;
        nn->right = NULL;
        nn->left = NULL;
        return nn;
        return root;
    }

    while(t!=NULL)
    {
        if(data<t->data)
        {
            if(t->lthread==0)
            {
                t = t->left;
            }
            else
            break;
        }

        if(data>t->data)
        {
            if(t->rthread==0)
            {
                t = t->right;
            }
            else
            break;
        }

        if(data<parent->data)
        {
            nn->lthread = 1;
            nn->rthread = 1;
            nn->left = parent->left;
            nn->right = parent;
            parent->left = nn->left;
            parent->lthread = 0;
        }

        if(data<parent->data)
        {
            nn->lthread = 1;
            nn->rthread = 1;
            nn->left = parent;
            nn->right = parent->right;
            parent->right = nn->right;
            parent->rthread = 0;
        }
    }
}