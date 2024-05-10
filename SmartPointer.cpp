#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A Instantiated" << endl;
	}
	~A()
	{
		cout << "A Destructed" << endl;
	}
	void operation()
	{
		cout << "A.operation called" << endl;
	}
};

template<typename C>
class SmartPointerOfAnyType
{
	C* ptr;
public:
	SmartPointerOfAnyType(C* ptrRef) : ptr{ ptrRef }
	{

	}
	~SmartPointerOfAnyType()
	{
		delete ptr;
	}

	C* operator->()
	{
		return ptr;
	}
};

void instantiate()
{
	SmartPointerOfAnyType<A> smartPtr{ new A() };
	smartPtr->operation();
	unique_ptr<A> newSmartPtr = make_unique<A>();
	newSmartPtr->operation();
}

int main()
{
	instantiate();
	return 0;
}