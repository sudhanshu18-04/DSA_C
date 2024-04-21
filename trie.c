#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char output[25] = {};
int length;

typedef struct trienode
{
    struct trienode *child[26]; // Assuming only lowercase letters
    int eos;
} TRIE;

TRIE *createnode()
{
    TRIE *newnode = (TRIE *)malloc(sizeof(TRIE));
    for (int i = 0; i < 26; i++)
    {
        newnode->child[i] = NULL;
    }
    newnode->eos = 0;
    return newnode;
}

void insert_node(TRIE *root, char *word)
{
    TRIE *t = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a'; // Corrected: Calculate index based on ASCII value
        if (t->child[index] == NULL)
        {
            t->child[index] = createnode();
        }
        t = t->child[index];
        printf("\n%d", index);
    }
    t->eos = 1;
}

void display(TRIE *root)
{

    TRIE *t = root;
    for (int i = 0; i < 26; i++)
    {
        if (t->child[i] != NULL)
        {
            output[length++] = i + 'a';
            if (t->child[i]->eos == 1)
            {

                printf("\n");
                for (int j = 0; j < length; j++)
                    printf("%c", output[j]);
            }
            display(t->child[i]);
        }
    }

    return;
}
