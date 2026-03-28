// We have create Singly Linear Linked List Here...

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;           // Double Pointer

class SinglyLL
{
    public:
        PNODE first;            // Pointer
        int iCount;             // Characteristics named as iCount used for counter

        SinglyLL()              // Default Constructor
        {
            cout<<"Object of SinglyLL gets created.\n";
            first = NULL;
            iCount = 0;
        }   
};

int main()
{
    SinglyLL obj1;
    SinglyLL obj2;
    
    return 0;
}