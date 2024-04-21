#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node NODE;

struct list
{
    NODE *head;
};
typedef struct list LIST;

void init(LIST *p)
{
    p->head = NULL;
}

NODE *createnode(int data)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = NULL;
    temp->llink = NULL;
    return temp;
}

void insert_front(LIST *p, int data)
{
    NODE *newnode = createnode(data);
    if (p->head == NULL)
    {
        p->head = newnode;
        p->head->rlink = p->head;
        p->head->llink = p->head;
    }
    else
    {
        NODE *first = p->head;
        NODE *last = p->head->llink;
        newnode->rlink = first;
        first->llink = newnode;
        newnode->llink = last;
        last->rlink = newnode;
        p->head = newnode;
    }
}

void insert_rear(LIST *p, int data)
{
    NODE *newnode = createnode(data);
    if (p->head == NULL)
    {
        p->head = newnode;
        p->head->rlink = p->head;
        p->head->llink = p->head;
    }
    else
    {
        newnode->rlink = p->head;
        newnode->llink = p->head->llink;
        p->head->llink->rlink = newnode;
        p->head->llink = newnode;
    }
}

void delete_front(LIST *p)
{
    if (p->head == NULL)
    {
        printf("List pehli hi khali hai chutiye");
    }
    else if (p->head->rlink == p->head)
    {
        NODE *temp;
        temp = p->head;
        p->head = NULL;
        printf("Deleted element is %d", temp->data);
        free(temp);
    }
    else
    {
        NODE *temp;
        temp = p->head;
        p->head = p->head->rlink;
        p->head->llink = temp->llink;
        printf("Deleted node is %d", temp->data);
        free(temp);
    }
}

void delete_rear(LIST *p)
{
    if (p->head == NULL)
    {
        printf("List pehli hi khali hai chutiye");
    }
    else if (p->head->rlink == p->head)
    {
        NODE *temp;
        temp = p->head;
        p->head = NULL;
        printf("Deleted element is %d", temp->data);
        free(temp);
    }
    else
    {
        NODE *last = p->head->llink;
        last->llink->rlink = p->head;
        p->head->llink = last->llink;
        printf("The deleted data is %d", last->data);
        free(last);
    }
}
void display(LIST *p)
{
    if(p->head==NULL)
    {
        printf("\n The list is empty!\n");
    }
    else
    {
        NODE *temp=p->head;
        while(temp!=p->head->llink) 
        {
            printf("\n %d",temp->data); 
            temp=temp->rlink;
        }
        printf("\n %d",temp->data); 
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