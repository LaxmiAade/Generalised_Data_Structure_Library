/////////////////////////////////////////////////////////////////
            // Generalised Data Structure Library
/////////////////////////////////////////////////////////////////

/*
------------------------------------------------------------------------------------------------------------
    Type                     Name of class for node                Name of class for Functionality
------------------------------------------------------------------------------------------------------------

    Singly Linear            SinglyLLLnode                         SinglyLLL         DONE
    Singly Circular          SinglyCLLnode                         SinglyCLL         DONE
    Doubly Linear            DoublyLLLnode                         DoublyLLL         DONE
    Doubly Circular          DoublyCLLnode                         DoublyCLL         DONE
    Stack                    Stacknode                             Stack             DONE
    Queue                    Queuenode                             Queue             DONE

------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////
//  Singly Linear Linked List using Generic Approach..
/////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        // IMPORTNAT
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);    
        void InsertLast(T);  
        
        void DeleteFirst();
        void DeleteLast();
        
        void Display();
        int Count();
        
        void InsertAtPos(T ,int);
        void DeleteAtPos(int );       
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{   
    cout<<"\n-------------------------------------------------------------------";
    cout<<"\n------------ Singly Linear Linked List Gets Created Here : \n";
    cout<<"-------------------------------------------------------------------\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertFirst
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at First Position 
//                            in Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)         
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertLast
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at Last Position
//                            in Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void  SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)     
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
    }

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteFirst
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete First NODE 
//                            from Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void  SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteLast
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete Last NODE
//                            from Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void  SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Display
//  Input               :     None
//  Output              :     Display Elements
//  Description         :     Used to Display ALL NODES 
//                            from Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void  SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   // New code
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Count
//  Input               :     None
//  Output              :     Integer
//  Description         :     Used to Count Total Number of NODES
//                            in Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertAtPos
//  Input               :     Data and Position
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at Specific Position
//                            in Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void  SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
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
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteAtPos
//  Input               :     Position
//  Output              :     Nothing
//  Description         :     Used to Delete NODE from Specific Position 
//                            in Singly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void  SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
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

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
};

///////////////////....End of Singly Linear Linked List...///////////////////////

/////////////////////////////////////////////////////////////////////
//  Singly Circular Linked List using Generic Approach..
/////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;
    
    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);

        void DeleteFirst();
        void DeleteLast();

        void Display();
        int Count();

        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    
    cout<<"\n-------------------------------------------------------------------";
    cout<<"\n------------ Singly Circular Linked List gets created Here : \n";
    cout<<"-------------------------------------------------------------------\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertFirst
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at First Position 
//                            in Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = new SinglyCLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->last->next = this->first;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertLast
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at Last Position
//                            in Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = new SinglyCLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteFirst
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete First NODE 
//                            from Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    if(this->iCount == 0)
    {
        return;
    }
    else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->last->next;
        this->last->next = this->first;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteLast
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete Last NODE
//                            from Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    if(this->iCount == 0)
    {
        return;
    }
    else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        SinglyCLLnode<T> * temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;
        this->last->next = this->first;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Display
//  Input               :     None
//  Output              :     Display Elements
//  Description         :     Used to Display ALL NODES 
//                            from Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> * temp = this->first;

    for(int iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Count
//  Input               :     None
//  Output              :     Integer
//  Description         :     Used to Count Total Number of NODES 
//                            in Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertAtPos
//  Input               :     Data and Position
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at Specific Position
//                            in Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteAtPos
//  Input               :     Position
//  Output              :     Nothing
//  Description         :     Used to Delete NODE from Specific Position 
//                            in Singly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
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

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////....End of Singly Circular Linked List...///////////////////////


/////////////////////////////////////////////////////////////////////
// Doubly Linear Linked List using Generic code...
/////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode<T> *next;
        DoublyLLLnode<T> *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();              // Default Constructor

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL() 
{
    cout<<"\n-------------------------------------------------------------------";
    cout<<"\n------------ Doubly Linear Linked List Gets Created Here : \n";
    cout<<"-------------------------------------------------------------------\n";

    this->first = NULL;
    this->iCount = 0;

}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertFirst
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert at First Position 
//                            in Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertLast
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert at Last Position 
//                            in Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

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

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertAtPos
//  Input               :     Data and Position
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at Specific Position 
//                            in Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

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
        newn = new DoublyLLLnode<T>(no);

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

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteFirst
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete First NODE 
//                            from Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                     
    {
        return;
    }
    else if(this->first->next == NULL)          
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteLast
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete Last NODE 
//                            from Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                     
    {
        return;
    }
    else if(this->first->next == NULL)         
    {
        delete this->first;
        this->first = NULL;
    }
    else                                        
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

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteAtPos
//  Input               :     Position
//  Output              :     Nothing
//  Description         :     Used to Delete NODE from Specific Position 
//                            in Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
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

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Display
//  Input               :     None
//  Output              :     Display elements
//  Description         :     Used to Display ALL NODES 
//                            from Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" |<=>";

        temp = temp->next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Count
//  Input               :     None
//  Output              :     Integer
//  Description         :     Used to Count Total Number of NODES
//                            in Doubly Linear Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////....End of Doubly Linear Linked List...///////////////////////


/////////////////////////////////////////////////////////////////////
// Doubly Circular Linked List using Generic code...
/////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T);    
        void InsertLast(T);  

        void DeleteFirst();
        void DeleteLast();

        void Display();
        int Count();

        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    
    cout<<"\n-------------------------------------------------------------------";
    cout<<"\n------------ Doubly Circular Linked List Gets Created Here : \n";
    cout<<"-------------------------------------------------------------------\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertFirst
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert at First Position 
//                            in Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = new DoublyCLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertLast
//  Input               :     Data of node
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at Last Position 
//                            in Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> * newn = new DoublyCLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteFirst
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete First NODE 
//                            from Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(this->iCount == 0)
    {
        return;
    }
    else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->first->prev = this->last;
        this->last->next = this->first;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteLast
//  Input               :     None
//  Output              :     Nothing
//  Description         :     Used to Delete Last NODE 
//                            from Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(this->iCount == 0)
    {
        return;
    }
    else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Display
//  Input               :     None
//  Output              :     Display elements
//  Description         :     Used to Display ALL NODES 
//                            from Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> * temp = this->first;

    for(int iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Count
//  Input               :     None
//  Output              :     Integer
//  Description         :     Used to Count Total Number of NODES
//                            in Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     InsertAtPos
//  Input               :     Data and Position
//  Output              :     Nothing
//  Description         :     Used to Insert NODE at Specific Position 
//                            in Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     DeleteAtPos
//  Input               :     Position
//  Output              :     Nothing
//  Description         :     Used to Delete NODE from Specific Position 
//                            in Doubly Circular Linked List
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
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

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;

        this->iCount--;
    }
}

///////////////////....End of Doubly Circular Linked List...///////////////////////


/////////////////////////////////////////////////////////////////////
//              Stack using Generic Approach..
/////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);     
        T pop();          
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()                
{

    cout<<"\n-------------------------------------------------------------------";
    cout<<"\n------------ STACK Gets Created Successfully Here : \n";
    cout<<"-------------------------------------------------------------------\n";   

    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     PUSH
//  Input               :     Data of NODE
//  Output              :     Nothing
//  Description         :     Used to Insert NODE in Stack 
//                            using LIFO (Last In First Out) Principle
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
} 

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     POP
//  Input               :     None
//  Output              :     Data of Removed NODe
//  Description         :     Used to Delete NODE from Stack 
//                            using LIFO (Last In First Out) Principle
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}  

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     PEEP
//  Input               :     None
//  Output              :     Data of Top NODE
//  Description         :     Used to Display Top NODE of Stack 
//                            without Removing it...
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Display
//  Input               :     None
//  Output              :     Display Elements
//  Description         :     Used to Display all NODES of Stack
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<" |\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Count
//  Input               :     None
//  Output              :     Integer
//  Description         :     Used to Count Total Number of NODES in Stack
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////....End of STACK()Function Here...///////////////////////


/////////////////////////////////////////////////////////////////////
//              Queue using Generic Approach.....
/////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;

        int iCount;

    public:
        Queue();
        void enqueue(T);                   
        T dequeue();                       
        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()                
{

    cout<<"\n-------------------------------------------------------------------";
    cout<<"\n------------ QUEUE Gets Created Successfully Here : \n";
    cout<<"-------------------------------------------------------------------\n"; 

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Enqueue
//  Input               :     Data of NODE
//  Output              :     Nothing
//  Description         :     Used to Insert NODE in Queue 
//                            using FIFO (First In First Out) Principle
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    } 

    this->iCount++;
} 

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Dequeue
//  Input               :     None
//  Output              :     Data of Removed NODE
//  Description         :     Used to Delete NODE from Queue 
//                            using FIFO (First In First Out) Principle
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}  

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Display
//  Input               :     None
//  Output              :     Display elements
//  Description         :     Used to Display All NODES of Queue
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :     Count
//  Input               :     None
//  Output              :     Integer
//  Description         :     Used to Count Total Number of NODES in Queue
//  Author              :     Laxmi Rahul Rathod
//  Date                :     06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////
template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

///////////////////////.....End of All Functions() Library......///////////////////////////
int main()
{
    //////////////////////////////////////////////////////////////////////////////////
    //
    //  Data Structure Name     :     Singly Linear Linked List
    //  Input                   :     Integer Data Values
    //  Output                  :     Display Elements, Count NODES, 
    //                                Insert & Delete Operations
    //  Description             :     Demonstration of All Operations 
    //                                of Singly Linear Linked List
    //  Author                  :     Laxmi Rahul Rathod
    //  Date                    :     06/01/2026
    //
    //////////////////////////////////////////////////////////////////////////////////
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    cout<<"\nAfter InsertFirst :\n";
    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"\nAfter InsertLast :\n";
    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    cout<<"\nAfter DeleteFirst :\n";
    obj->DeleteFirst();
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    cout<<"\nAfter DeletetLast :\n";
    obj->DeleteLast();
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    cout<<"\nAfter InsertAtPos (105 at position 4) :\n";
    obj->InsertAtPos(105,4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    cout<<"\nAfter DeleteAtPos (position 4) :\n";
    obj->DeleteAtPos(4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cout<<"-------------------------------------------------------------------\n";
    cout<<"-------------- Singly Linear Linked List is Done Here -------------";
    cout<<"\n-------------------------------------------------------------------\n\n";
    
///////////////////....End of Singly Linear Linked List...///////////////////////

    //////////////////////////////////////////////////////////////////////////////////
    //
    //  Data Structure Name     :     Singly Circular Linked List
    //  Input                   :     Integer data values
    //  Output                  :     Display elements, Count NODES, 
    //                                Insert & delete operations
    //  Description             :     Demonstration of All Operations 
    //                                of Singly Circular Linked List
    //  Author                  :     Laxmi Rahul Rathod
    //  Date                    :     06/01/2026
    //
    //////////////////////////////////////////////////////////////////////////////////

    SinglyCLL<int> *obj1 = new SinglyCLL<int>();
    int iRet1 = 0;

    cout<<"\nAfter InsertFirst :\n";
    obj1->InsertFirst(51);
    obj1->InsertFirst(21);
    obj1->InsertFirst(11);

    obj1->Display();
    iRet1 = obj1->Count();
    cout<<"Number of nodes are : "<<iRet1<<"\n";

    cout<<"\nAfter InsertLast :\n";
    obj1->InsertLast(101);
    obj1->InsertLast(111);
    obj1->InsertLast(121);

    obj1->Display();
    iRet1 = obj1->Count();
    cout<<"Number of nodes are : "<<iRet1<<"\n";

    cout<<"\nAfter DeleteFirst :\n";
    obj1->DeleteFirst();
    obj1->Display();
    iRet1 = obj1->Count();
    cout<<"Number of nodes are : "<<iRet1<<"\n";

    cout<<"\nAfter DeleteLast:\n";
    obj1->DeleteLast();
    obj1->Display();
    iRet1 = obj1->Count();
    cout<<"Number of nodes are : "<<iRet1<<"\n";

    cout<<"\nAfter InsertAtPos (105 at position 4) :\n";
    obj1->InsertAtPos(105,4);
    obj1->Display();
    iRet1 = obj1->Count();
    cout<<"Number of nodes are : "<<iRet1<<"\n";

    cout<<"\nAfter DeleteAtPos (position 4) :\n";
    obj1->DeleteAtPos(4);
    obj1->Display();
    iRet1 = obj1->Count();
    cout<<"Number of nodes are : "<<iRet1<<"\n";

    cout<<"-------------------------------------------------------------------\n";
    cout<<"----------- Singly Circular Linked List is Done Here --------------";
    cout<<"\n-------------------------------------------------------------------\n\n";

///////////////////////...End of Singly Circular Linked List.../////////////////////

//////////////////////////////////////////////////////////////////////////////////
//
//  Data Structure Name     :     Doubly Linear Linked List
//  Input                   :     Integer Data Values
//  Output                  :     Display Elements, Count NODES, 
//                                Insert & Delete Operations
//  Description             :     Demonstration of All Operations 
//                                of Doubly Linear Linked List
//  Author                  :     Laxmi Rahul Rathod
//  Date                    :     06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    cout<<"\nAfter InsertFirst :\n";
    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    cout<<"\nAfter InsertLast :\n";
    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    cout<<"\nAfter DeleteFirst :\n";
    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    cout<<"\nAfter DeleteLast :\n";
    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    cout<<"\nAfter InsertAtPos (105 at position 4) :\n";
    dobj->InsertAtPos('$',4);
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    cout<<"\nAfter DeleteAtPos (position 4) :\n";
    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Number of Elements are : "<<dobj->Count()<<"\n";

    cout<<"-------------------------------------------------------------------\n";
    cout<<"-------------- Doubly Linear Linked List is Done Here -------------";
    cout<<"\n-------------------------------------------------------------------\n\n";
    
    delete dobj;

////////////////////////...End of Doubly Linear Linked List...//////////////////////

    //////////////////////////////////////////////////////////////////////////////////
    //
    //  Data Structure Name     :     Doubly Circular Linked List
    //  Input                   :     Integer data values
    //  Output                  :     Display Elements, Count NODES,
    //                                Insert & Delete operations
    //  Description             :     Demonstration of All Operations 
    //                                of Doubly Circular Linked List
    //  Author                  :     Laxmi Rahul Rathod
    //  Date                    :     06/01/2026
    //
    /////////////////////////////////////////////////////////////////////////////////

    DoublyCLL<int> *obj2 = new DoublyCLL<int>();
    int iRet2 = 0;

    cout<<"\nAfter InsertFirst :\n";
    obj2->InsertFirst(51);
    obj2->InsertFirst(21);
    obj2->InsertFirst(11);

    obj2->Display();
    iRet2 = obj2->Count();
    cout<<"Number of nodes are : "<<iRet2<<"\n";

    cout<<"\nAfter InsertLast :\n";
    obj2->InsertLast(101);
    obj2->InsertLast(111);
    obj2->InsertLast(121);

    obj2->Display();
    iRet2 = obj2->Count();
    cout<<"Number of nodes are : "<<iRet2<<"\n";

    cout<<"\nAfter DeleteFirst :\n";
    obj2->DeleteFirst();
    obj2->Display();
    iRet2 = obj2->Count();
    cout<<"Number of nodes are : "<<iRet2<<"\n";

    cout<<"\nAfter DeleteLast :\n";
    obj2->DeleteLast();
    obj2->Display();
    iRet2 = obj2->Count();
    cout<<"Number of nodes are : "<<iRet2<<"\n";

    cout<<"\nAfter InsertAtPos (105 at position 4) :\n";
    obj2->InsertAtPos(105,4);
    obj2->Display();
    iRet2 = obj2->Count();
    cout<<"Number of nodes are : "<<iRet2<<"\n";

    cout<<"\nAfter DeleteAtPos (position 4) :\n";
    obj2->DeleteAtPos(4);
    obj2->Display();
    iRet2 = obj2->Count();
    cout<<"Number of nodes are : "<<iRet2<<"\n";

    cout<<"-------------------------------------------------------------------\n";
    cout<<"----------- Doubly Circular Linked List is Done Here --------------";
    cout<<"\n-------------------------------------------------------------------\n\n";

//////////////////////...End of Doubly Circular Linked List...////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////
    //
    //  Data Structure Name :     Stack
    //  Input               :     Integer data values
    //  Output              :     PUSH, POP, Display Elements
    //  Description         :     Demonstration of Stack Operations using LIFO principle
    //  Author              :     Laxmi Rahul Rathod
    //  Date                :     06/01/2026
    //
    ///////////////////////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();

    cout<<"Number of Elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<sobj->peep()<<"\n";
    sobj->Display();
    cout<<"Number of Elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped Element is : "<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of Elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped Element is : "<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of Elements in Stack are : "<<sobj->Count()<<"\n";

    sobj->push('e');
    sobj->Display();
    cout<<"Number of Elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"-------------------------------------------------------------------\n";
    cout<<"---------------------- STACK is Done Here -------------------------";
    cout<<"\n-------------------------------------------------------------------\n\n";
    
    delete sobj;
    
//////////////////////////////...End of STACK Library Here...////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////
    //
    //  Data Structure Name :     Queue
    //  Input               :     Integer data values
    //  Output              :     Enqueue, Dequeue, Display Elements
    //  Description         :     Demonstration of QUEUE Operations using FIFO Principle
    //  Author              :     Laxmi Rahul Rathod
    //  Date                :     06/01/2026
    //
    ///////////////////////////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();

    cout<<"Number of Elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed Element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of Elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed Element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of Elements in Queue are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);
    qobj->Display();
    cout<<"Number of Elements in Queue are : "<<qobj->Count()<<"\n";

    cout<<"-------------------------------------------------------------------\n";
    cout<<"----------------------- QUEUE is Done Here ------------------------";
    cout<<"\n-------------------------------------------------------------------\n\n";
    
    delete qobj;
//////////////////////////////...End of QUEUE Library Here...////////////////////////////

    return 0;
}
