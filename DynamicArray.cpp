#include <iostream>
using namespace std;

class IntVector
{
    int capacity;
    int position;
    int* items;
    int incrementSize;
public:
    IntVector() :position{ 0 },capacity{10}, items{new int[capacity]}, incrementSize{10}
    {

    }
    IntVector(int capacityArg) :position{ 0 }, capacity{ capacityArg }, items{ new int[capacity] }, incrementSize{ 10 }
    {

    }
    ~IntVector()
    {
        delete[] items;
    }
    void push_back(int item)
    {
        if (position == capacity)
        {
            capacity += incrementSize;
            int* temp = new int[capacity];
            for (int i = 0; i < position; i++)
            {
                temp[i] = items[i];
            }
            delete[] items;
            items = temp;
        }
        items[position++] = item;
    }

    int operator [](const int& index)
    {
        return items[index];
    }

    friend ostream& operator<<(ostream& out, IntVector& operandTwo)
    {
        int i;
        for (i = 0; i < operandTwo.position - 1; i++)
        {
            out << operandTwo.items[i] << ",";
        }
        out << operandTwo.items[i]<< endl;
        return out;
    }

};

int main()
{
    IntVector v{ 10 };
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(90);
    v.push_back(110);
    v.push_back(120);
    v.push_back(130);
    v.push_back(140);
    v.push_back(150);
    v.push_back(160);
    v.push_back(170);
    int item = v[3];
    cout << item << endl;
    cout << v << endl;
    return 0;
}