// In this File Write the Function of Bubble Sorting Algorithm by using Decreasing Order it is Sorted or not..

#include<iostream>
using namespace std;

#define INC_ORDER 1
#define DEC_ORDER 2

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

    bool CheckSorted();

    void BubbleSort();    // Declaration
    void BubbleSortEfficient(); 
    void BubbleSortEfficientX(int iOption); 
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

void ArrayX :: BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;
    int Pass = 0;                           // local variable for testing Purpose
    int Time = 0;

    if(Sorted == true)                      // Important -> It is Filter
    {
        return;
    }

    Time = 1;

    for(i = 0, Pass = 1; i < iSize - 1; i++, Pass++)              // Outer Loop
    {
        for(j = 0; j < iSize - 1 - i; j++, Time++)      // Inner Loop
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout<<"\nData After Pass : "<<i + 1<<"\n";
        Display();
    }

    cout<<"Number of Passes for Bubble Sort : "<<Pass<<"\n";
    cout<<"Total Number of Iterations : "<<Time<<"\n";
    
    Sorted = true;      // It Just Reset the flag
}

// Input Data -> 21   15  18  16  11

void ArrayX :: BubbleSortEfficient()
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;

    /*if(Sorted == true)                      // Important -> It is Filter
    {
        return;
    }
    */

    bFlag = true;

    for(i = 0; (i < iSize - 1) && (bFlag == true); i++)              // Outer Loop
    {
        bFlag = false;

        for(j = 0; j < iSize - 1 - i; j++)      // Inner Loop
        {
            if(Arr[j] > Arr[j + 1])             // It just checking Incresing order (< symbol)
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }

        cout<<"\nData After Pass : "<<i + 1<<"\n";
        Display();
    }

    cout<<"Number of Passes for Bubble Sort : "<<i<<"\n";
    
    Sorted = true;      // It Just Reset the flag
}

// 1 : Increasing order
// 2 : Decreasing Order
void ArrayX :: BubbleSortEfficientX(int iOption = INC_ORDER)                    
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;

    if(iOption < INC_ORDER || iOption > DEC_ORDER)
    {
        cout<<"Invalid Option for sorting\n";
        cout<<"1 : Increasing\n";
        cout<<"2 : Decreasing\n";
        return;
    }

    /*if(Sorted == true)                      // Important -> It is Filter
    {
        return;
    }
    */

    bFlag = true;

    if(iOption == INC_ORDER)
    {
        for(i = 0; (i < iSize - 1) && (bFlag == true); i++)              // Outer Loop
        {
            bFlag = false;

            for(j = 0; j < iSize - 1 - i; j++)      // Inner Loop
            {
                if(Arr[j] > Arr[j + 1])             // Convert it into Decreasing orderby using
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            } 
        }       
    }
    else if(iOption == DEC_ORDER)
    {
        for(j = 0; j < iSize - 1 - i; j++)      // Inner Loop
        {
            bFlag = false;
            
            if(Arr[j] < Arr[j + 1])             // Convert it into Decreasing orderby using
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }        
    }
        cout<<"\nData After Pass : "<<i + 1<<"\n";
        Display();
        
    cout<<"Number of Passes for Bubble Sort : "<<i<<"\n";
    
    Sorted = true;      // It Just Reset the flag
}

int main()
{
    int iValue = 0;

    cout<<"Enter the Number of Elements : \n";
    cin>>iValue;

   ArrayX aobj(iValue);    // Object created Statically...

   aobj.Accept();
   
   cout<<"Data Before Sorting\n";
   aobj.Display();

   // 1 : Increasing
   // 2 : Decreasing
   aobj.BubbleSortEfficientX(2);

   cout<<"Data After Sorting\n";

   aobj.Display();

    return 0;
}