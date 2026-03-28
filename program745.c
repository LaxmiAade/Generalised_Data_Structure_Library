// Start the program of Binary Serch Tree from this file ...

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool Search(PNODE first, int no)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first ->lchild;
        }
        else if(no == first->data)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

int main()
{
    PNODE head = NULL;
    bool bRet = false;

    Insert(&head,21);
    Insert(&head,11);
    Insert(&head,51);
    Insert(&head,67);
    Insert(&head,40);
    Insert(&head,10);
    Insert(&head,13);
    Insert(&head,38);

    printf("Inorder Traversal : \n");
    Inorder(head);

    bRet = Search(head,38);

    if(bRet == true)
    {
        printf("Element is Present\n");
    }
    else
    {
        printf("There is no Such Element\n");
    }
    
    return 0;
}