#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;

struct hash
{
    int count;
    struct node *head;
};
typedef struct hash HashTable;

Node *createNode(int key)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = key;
    nn->next = NULL;
    return nn;
}

void insert(int key, HashTable *hashTable)
{
    int hash;
    Node *nn, *t;
    hash = key % SIZE;
    nn = createNode(key);
    if (hashTable[hash].count == 0)
    {
        hashTable[hash].head = nn;
        hashTable[hash].count++;
    }
    else
    {
        t = hashTable[hash].head;
        while (t->next != NULL)
            t = t->next;
        t->next = nn;
        hashTable[hash].count++;
    }
}

void display(HashTable *hashTable)
{
    for (int i = 0; i < SIZE; i++)
    {
        Node *t = hashTable[i].head;
        while (t != NULL)
        {
            printf("%d->", t->data);
            t = t->next;
        }
        printf("NULL");
    }
}
void search(int key, HashTable *hashTable)
{
    int hash, pos = 0;
    Node *t;
    hash = key % SIZE;
    t = hashTable[hash].head;

    while (t != NULL)
    {
        pos++;
        if (t->data == key)
        {
            printf("\nData found at index %d in position %d", hash, pos);
            return;
        }
        t = t->next;
    }
    printf("\nData not found");
}
void deleteData(int key, HashTable *hashTable)
{
    int hash, pos = 0;
    Node *t, *prev;
    hash = key % SIZE;
    t = hashTable[hash].head;
    while (t != NULL)
    {
        pos++;
        if (t->data == key)
        {
            if (pos == 1)
                hashTable[hash].head = t->next;
            else
            {
                prev = hashTable[hash].head;
                while (prev->next != t)
                    prev = prev->next;
                prev->next = t->next;
            }
            free(t);
            hashTable[hash].count--;
            return;
        }
        t = t->next;
    }
    printf("\nData not found");
}
void main()
{
    int key, ch;
    HashTable hashTable[SIZE] = {};
    do
    {
        printf("\nEnter the key to be inserted:");
        scanf("%d", &key);
        insert(key, hashTable);
        printf("\nTo exit Press 0:");
        scanf("%d", &ch);
    } while (ch);
    display(hashTable);
    do
    {
        printf("\nEnter the key to be searched:");
        scanf("%d", &key);
        search(key, hashTable);
        printf("\nTo exit Press 0:");
        scanf("%d", &ch);
    } while (ch);
    do
    {
        printf("\nEnter the key to be deleted:");
        scanf("%d", &key);
        deleteData(key, hashTable);
        display(hashTable);
        printf("\nTo exit Press 0:");
        scanf("%d", &ch);
    } while (ch);
}
