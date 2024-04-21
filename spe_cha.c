#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct node
{
    int data;
    struct node *link;
} NODE;

NODE *createnode(int key)
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->data = key;
    nn->link = NULL;
    return nn;
}

typedef struct hash
{
    int count;
    struct node *head;
} hash;

void insert(hash *hashtable, int key)
{
    int hash = key % size;
    NODE *nn = createnode(key);
    if (hashtable[hash].count == 0)
    {
        hashtable[hash].head = nn;
        hashtable[hash].count++;
    }
    NODE *t = hashtable[hash].head;
    while (t->link != NULL)
    {
        t = t->link;
    }
    t->link = nn;
    hashtable[hash].count++;
}

void search(hash *hashtable, int key)
{
    int hash = key % size;
    NODE *t = hashtable[hash].head;
    while (t != NULL)
    {
        int pos;
        pos++;
        if(t->data = key)
        {
            printf("The data is found at hash %d and position %d",hash,pos);
            return;
        }
        t = t->link;
    }
    printf("data not there");
}