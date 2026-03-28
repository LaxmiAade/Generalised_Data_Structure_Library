// Write a Program in C++ which is for Selection Sort Algorithm.

#include<iostream>
using namespace std;

void SelectionSort(int Arr[], int no)
{
    for(int x = 0; x < no - 1; x++)
    {
        int index_of_min = x;

        for(int y = x + 1; y < no; y++)
        {
            if(Arr[y] < Arr[index_of_min])
            {
                index_of_min = y;
            }
        }

        // Swap
        int temp = Arr[x];
        Arr[x] = Arr[index_of_min];
        Arr[index_of_min] = temp;
    }
}

void Display(int Arr[], int no)
{
    for(int i = 0; i < no; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int Arr[] = {64, 25, 12, 22, 11};
    int size = 5;

    cout << "Before Sorting: ";
    Display(Arr, size);

    SelectionSort(Arr, size);

    cout << "After Sorting: ";
    Display(Arr, size);

    return 0;
}
