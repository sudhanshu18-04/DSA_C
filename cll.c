#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

struct list
{
    NODE *tail;
};
typedef struct list LIST;

void init(LIST *p)
{
    p->tail = NULL;
}

NODE *createnode(int data)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert_front(LIST *p, int data)
{
    NODE *newnode = createnode(data);
    if (p->tail == NULL)
    {
        p->tail = newnode;
        newnode->next = p->tail;
    }
    else
    {
        newnode->next = p->tail;
        p->tail->next = newnode;
    }
}

void insert_rear(LIST *p, int data)
{
    NODE *newnode = createnode(data);
    if (p->tail == NULL)
    {
        p->tail = newnode;
        newnode->next = p->tail;
    }
    else
    {
        newnode->next = p->tail->next;
        p->tail->next = newnode;
        p->tail = newnode;
    }
}

void delete_front(LIST *p)
{
    if (p->tail == NULL)
    {
        printf("the list is already empty");
    }
    else if (p->tail->next == p->tail)
    {
        NODE *temp = p->tail;
        p->tail = NULL;
        printf("Deleted node is %d", temp->data);
        free(temp);
    }
    else
    {
        NODE *temp = p->tail->next;
        p->tail->next = temp->next;
        printf("the deleted node is %d", temp->data);
        free(temp);
    }
}
void delete_rear(LIST *p)
{
    if (p->tail == NULL)
    {
        printf("the list is already empty");
    }
    else if (p->tail->next == p->tail)
    {
        NODE *temp = p->tail;
        p->tail = NULL;
        printf("Deleted node is %d", temp->data);
        free(temp);
    }
    else
    {
        NODE *cur = p->tail->next;
        NODE *prev = NULL;
        while (cur != p->tail)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        p->tail = prev;
        printf("\n The deleted node data is %d \n", cur->data);
        free(cur);
    }
}
void display(LIST *p)
{
    if (p->tail == NULL)
    {
        printf("\n List is Empty\n");
    }
    else
    {
        NODE *temp = p->tail->next;  
        printf("\n %d", temp->data); 
        temp = temp->next;
        while (temp != p->tail->next)
        {
            printf("\n %d", temp->data); 
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice, data, pos, x;
    LIST l1;
    init(&l1);
    do
    {
        printf("\n 1.Insert Front 2.Insert Rear");
        printf("\n 3.Delete Front 4.Delete Rear ");
        printf("\n 5.Display List 6.EXIT");
        printf("\n Enter choice: ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the element to be inserted at front: ");
            scanf("%d", &data);
            insert_front(&l1, data);
            break;
        case 2:
            printf("\n Enter the element to be inserted at rear: ");
            scanf("%d", &data);
            insert_rear(&l1, data);
            break;
        
        case 3:
            delete_front(&l1);
            break;
        case 4:
            delete_rear(&l1);
            break;
        case 5:
            display(&l1);
            break;
        case 6:
            printf("\n THANK YOU. EXITING..\n");
            break;
        default:
            printf("\n Invalid choice. Please try again! \n");
            break;
        }
    } while (choice != 6);
}