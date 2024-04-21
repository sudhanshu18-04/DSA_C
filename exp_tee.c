// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>

// typedef struct node
// {
//     int data;
//     struct node* right, *left;
// }NODE;

// NODE*createnode()
// {
//     NODE*newnode = (NODE*)malloc(sizeof(NODE));
//     newnode->left = NULL;
//     newnode->right = NULL;
//     return newnode;
// }

// NODE*create_tree(char postfix[])
// {
//     NODE*temp;
//     NODE*s[70];
//     char symb;
//     int top = -1;
//     for(int i=0;i!='\0';i++)
//     {
//         symb = postfix[i];
//         temp= createnode();
//         temp->data = symb;
//         if(isalnum(symb))
//         {
//             s[++top] = temp;
//         }
//         else
//         {
//             temp->right = s[top--];
//             temp->left = s[top--];
//             s[++top] = temp;
//         }
//     }
//     return s[top--];
// }

// float evaluate(NODE*root)
// {
// 	float num;
// 	switch(root->data)
// 	{
// 		case '+': return evaluate(root->left) + evaluate(root->right);
// 		case '-': return evaluate(root->left) - evaluate(root->right);
// 		case '*': return evaluate(root->left) * evaluate(root->right);
// 		case '/': return evaluate(root->left) / evaluate(root->right);
// 		case '^':
// 		case '$':return pow(evaluate(root->left), evaluate(root->right));
// 		default: 
// 		if(isalpha(root->data))
// 		{
// 			printf("\n%c", root->data);
// 			scanf("%f", &num);
// 			return num;
// 		}
// 		else
// 			return root->data-'0';
// 	}
// }
// void main()
// {
// 	NODE*root=NULL;
// 	char postfix[70];
// 	float res;
// 	printf("\nEnter the postfix expression");
// 	scanf("%s", postfix);
// 	root=create_tree(postfix);
// 	res=evaluate(root);
// 	printf("\nThe computed result is =%f", res);
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node
{
    int data;
    struct node* right;
    struct node*left;
}NODE;

NODE*createnode()
{
    NODE*newnode = (NODE*)malloc(sizeof(NODE));
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

NODE*create_tree(char postfix[])
{
    NODE*temp;
    NODE*s[70];
    char symb;
    int top = -1;
    for(int i = 0;i!='\0';i++)
    {
        symb = postfix[i];
        temp = createnode();
        temp->data = symb;
        if(isalnum(symb))
        {
            s[++top] = temp;
        }
        else
        {
            temp->right = s[top--];
            temp->left = s[top--];
            s[++top] = temp;
        }
        return s[top--];
    }
}

NODE*create_tree(char postfix[])
{
    NODE*temp;
    NODE*s[70];
    char symb;
    int top = -1;
    for(int i=0;i!='\0';i++)
    {
        symb = postfix[i];
        temp = createnode();
        temp->data = symb;
        if(isalnum(symb))
        {
            s[++top] = temp;
        }
        else
        {
            temp->right = s[top--];
            temp->left = s[top--];
            s[++top] = temp;
        }
        return s[top--];
    }

}