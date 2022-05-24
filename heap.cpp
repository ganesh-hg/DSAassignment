#include <iostream>
using namespace std;

int const SIZE = 100;
class Heap
 {
public:
    int data[SIZE];
    int heapsize;

    Heap()
    {
        heapsize = 0;
    }
    void insert(int value);
    void insertMax(int value);
    void reHeapUp(int child);
    void disply();
    void mini();
    void maxi();
};
void Heap::insert(int value)
{
    int child = heapsize;
    heapsize = heapsize + 1;
    data[child] = value;
    reHeapUp(child);
}
void Heap::insertMax(int value) // For Maximum
{
    int child = heapsize;
    heapsize = heapsize + 1;
    data[child] = value;

    int parent = (child - 1) / 2;
    while (data[child] > data[parent] && child > 0)
    {
        int temp = data[parent];
        data[parent] = data[child];
        data[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}
void Heap::reHeapUp(int child)
{
    int parent = (child - 1) / 2;
    while (data[child] < data[parent] && child > 0)
    {
        int temp = data[parent];
        data[parent] = data[child];
        data[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}
void Heap::disply()
{
    if (heapsize == 0)
    {
        cout << "Heap is Empty !!" << endl;
    }
    else
    {
        cout << "The heap is : ";
        for (int i = 0; i < heapsize; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
}
void Heap::mini()
{
    cout << "Minimum marks in the subject are : " << data[0] << endl;
}

void Heap::maxi()
{
    cout << "Maximum marks in the subject are : " << data[0] << endl;
}
int main()
{
    Heap h, max;
    int c;
    while (1)
    {
        cout << "1. Insert 2.delete 3.Minimum Marks 4. Maximum Marks 5.Display 0. Exit" << endl;
        cin >> c;
        if (c == 0)
        {
            return 0;
        }
        else if (c == 1) // insert
        {
            int i;
            cout << "Enter the Value to insert" << endl;
            cin >> i;
            h.insert(i);
            max.insertMax(i);
        }
        else if (c == 3) // mini
        {
            h.mini();
        }

        else if (c == 4) // max
        {
            max.maxi();
        }

        else if (c == 5) // nothing
        {
            h.disply();
        }

        else
        {
            cout << "Wrong Choice Entered !!" << endl;
        }
    }

    return 0;
}