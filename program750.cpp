#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside Constructor\n";
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()       // Destructor
        {
            cout<<"Inside Destructor\n";
            delete [] Arr;
        }

        void Accept()
        {
            int iCnt = 0;

            cout<<"Enter the Elements : \n";

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()
        {
            int iCnt = 0;

            cout<<"Elements of the Array are : \n";

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<"\n";
        }

        bool LinearSearch(int iNo)
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
};

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

    return 0;
}