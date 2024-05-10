#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Vector
{
    int capacity;
    int position;
    T* items;
    int incrementSize;
public:
    Vector() :position{ 0 }, capacity{ 1 }, items{ new T[capacity] }, incrementSize{ 1 }
    {

    }

    Vector(int capacityArg) :position{ 0 }, capacity{ capacityArg }, items{ new T[capacity] }, incrementSize{ 1 }
    {

    }

    ~Vector()
    {
        delete[] items;
    }

    int getSize()
    {
        return position;
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
        for (i = 0; i < operandTwo.getSize() - 1; i++)
        {
            out << operandTwo.items[i] << ",";
        }
        out << operandTwo.items[i] << endl;
        return out;
    }

};

template<typename K, typename V>
class KeyValuePair
{
public:
    K key;
    V value;
    void setKeyValue(K keyArg, V valueArg)
    {
        key = keyArg;
        value = valueArg;
    }
};

template<typename K, typename V> 
class Dictionary
{
    Vector<KeyValuePair<K,V>> keyValueList;
public:
	void add(K key, V value)
	{
        KeyValuePair<K, V> element;
        element.setKeyValue( key, value );
        keyValueList.push_back(element);
	}
    
    V operator[](K key)
    {
        for (int i = 0; i < keyValueList.getSize(); i++)
        {
            if (keyValueList[i].key == key)
                return keyValueList[i].value;
        }
        return NULL;
    }

};


int main()
{
	Dictionary<string, string> stringMap;
	stringMap.add("BLR", "Bengaluru");
	stringMap.add("CHN", "Chennai");
	string value = stringMap["BLR"];
	cout << value << endl;
    
	Dictionary<string, int> stringToIntMap;
	stringToIntMap.add("One", 1);
	stringToIntMap.add("Two", 2);
	int number = stringToIntMap["One"];
	cout << number << endl;
}