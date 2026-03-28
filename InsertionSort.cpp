// In this File Write the Function of Insertion Sorting Algorithm it is Sorted or not..

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

    bool CheckSorted();

    void InsertionSort(int Arr[],int No);    // Declaration
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

// Input Data -> 21   15  18  16  11

/*Data Before Sorting
Elements of the Array are : 
21	15	18	16	11	

Data After Pass : 1
Elements of the Array are : 
15	18	16	11	21	

Data After Pass : 2
Elements of the Array are : 
15	16	11	18	21	

Data After Pass : 3
Elements of the Array are : 
15	11	16	18	21	

Data After Pass : 4
Elements of the Array are : 
11	15	16	18	21	
Data After Sorting
Elements of the Array are : 
11	15	16	18	21	
*/

void ArrayX :: InsertionSort(int Arr[],int No)
{
    int i = 0, j = 0;
    int key = 0;

    if(Sorted == true)              // Important -> It is Filter
    {
        return;
    }

    for(i = 1; i < iSize; i++)              // Outer Loop
    {
        key = Arr[i];
        j = i - 1;

        while((j >= 0) && (Arr[j]) > key)      // Inner Loop
        {
            Arr[j + 1] = Arr[j];
            j--;
        }

        Arr[j + 1] = key;

        cout<<"\nData After Pass : "<<i + 1<<"\n";
        Display();
    }

    Sorted = true;      // It Just Reset the flag after Sorting
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

   aobj.InsertionSort(aobj.Arr, iValue);
   cout<<"Data After Sorting\n";
   aobj.Display();

    return 0;
}