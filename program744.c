// Start the program of Binary Serch Tree from this file ...

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)          // If Tree is Empty
    {
        *first = newn;
    }
    else                        // If tree contains atleast one node
    {
        temp = *first;

        while(1)
        {
            if(no > temp->data)                // If Element is Greater
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)           // If Element is Smaller
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(no == temp->data)           // If Element is identical
            {
               printf("Unable to insert as Element is Duplicate\n");
               free(newn);
               break;               // It is break the while loop not used for the if or else if
            }
        }
    }
}

// L    D   R
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\n",first->data);
        Inorder(first->rchild);
    }
}

// D    L   R
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\n",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

// L   R    D
void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\n",first->data);
    }
}

int main()
{
    PNODE head = NULL;

    Insert(&head,21);
    Insert(&head,11);
    Insert(&head,51);

    printf("Inorder Traversal : \n");
    Inorder(head);

    printf("Preorder Traverssal : \n");
    Preorder(head);

    printf("Postorder Traverssal : \n");
    Postorder(head);

    return 0;
}