// Doubly Linear Linked List specific to Generic...

#include<iostream>
using namespace std;

#pragma pack(1)
class node
{
    public:
        int data;
        node *next;
        node *prev;

        node(int no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

class DoublyCLL
{
    public:
        node * first;
        node * last;    
        int iCount;

        DoublyCLL();              // Default Constructor

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

DoublyCLL :: DoublyCLL() 
{
    cout<<"Doubly Circular Linked List gets created\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

void DoublyCLL :: InsertFirst(int no)
{
    node *newn = NULL;

    newn = new node(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;

        this->first->next = this->first;
        this->first->prev = this->first;
    }
    else
    {
        newn->next = this->first;
        newn->prev = this->last;

        this->first->prev = newn;
        this->last->next = newn;
        
        this->first = newn;
    }
    this->iCount++;
}

void DoublyCLL :: InsertLast(int no)
{
    node *temp = NULL;
    node *newn = NULL;

    newn = new node(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

void DoublyCLL :: InsertAtPos(int no,int pos)
{
    node *temp = NULL;
    node *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new node(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

void DoublyCLL :: DeleteFirst()
{
    if(this->first == NULL)                     // LL is Empty
    {
        return;
    }
    else if(this->first->next == NULL)          // LL Contains one Node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        // LL contains more than one node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

void DoublyCLL :: DeleteLast()
{
    node *temp = NULL;

    if(this->first == NULL)                     // LL is Empty
    {
        return;
    }
    else if(this->first->next == NULL)          // LL Contains one Node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        // LL contains more than one node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

void DoublyCLL :: DeleteAtPos(int pos)
{
    node *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

void DoublyCLL :: Display()
{
    node *temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |<=>";

        temp = temp->next;
    }
    cout<<"NULL\n";
}

int DoublyCLL :: Count()
{
    return this->iCount;
}


int main()
{
    DoublyCLL *dobj = new DoublyCLL();

    dobj->InsertFirst(51);
    dobj->InsertFirst(21);
    dobj->InsertFirst(11);

    dobj->Display();

    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast(101);
    dobj->InsertLast(111);
    dobj->InsertLast(121);

    dobj->Display();

    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos(105,4);
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    delete dobj;

    return 0;
}