#include<stdio.h>
#include<stdlib.h>
#define table_size 10

void init(int*table)
{
    for(int i=0;i<table_size;i++)
    {
        table[i] = -1;
    }
}

void insert(int*table,int value)
{
    int index = value%table_size;
    int i = 1;
    while(table[index]!=-1)
    {
        index = (index+i*i)%table_size;
        i++;
    }
    table[index] = value;
}

void display(int*table)
{
    for(int i=0;i<table_size;i++)
    {
        if(table[i]!=-1)
        printf("%d",table[i]);
    }
}
int main() {
    int hashTable[table_size];
    init(hashTable);

    int choice;
    int value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Display hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(hashTable,value);
                break;
            case 2:
                display(hashTable);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}