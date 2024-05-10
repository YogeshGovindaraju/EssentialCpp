#include <iostream>
#include <string>
using namespace std;

class Device
{
    string name;
public:
    Device() :name{ "" } {}
    void setName(string nameArg)
    {
        name = nameArg;
    }
    string getName()
    {
        return name;
    }
    friend ostream& operator<<(ostream& out, Device& operandTwo)
    {
        out << operandTwo.getName();
        return out;
    }
};

template<typename T>
class Vector
{
    int capacity;
    int position;
    T* items;
    int incrementSize;
public:
    Vector() :position{ 0 },capacity{10}, items{new T[capacity]}, incrementSize{10}
    {

    }
    Vector(int capacityArg) :position{ 0 }, capacity{ capacityArg }, items{ new T[capacity] }, incrementSize{ 10 }
    {

    }
    ~Vector()
    {
        delete[] items;
    }
    void push_back(T item)
    {
        if (position == capacity)
        {
            capacity += incrementSize;
            T* temp = new T[capacity];
            for (int i = 0; i < position; i++)
            {
                temp[i] = items[i];
            }
            delete[] items;
            items = temp;
        }
        items[position++] = item;
    }

    T operator [](const int& index)
    {
        return items[index];
    }

    friend ostream& operator<<(ostream& out, Vector& operandTwo)
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
    Vector<int> v{ 10 };
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

    Vector<string> vs;
    vs.push_back("A10");
    vs.push_back("A20");
    cout << vs << endl;

    Vector<Device> vd;
    Device obj1;
    obj1.setName("D1");
    Device obj2;
    obj2.setName("D2");
    vd.push_back(obj1);
    vd.push_back(obj2);
    
    cout << vd << endl;

    return 0;
}
