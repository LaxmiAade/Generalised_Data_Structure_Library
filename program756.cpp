// In this File Write the Function(Characteristics(CheckSorted())) of Array it is Sorted or not..

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

    ArrayX(int no);
    ~ArrayX();
    void Accept();
    void Display();
    bool LinearSearch(int iNo);
    bool BiDirectionalSearch(int iNo);
    bool CheckSorted();
    bool BinarySearch(int iNo);
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside Constructor\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

ArrayX :: ~ArrayX()       // Destructor
{
    cout<<"Inside Destructor\n";
    delete [] Arr;
}

void ArrayX :: Accept()
{
    int iCnt = 0;

    cout<<"Enter the Elements : \n";
    cin>>Arr[iCnt];

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt - 1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }

    //Sorted = CheckSorted();
}

void ArrayX :: Display()
{
    int iCnt = 0;

    cout<<"Elements of the Array are : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

bool ArrayX :: LinearSearch(int iNo)
{
    int i= 0;
    bool bFlag = false;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == iNo)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

bool ArrayX :: BiDirectionalSearch(int iNo)
{
    bool bFlag = false;
    int iStart = 0;
    int iEnd = 0;

    for(iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == iNo || Arr[iEnd] == iNo)
        {
            bFlag = true;
            break;
        }
    }
    return bFlag;
}

// iSize = 10;
//  0    1   2   3   4   5   6   7   8   9
//  12  14  17  24  42  36  48  52  52  65
bool ArrayX :: CheckSorted()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i+1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

bool ArrayX :: BinarySearch(int iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if(iNo < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(iNo > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }
    return bFlag;
}

int main()
{
    int iValue = 0;

    cout<<"Enter the Number of Elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);    // Object created Statically...

    aobj.Accept();
    
    aobj.Display();

    if(aobj.LinearSearch(21))
    {
            cout<<"Element is present....\n";
    }
    else
    {
            cout<<"There is no such Element...\n";
    }

    if(aobj.BiDirectionalSearch(21))
    {
            cout<<"Element is present....\n";
    }
    else
    {
            cout<<"There is no such Element...\n";
    }

    if(aobj.Sorted == true)
    {
        cout<<"Data is Sorted\n";
    }
    else
    {
        cout<<"Data is not Sorted\n";
    }


    if(aobj.BinarySearch(25))
    {
        cout<<"Element is Present\n";
    }
    else
    {
        cout<<"There is no Such Element\n";
    }
    
    return 0;
}