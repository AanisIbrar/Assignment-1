#include<iostream>
using namespace std;
template <typename T>
class Abstract
{
public:
	virtual void push(T value) = 0;
	virtual void pop() = 0;
	virtual T top() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;

};
template <typename T>
class Stack :public Abstract<T>
{
private:
	T* arr;
	int topIndex;
	int size;
public:
	Stack(int s)
	{
		size = s;
		arr = new T[size];
		topIndex = -1;

	}
	bool isFull()
	{
		return topIndex == size - 1;
	}
	bool isEmpty()
	{
		return topIndex == -1;
	}
	void push(T value)
	{
		if (isFull())
		{
			cout << "Stack is already full" << endl;
		}
		else
		{
			topIndex++;
			arr[topIndex] = value;

		}
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is already empty" << endl;
		}
		else
		{
			topIndex--;

		}
	}
	T top()
	{
		return arr[topIndex];

	}
	~Stack()
	{
		delete[]arr;
	}
};
int main()
{
	int arr[] = { 4,8,1,3,9,2,10,6,5,7 };
	int size = 10;
	int NGE[10];
	Stack<int> st(20);

	for (int i =size-1;i>=0;i--)
	{
		while (!st.isEmpty() && st.top() <= arr[i])
		{
			st.pop();

	   }
		if (st.isEmpty())
		{
			NGE[i] = -1;
		}
		else
		{
			NGE[i] = st.top();
		}
		st.push(arr[i]);

	}
	cout << "Next Greater Elements :" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << NGE[i] << "\t";
	}
	return 0;
}